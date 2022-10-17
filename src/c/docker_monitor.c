// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause
/* Copyright (c) 2020 Facebook */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <bpf/libbpf.h>
#include <signal.h>
#include <argp.h>



#include "docker_monitor.skel.h"

static int libbpf_print_fn(enum libbpf_print_level level, const char *format, va_list args)
{
	return vfprintf(stderr, format, args);
}

static struct docker_monitor_bpf *skel;

static int handle_event(void *ctx, void *data, size_t data_sz)
{
    FILE * fp;
    char buffer[8192];
    size_t e = *((size_t *)data);
    bool tag = false;
    switch (e) {
    case 0:
        printf("%-15s\t", "run");
        break;
    case 1:
        printf("%-15s\t", "create");
        break;
    default:
        return -1;
    }
    fp = popen("docker ps -ls","r");
    while (fgets(buffer, sizeof(buffer), fp)) {
        if (tag) break;
        tag = true;
    }
    printf("%s", buffer);
    pclose(fp);
    // system("docker ps -ls");
	return 0;
}

static volatile bool exiting = false;

static void sig_handler(int sig)
{
	exiting = true;
}

int main(int argc, char **argv)
{
	struct ring_buffer *rb = NULL;
	int err;

	libbpf_set_strict_mode(LIBBPF_STRICT_ALL);
	/* Set up libbpf errors and debug info callback */
	libbpf_set_print(libbpf_print_fn);

	/* Open BPF application */
	skel = docker_monitor_bpf__open();
	if (!skel) {
		fprintf(stderr, "Failed to open BPF skeleton\n");
		return 1;
	}

	/* Cleaner handling of Ctrl-C */
	signal(SIGINT, sig_handler);
	signal(SIGTERM, sig_handler);

	/* Load & verify BPF programs */
	err = docker_monitor_bpf__load(skel);
	if (err) {
		fprintf(stderr, "Failed to load and verify BPF skeleton\n");
		goto cleanup;
	}

	/* Set up ring buffer polling */
	rb = ring_buffer__new(bpf_map__fd(skel->maps.rb), handle_event, NULL, NULL);
	if (!rb) {
		err = -1;
		fprintf(stderr, "Failed to create ring buffer\n");
		goto cleanup;
	}

	/* Attach tracepoint handler */
	err = docker_monitor_bpf__attach(skel);
	if (err) {
		fprintf(stderr, "Failed to attach BPF skeleton\n");
		goto cleanup;
	}

	printf("Successfully started! Please run `sudo cat /sys/kernel/debug/tracing/trace_pipe` "
		"to see output of the BPF programs.\n");

	printf("Press Ctrl-C to stop.\n");

    printf("%-15s\tCONTAINER ID   IMAGE     COMMAND     CREATED        STATUS    PORTS     NAMES         SIZE\n", "DOCKER_COMMAND");

	/* Process events */
	while (!exiting) {
		err = ring_buffer__poll(rb, 100 /* timeout, ms */);
		/* Ctrl-C will cause -EINTR */
		if (err == -EINTR) {
			err = 0;
			break;
		}
		if (err < 0) {
			fprintf(stderr, "Error polling perf buffer: %d\n", err);
			break;
		}
		sleep(1);
	}

cleanup:
	ring_buffer__free(rb);
	docker_monitor_bpf__destroy(skel);
	return -err;
}

