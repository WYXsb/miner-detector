cmake_minimum_required(VERSION 3.16)
project(openssltools)

add_link_options(-lssl -lcrypto)


add_library(openssltools SHARED sha256test.c /usr/lib/x86_64-linux-gnu/libssl.so /usr/lib/x86_64-linux-gnu/libcrypto.so)
