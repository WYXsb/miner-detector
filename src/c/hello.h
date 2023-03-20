/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */
/* Copyright (c) 2020 Facebook */
#ifndef __HELLO_H
#define __HELLO_H

#define TASK_COMM_LEN 16
#define MAX_FILENAME_LEN 32

struct event {
	int pid;
	int ppid;
	unsigned exit_code;
	unsigned long long duration_ns;
	char comm[TASK_COMM_LEN];
	char filename[MAX_FILENAME_LEN];
	bool exit_event;
};
typedef struct args_t {
	const char *fname;
	void * userstr;
	size_t len;
}Args_t;

#endif /* __BOOTSTRAP_H */
