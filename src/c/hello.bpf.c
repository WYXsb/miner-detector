// SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause
/* Copyright (c) 2020 Facebook */
#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include <bpf/bpf_core_read.h>
#include "hello.h"

char LICENSE[] SEC("license") = "Dual BSD/GPL";

struct {
	__uint(type, BPF_MAP_TYPE_HASH);
	__uint(max_entries, 2048);
	__type(key, pid_t);
	__type(value, u64);
} fd_map SEC(".maps");

struct {
	__uint(type, BPF_MAP_TYPE_HASH);
	__uint(max_entries, 2048);
	__type(key, pid_t);
	__type(value, Args_t);
} open_map SEC(".maps");

struct {
	__uint(type, BPF_MAP_TYPE_RINGBUF);
	__uint(max_entries, 256 * 1024);
} rb SEC(".maps");


const volatile int target_file_len = 0;
const volatile int target_string_len = 0;
const volatile char target_file[MAX_FILENAME_LEN] = {0};
const volatile char new_buff_addr[TASK_COMM_LEN] = {0};
const volatile char target_comm[TASK_COMM_LEN] = {0};

SEC("tracepoint/syscalls/sys_enter_openat")
int trace_open_enter(struct trace_event_raw_sys_enter* ctx)
{
	struct args_t args = {0};
	pid_t pid;
	int ret;
	pid = bpf_get_current_pid_tgid() >> 32;
	char comm[TASK_COMM_LEN] = {0};
	char filename[MAX_FILENAME_LEN] ={0};
    bpf_get_current_comm(&comm, TASK_COMM_LEN);
        
	//filename = (const char *)ctx->args[1];
	
	bpf_probe_read_user(&filename,MAX_FILENAME_LEN,(char *)ctx->args[1]);
	
	for(int i = 0 ;i < TASK_COMM_LEN; i++)
	{
		if(comm[i] == target_comm[i])
		{
			if(comm[i] == 0)
			{
				break;
			}
		}
		else 
		{
			return 0;
		}
	}
	bpf_printk(" pid:%d open %s targetcomm:%s// comm:%s//",pid,filename,target_comm,comm);
	if(target_file_len > MAX_FILENAME_LEN)
		return 0;
	for(int i = 0 ; i < MAX_FILENAME_LEN; i++)
	{
		if(filename[i] == target_file[i])
		{
			if(filename[i] == 0)
			{
				break;
			}
			//bpf_printk("same:%d",filename[i]);
		}else {
			//bpf_printk("end :%d",i);
			return 0;
		}
	}
	
	//bpf_printk(" pid:%d open %s ",pid,filename);
	unsigned int zero = 0;
	bpf_map_update_elem(&fd_map, &pid, &zero, BPF_ANY);
end:
	return 0;
}

SEC("tracepoint/syscalls/sys_exit_openat")
int trace_open_exit(struct trace_event_raw_sys_exit* ctx)
{
	struct args_t args = {0};
	pid_t pid;
	pid = bpf_get_current_pid_tgid() >> 32;
	unsigned int *check = bpf_map_lookup_elem(&fd_map,&pid);
	if(check == 0)
		return 0;
	unsigned int fd = (unsigned int)ctx->ret;
	bpf_map_update_elem(&fd_map, &pid, &fd, BPF_ANY);
	//bpf_printk(" pid:%d open %d ",pid,fd);
	return 0;
	
}


SEC("tracepoint/syscalls/sys_enter_read")
int handle_read_enter(struct trace_event_raw_sys_enter *ctx)
{
    size_t pid_tgid = bpf_get_current_pid_tgid();
	pid_t pid;
	pid = bpf_get_current_pid_tgid() >> 32;
	char comm[TASK_COMM_LEN] = {0};
	bpf_get_current_comm(&comm, TASK_COMM_LEN);

    unsigned int *pfd = (unsigned int *) bpf_map_lookup_elem(&fd_map, &pid_tgid);
    if (pfd == 0) return 0;

    unsigned int map_fd = *pfd;
    unsigned int fd = (unsigned int)ctx->args[0];
    if (map_fd != fd) return 0;

    long unsigned int buff_addr = ctx->args[1];
    size_t size = ctx->args[2];
    Args_t data = {0};
    data.userstr = (void *)buff_addr;
    data.len = size;
	bpf_printk(" read_enter %d %s %s ",pid,comm,data.userstr);

    bpf_map_update_elem(&open_map, &pid, &data, BPF_ANY);
	bpf_printk(" readok %d ",fd);
    return 0;
}
SEC("tracepoint/syscalls/sys_exit_read")
int handle_read_exit(struct trace_event_raw_sys_exit *ctx)
{
	pid_t pid;
	pid = bpf_get_current_pid_tgid() >> 32;
    unsigned int ret = (unsigned int)ctx->ret;
	void * addr;
	char comm[TASK_COMM_LEN];
	bpf_get_current_comm(&comm, TASK_COMM_LEN);

    Args_t *payload = bpf_map_lookup_elem(&open_map, &pid);
	if(payload == NULL)
		return 0;
	if(ret <= 0)
	{
		return 0;
	}
	ret = payload->len > ret ? ret : payload->len;
	if(ret < 0)
		return 0;
    //long unsigned int new_buff_addr = buff_addr + read_size - MAX_PAYLOAD_LEN;
	
	if(target_file_len < 0)
		return 0;
	bpf_probe_write_user(payload->userstr, new_buff_addr,target_string_len); 
	bpf_printk(" read_exit %d %s %x ",pid,comm,payload->userstr);
    bpf_map_delete_elem(&fd_map, &pid);
    bpf_map_delete_elem(&open_map, &pid);
    return 0;
}