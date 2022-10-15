/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */
/* Copyright (c) 2020 Facebook */
#ifndef __BOOTSTRAP_H
#define __BOOTSTRAP_H




#define TASK_COMM_LEN 16
#define MAX_FILENAME_LEN 127
#define OPEN_TYPE 1
#define CLOCK_TYPE 2
#define CONNECT_TYPE 3
typedef struct args_t {
	const char *fname;
}Args_t;



struct event {
	int pid;
	int ppid;
	unsigned type;
	__u64 pid_ns;
	char comm[TASK_COMM_LEN];
	char filename[MAX_FILENAME_LEN];
	union {
		__u32 saddr_v4;
		__u8 saddr_v6[16];
	};
	union {
		__u32 daddr_v4;
		__u8 daddr_v6[16];
	};
	__u32 af;
};

#endif /* __BOOTSTRAP_H */
