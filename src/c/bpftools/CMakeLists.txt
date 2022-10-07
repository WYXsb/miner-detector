# SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(bpftool)

include_directories(../../../build/libbpf)

add_library(bpftool STATIC btf_helpers.c trace_helpers.c uprobe_helpers.c)