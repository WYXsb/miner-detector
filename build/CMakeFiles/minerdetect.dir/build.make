# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sp0002/workspace-wyx/miner-detector/src/c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sp0002/workspace-wyx/miner-detector/build

# Include any dependencies generated for this target.
include CMakeFiles/minerdetect.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/minerdetect.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/minerdetect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minerdetect.dir/flags.make

minerdetect.skel.h: minerdetect.bpf.o
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sp0002/workspace-wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[skel]  Building BPF skeleton: minerdetect"
	bash -c "/home/sp0002/workspace-wyx/miner-detector/src/c/../../tools/bpftool gen skeleton /home/sp0002/workspace-wyx/miner-detector/build/minerdetect.bpf.o > /home/sp0002/workspace-wyx/miner-detector/build/minerdetect.skel.h"

minerdetect.bpf.o: /home/sp0002/workspace-wyx/miner-detector/src/c/minerdetect.bpf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sp0002/workspace-wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[clang] Building BPF object: minerdetect"
	/usr/bin/clang -g -O2 -target bpf -D__TARGET_ARCH_x86 "-idirafter /usr/lib/llvm-14/lib/clang/14.0.0/include -idirafter /usr/local/include -idirafter /usr/include/x86_64-linux-gnu -idirafter /usr/include" -I/home/sp0002/workspace-wyx/miner-detector/src/c/../../vmlinux -isystem /home/sp0002/workspace-wyx/miner-detector/build/libbpf -c /home/sp0002/workspace-wyx/miner-detector/src/c/minerdetect.bpf.c -o /home/sp0002/workspace-wyx/miner-detector/build/minerdetect.bpf.o

CMakeFiles/minerdetect.dir/minerdetect.c.o: CMakeFiles/minerdetect.dir/flags.make
CMakeFiles/minerdetect.dir/minerdetect.c.o: /home/sp0002/workspace-wyx/miner-detector/src/c/minerdetect.c
CMakeFiles/minerdetect.dir/minerdetect.c.o: CMakeFiles/minerdetect.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sp0002/workspace-wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/minerdetect.dir/minerdetect.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/minerdetect.dir/minerdetect.c.o -MF CMakeFiles/minerdetect.dir/minerdetect.c.o.d -o CMakeFiles/minerdetect.dir/minerdetect.c.o -c /home/sp0002/workspace-wyx/miner-detector/src/c/minerdetect.c

CMakeFiles/minerdetect.dir/minerdetect.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minerdetect.dir/minerdetect.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sp0002/workspace-wyx/miner-detector/src/c/minerdetect.c > CMakeFiles/minerdetect.dir/minerdetect.c.i

CMakeFiles/minerdetect.dir/minerdetect.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minerdetect.dir/minerdetect.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sp0002/workspace-wyx/miner-detector/src/c/minerdetect.c -o CMakeFiles/minerdetect.dir/minerdetect.c.s

# Object files for target minerdetect
minerdetect_OBJECTS = \
"CMakeFiles/minerdetect.dir/minerdetect.c.o"

# External object files for target minerdetect
minerdetect_EXTERNAL_OBJECTS =

minerdetect: CMakeFiles/minerdetect.dir/minerdetect.c.o
minerdetect: CMakeFiles/minerdetect.dir/build.make
minerdetect: bpftools/libbpftool.a
minerdetect: cputools/libcputools.a
minerdetect: openssltools/libopenssltools.so
minerdetect: /usr/lib/x86_64-linux-gnu/libssl.so
minerdetect: /usr/lib/x86_64-linux-gnu/libcrypto.so
minerdetect: libbpf/libbpf.a
minerdetect: CMakeFiles/minerdetect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sp0002/workspace-wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable minerdetect"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minerdetect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minerdetect.dir/build: minerdetect
.PHONY : CMakeFiles/minerdetect.dir/build

CMakeFiles/minerdetect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minerdetect.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minerdetect.dir/clean

CMakeFiles/minerdetect.dir/depend: minerdetect.bpf.o
CMakeFiles/minerdetect.dir/depend: minerdetect.skel.h
	cd /home/sp0002/workspace-wyx/miner-detector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sp0002/workspace-wyx/miner-detector/src/c /home/sp0002/workspace-wyx/miner-detector/src/c /home/sp0002/workspace-wyx/miner-detector/build /home/sp0002/workspace-wyx/miner-detector/build /home/sp0002/workspace-wyx/miner-detector/build/CMakeFiles/minerdetect.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minerdetect.dir/depend

