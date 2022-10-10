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
	__uint(max_entries, 8192);
	__type(key, pid_t);
	__type(value, u64);
} exec_start SEC(".maps");

struct {
	__uint(type, BPF_MAP_TYPE_RINGBUF);
	__uint(max_entries, 256 * 1024);
} rb SEC(".maps");

const volatile unsigned long long min_duration_ns = 0;

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

SEC("tracepoint/syscalls/sys_enter_clock_gettime")
int tracepoint__syscalls__sys_enter_clock_gettime(struct trace_event_raw_sys_exit* ctx)
{
	struct task_struct *task;
	struct event *e;
	pid_t pid, tid;
	char comm[TASK_COMM_LEN];
	u64 id, ts, *start_ts, duration_ns = 0;

	
	id = bpf_get_current_pid_tgid();
	pid = id >> 32;
	tid = (u32)id;
	bpf_get_current_comm(comm, sizeof(comm));
	if(!__commcmp(comm,"bootstrap"))
		return 0;
	
	/* reserve sample from BPF ringbuf */
	e = bpf_ringbuf_reserve(&rb, sizeof(*e), 0);
	if (!e)
		return 0;

	/* fill out the sample with data */
	task = (struct task_struct *)bpf_get_current_task();

	e->pid = pid;
	e->ppid = BPF_CORE_READ(task, real_parent, tgid);
	bpf_get_current_comm(&e->comm, sizeof(e->comm));
	

	/* send data to user-space for post-processing */
	bpf_ringbuf_submit(e,0); 
	return 0;

}




// SEC("tracepoint/syscalls/sys_enter_openat")
// int tracepoint__syscalls__sys_enter_openat(struct trace_event_raw_sys_exit* ctx)
// {
// 	struct task_struct *task;
// 	struct event *e;
// 	pid_t pid, tid;
// 	char comm[TASK_COMM_LEN];
// 	u64 id, ts, *start_ts, duration_ns = 0;

	
// 	id = bpf_get_current_pid_tgid();
// 	pid = id >> 32;
// 	tid = (u32)id;
// 	bpf_get_current_comm(comm, sizeof(comm));
// 	if(!__commcmp(comm,"bootstrap"))
// 		return 0;
	
// 	/* reserve sample from BPF ringbuf */
// 	e = bpf_ringbuf_reserve(&rb, sizeof(*e), 0);
// 	if (!e)
// 		return 0;

// 	/* fill out the sample with data */
// 	task = (struct task_struct *)bpf_get_current_task();

// 	e->pid = pid;
// 	e->ppid = BPF_CORE_READ(task, real_parent, tgid);
// 	bpf_get_current_comm(&e->comm, sizeof(e->comm));
	

// 	/* send data to user-space for post-processing */
// 	bpf_ringbuf_submit(e,0); 
// 	return 0;

// }
