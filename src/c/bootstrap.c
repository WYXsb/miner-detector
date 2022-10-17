// SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause)
/* Copyright (c) 2020 Facebook */
#include <argp.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/resource.h>
#include <bpf/libbpf.h>
#include "bootstrap.h"
#include "bootstrap.skel.h"

#include "cpuusage.h"
#include "memusage.h"
#include "sha256.h"

#define MAX_PROC_PIDNS 64

static struct env
{
	bool verbose;
	long min_duration_ms;
} env;

unsigned long host_pidns;

const char *argp_program_version = "bootstrap 0.0";
const char *argp_program_bug_address = "<bpf@vger.kernel.org>";
const char argp_program_doc[] =
	"BPF bootstrap demo application.\n"
	"\n"
	"It traces process start and exits and shows associated \n"
	"information (filename, process duration, PID and PPID, etc).\n"
	"\n"
	"USAGE: ./bootstrap [-d <min-duration-ms>] [-v]\n";

static const struct argp_option opts[] = {
	{"verbose", 'v', NULL, 0, "Verbose debug output"},
	{"duration", 'd', "DURATION-MS", 0, "Minimum process duration (ms) to report"},
	{},
};

static error_t parse_arg(int key, char *arg, struct argp_state *state)
{
	switch (key)
	{
	case 'v':
		env.verbose = true;
		break;
	case 'd':
		errno = 0;
		env.min_duration_ms = strtol(arg, NULL, 10);
		if (errno || env.min_duration_ms <= 0)
		{
			fprintf(stderr, "Invalid duration: %s\n", arg);
			argp_usage(state);
		}
		break;
	case ARGP_KEY_ARG:
		argp_usage(state);
		break;
	default:
		return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

static const struct argp argp = {
	.options = opts,
	.parser = parse_arg,
	.doc = argp_program_doc,
};

static int libbpf_print_fn(enum libbpf_print_level level, const char *format, va_list args)
{
	if (level == LIBBPF_DEBUG && !env.verbose)
		return 0;
	return vfprintf(stderr, format, args);
}

static volatile bool exiting = false;

static void sig_handler(int sig)
{
	exiting = true;
}


void read_pidns(void)
{
	char buf[MAX_PROC_PIDNS]  = {0};  
	char *buf_p				  = buf ; // 作为strsep的第一个参数
	char *strtoul_end_ptr     = NULL;
	// char *strsep_ret 		  = NULL;

	int result = readlink("/proc/self/ns/pid",buf,MAX_PROC_PIDNS-1);
	printf("\n\nfn-[read_pidns] buf : %s  result: %d \n",buf,result);
	// strsep_ret = strsep(&buf_p, "[" );
	strsep(&buf_p, "[" );

	host_pidns = strtoul(buf_p, &strtoul_end_ptr, 10);
	printf("fn-[read_pidns] host_pidns: %ld \n \n",host_pidns);
	return ;
}

int getRootPath(char *rootpath,const char *path,int pid)
{
    char temp[MAX_FILENAME_LEN];
    int pathlen = strlen(path);
    if(pathlen == 0)
    {
        printf("Error in function getRootPath: path str is null \n");
        return -1;
    }

    if(path[0] == '/')
    {
        sprintf(rootpath,"/proc/%d/root%s",pid,path);
    }
    else if (path[0] == '.' && path[1] == '/')
    {
        /* code */
        for(int i = 0; i < pathlen; i++)
        {
            temp[i] = path[i+1];
        }
        sprintf(rootpath,"/proc/%d/cwd%s",pid,temp);
    }
    else{
        sprintf(rootpath,"/proc/%d/cwd/%s",pid,path);
    }
    return 0;
}

static int handle_event(void *ctx, void *data, size_t data_sz)
{
	const struct event *e = data;
	struct tm *tm;
	char ts[32];
	time_t t;
	float cpuusage, memusage;
	char src[32];
	char rootpath[256];

	time(&t);
	tm = localtime(&t);
	strftime(ts, sizeof(ts), "%H:%M:%S", tm);

	/*  */
	if (strstr(e->comm, "kinsing") || strstr(e->comm, "kdevtmpfsi"))
	{
		printf("%-8s %-5s %-16s %-7d \n",
			   ts, "MINER", e->comm, e->pid);
	}

	if (e->type == OPEN_TYPE)
	{
		getRootPath(rootpath,e->filename,(int)e->pid);
		GetSHA256(rootpath,(int)e->pid);
		printf("%-8s %-6s %-16s %-7d %s %lld \n",
			   ts, "OPEN", e->comm, e->pid, rootpath,e->pid_ns);
		
	}
	else if (e->type == CLOCK_TYPE)
	{
		cpuusage = GetProcessCpuUsage(e->pid);

		memusage = GetProcessMemUsage(e->pid);

		// if(cpuusage > 0.95 && memusage > 0.5)
		// {
		// 	printf("%-8s %-6s %-16s %-7d %-7f %-7f\n",
		// 	   ts, "CLOCK", e->comm, e->pid, cpuusage, memusage);
		// }
		printf("%-8s %-6s %-16s %-7d %-7f %-7f\n",
		   ts, "CLOCK", e->comm, e->pid, cpuusage, memusage);
	}
	else{
		inet_ntop(e->af, &e->daddr_v4, src, sizeof(src));
		if(!strcmp(src,"185.154.53.140") || !strcmp(src,"185.156.179.225"))
		printf("%-8s %-6s %-16s %-7d %25s %llu\n",
			   ts, "CONN", e->comm, e->pid, src, e->pid_ns);
	}

	return 0;
}

int main(int argc, char **argv)
{
	struct ring_buffer *rb = NULL;
	struct bootstrap_bpf *skel;
	int err;

	/* Parse command line arguments */
	err = argp_parse(&argp, argc, argv, 0, NULL, NULL);
	if (err)
		return err;

	libbpf_set_strict_mode(LIBBPF_STRICT_ALL);
	/* Set up libbpf errors and debug info callback */
	libbpf_set_print(libbpf_print_fn);

	/* Cleaner handling of Ctrl-C */
	signal(SIGINT, sig_handler);
	signal(SIGTERM, sig_handler);

	read_pidns();

	/* Load and verify BPF application */
	skel = bootstrap_bpf__open();
	if (!skel)
	{
		fprintf(stderr, "Failed to open and load BPF skeleton\n");
		return 1;
	}
	skel->rodata->host_pidns = host_pidns;
	
	/* Load & verify BPF programs */
	err = bootstrap_bpf__load(skel);
	if (err)
	{
		fprintf(stderr, "Failed to load and verify BPF skeleton\n");
		goto cleanup;
	}

	

	/* Attach tracepoints */
	err = bootstrap_bpf__attach(skel);
	if (err)
	{
		fprintf(stderr, "Failed to attach BPF skeleton\n");
		goto cleanup;
	}

	

	/* Set up ring buffer polling */
	rb = ring_buffer__new(bpf_map__fd(skel->maps.rb), handle_event, NULL, NULL);
	if (!rb)
	{
		err = -1;
		fprintf(stderr, "Failed to create ring buffer\n");
		goto cleanup;
	}

	/* Process events */
	printf("%-8s %-5s %-16s %-7s %-7s  %-7s\n",
		   "TIME", "EVENT", "COMM", "PID", "CPUUSAGE", "MEMUSAGE");
	while (!exiting)
	{
		err = ring_buffer__poll(rb, 100 /* timeout, ms */);
		/* Ctrl-C will cause -EINTR */
		if (err == -EINTR)
		{
			err = 0;
			break;
		}
		if (err < 0)
		{
			printf("Error polling perf buffer: %d\n", err);
			break;
		}
	}

cleanup:
	/* Clean up */
	ring_buffer__free(rb);
	bootstrap_bpf__destroy(skel);

	return err < 0 ? -err : 0;
}


