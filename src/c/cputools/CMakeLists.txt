cmake_minimum_required(VERSION 3.16)
project(cputools)

add_library(cputools STATIC cpuusage.c memusage.c)