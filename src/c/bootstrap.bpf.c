// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause
/* Copyright (c) 2020 Facebook */
#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include <bpf/bpf_core_read.h>
#include "bootstrap.h"

char LICENSE[] SEC("license") = "Dual BSD/GPL";

struct {
	__uint(type, BPF_MAP_TYPE_HASH);
	__uint(max_entries, 2048);
	__type(key, pid_t);
	__type(value, Args_t);
} open_map SEC(".maps");

struct {
	__uint(type, BPF_MAP_TYPE_HASH);
	__uint(max_entries, 2048);
	__type(key, pid_t);
	__type(value, struct sock *);
} sockets SEC(".maps");


struct {
	__uint(type, BPF_MAP_TYPE_RINGBUF);
	__uint(max_entries, 256 * 1024);
} rb SEC(".maps");

const volatile unsigned long long host_pidns;
const volatile int filter_ports[MAX_FILENAME_LEN];
const volatile int filter_ports_len = 0;
const volatile bool do_count = 0;
const volatile bool source_port = 0;
#define AF_INET		2


/*
 * 比较传入的两个命令是否相同
 * 相同返回 0，不同返回1
 */
static int __commcmp(char *comm1,char *comm2)
{
	for(int i = 0 ;i < TASK_COMM_LEN; i++)
	{
		if(comm1[i] == comm2[i])
		{
			if(comm1[i] == 0)
			{
				return 0;
			}
		}
		else 
		{
			return 1;
		}
	}
	return 1;
}


static __always_inline
int trace_enter_open(struct trace_event_raw_sys_enter* ctx)
{
	struct args_t args;
	struct task_struct *task;
	pid_t pid;
	__u64 pid_ns;
	pid = bpf_get_current_pid_tgid() >> 32;
	
	args.fname = (const char *)ctx->args[1];
	task = (struct task_struct *)bpf_get_current_task();
	pid_ns =  BPF_CORE_READ(task,nsproxy,pid_ns_for_children,ns.inum);

	if(pid_ns == host_pidns)
	{
		return 0;
	}

	args.fname = (const char *)ctx->args[1];
	bpf_map_update_elem(&open_map, &pid, &args, BPF_ANY);

	return 0;
}

static __always_inline
int trace_exit_open(struct trace_event_raw_sys_exit* ctx)
{
	struct task_struct *task;
	struct event *e;
	pid_t pid, tid;
	struct args_t *args;
	char comm[TASK_COMM_LEN];
	u64 id;
	__u64 pid_ns;

	id = bpf_get_current_pid_tgid();
	pid = id >> 32;

	task = (struct task_struct *)bpf_get_current_task();
	pid_ns =  BPF_CORE_READ(task,nsproxy,pid_ns_for_children,ns.inum);
	if(pid_ns == host_pidns)
	{
		return 0;
	}

	args = (Args_t *)bpf_map_lookup_elem(&open_map, &pid);
	if(args == NULL)
	{
		return 0;
	}

	tid = (u32)id;
	bpf_get_current_comm(comm, sizeof(comm));
	if(!__commcmp(comm,"bootstrap"))
		return 0;
	
	/* reserve sample from BPF ringbuf */
	e = bpf_ringbuf_reserve(&rb, sizeof(*e), 0);
	if (!e)
		return 0;

	/* fill out the sample with data */
	bpf_probe_read_str(e->filename, sizeof(e->filename), (void *)(args->fname));

	e->pid = pid; 
	e->ppid = BPF_CORE_READ(task, real_parent, tgid);
	bpf_get_current_comm(&e->comm, sizeof(e->comm));
	e->type = OPEN_TYPE;
	e->pid_ns = pid_ns;

	/* send data to user-space for post-processing */
	bpf_ringbuf_submit(e,0); 
	return 0;
}

SEC("tracepoint/syscalls/sys_enter_openat")
int tracepoint__syscalls__sys_enter_openat(struct trace_event_raw_sys_enter* ctx)
{
	return trace_enter_open(ctx);
}

SEC("tracepoint/syscalls/sys_enter_openat2")
int tracepoint__syscalls__sys_enter_openat2(struct trace_event_raw_sys_enter* ctx)
{
	return trace_enter_open(ctx);
}

SEC("tracepoint/syscalls/sys_exit_openat")
int tracepoint__syscalls__sys_exit_openat(struct trace_event_raw_sys_exit* ctx)
{
	return trace_exit_open(ctx);
}

SEC("tracepoint/syscalls/sys_exit_openat2")
int tracepoint__syscalls__sys_exit_openat2(struct trace_event_raw_sys_exit* ctx)
{
	return trace_exit_open(ctx);
}


SEC("tracepoint/syscalls/sys_enter_clock_gettime")
int tracepoint__syscalls__sys_enter_clock_gettime(struct trace_event_raw_sys_exit* ctx)
{
	struct task_struct *task;
	struct event *e;
	pid_t pid, tid;
	char comm[TASK_COMM_LEN];
	u64 id, ts, *start_ts, duration_ns = 0;
	u64 pid_ns;
	
	id = bpf_get_current_pid_tgid();
	pid = id >> 32;
	tid = (u32)id;

	task = (struct task_struct *)bpf_get_current_task();
	pid_ns =  BPF_CORE_READ(task,nsproxy,pid_ns_for_children,ns.inum);
	if(pid_ns == host_pidns)
	{
		return 0;
	} 

	bpf_get_current_comm(comm, sizeof(comm));
	if(!__commcmp(comm,"bootstrap"))
		return 0;
	
	/* reserve sample from BPF ringbuf */
	e = bpf_ringbuf_reserve(&rb, sizeof(*e), 0);
	if (!e)
		return 0;

	/* fill out the sample with data */

	e->pid = pid;
	e->ppid = BPF_CORE_READ(task, real_parent, tgid);
	bpf_get_current_comm(&e->comm, sizeof(e->comm));
	e->type = CLOCK_TYPE;

	/* send data to user-space for post-processing */
	bpf_ringbuf_submit(e,0); 
	return 0;

}


static __always_inline int
enter_tcp_connect(struct pt_regs *ctx, struct sock *sk)
{
	__u64 pid_tgid = bpf_get_current_pid_tgid();
	pid_t pid = pid_tgid >> 32;


	bpf_map_update_elem(&sockets, &pid, &sk, 0);
	return 0;
}

static __always_inline int
trace_v4(struct pt_regs *ctx, pid_t pid, struct sock *sk, __u16 sport, __u16 dport)
{
	struct event *e;
	struct task_struct *task;
	e = bpf_ringbuf_reserve(&rb, sizeof(*e), 0);
	if (!e)
		return 0;
	task = (struct task_struct *)bpf_get_current_task();
	e->pid_ns =  BPF_CORE_READ(task,nsproxy,pid_ns_for_children,ns.inum);
	e->type = CONNECT_TYPE;
	e->af = AF_INET;
	e->pid = pid; 
	BPF_CORE_READ_INTO(&e->saddr_v4, sk, __sk_common.skc_rcv_saddr);
	BPF_CORE_READ_INTO(&e->daddr_v4, sk, __sk_common.skc_daddr);
	bpf_get_current_comm(e->comm, sizeof(e->comm));

	bpf_ringbuf_submit(e,0); 
	return 0;
}

static __always_inline int
exit_tcp_connect(struct pt_regs *ctx, int ret, int ip_ver)
{
	__u64 pid_tgid = bpf_get_current_pid_tgid();
	__u32 pid = pid_tgid >> 32;
	__u32 tid = pid_tgid;
	struct sock **skpp;
	struct sock *sk;
	__u16 sport = 0;
	__u16 dport;

	skpp = bpf_map_lookup_elem(&sockets, &pid);
	if (!skpp)
		return 0;

	if (ret)
		goto end;

	sk = *skpp;

	if (source_port)
		BPF_CORE_READ_INTO(&sport, sk, __sk_common.skc_num);
	BPF_CORE_READ_INTO(&dport, sk, __sk_common.skc_dport);


	if (ip_ver == 4)
		trace_v4(ctx, pid, sk, sport, dport);

end:
	bpf_map_delete_elem(&sockets, &pid);
	return 0;
}





SEC("kprobe/tcp_v4_connect")
int BPF_KPROBE(tcp_v4_connect, struct sock *sk)
{
	return enter_tcp_connect(ctx, sk);
}

SEC("kretprobe/tcp_v4_connect")
int BPF_KRETPROBE(tcp_v4_connect_ret, int ret)
{
	return exit_tcp_connect(ctx, ret, 4);
}
