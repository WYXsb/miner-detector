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
CMAKE_SOURCE_DIR = /home/wyx/miner-detector/src/c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wyx/miner-detector/build

# Include any dependencies generated for this target.
include CMakeFiles/fentry.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fentry.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fentry.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fentry.dir/flags.make

fentry.skel.h: fentry.bpf.o
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[skel]  Building BPF skeleton: fentry"
	bash -c "/home/wyx/miner-detector/src/c/../../tools/bpftool gen skeleton /home/wyx/miner-detector/build/fentry.bpf.o > /home/wyx/miner-detector/build/fentry.skel.h"

fentry.bpf.o: /home/wyx/miner-detector/src/c/fentry.bpf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[clang] Building BPF object: fentry"
	/usr/bin/clang -g -O2 -target bpf -D__TARGET_ARCH_x86 "-idirafter /usr/lib/llvm-14/lib/clang/14.0.0/include -idirafter /usr/local/include -idirafter /usr/include/x86_64-linux-gnu -idirafter /usr/include" -I/home/wyx/miner-detector/src/c/../../vmlinux -isystem /home/wyx/miner-detector/build/libbpf -c /home/wyx/miner-detector/src/c/fentry.bpf.c -o /home/wyx/miner-detector/build/fentry.bpf.o

CMakeFiles/fentry.dir/fentry.c.o: CMakeFiles/fentry.dir/flags.make
CMakeFiles/fentry.dir/fentry.c.o: /home/wyx/miner-detector/src/c/fentry.c
CMakeFiles/fentry.dir/fentry.c.o: CMakeFiles/fentry.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/fentry.dir/fentry.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/fentry.dir/fentry.c.o -MF CMakeFiles/fentry.dir/fentry.c.o.d -o CMakeFiles/fentry.dir/fentry.c.o -c /home/wyx/miner-detector/src/c/fentry.c

CMakeFiles/fentry.dir/fentry.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fentry.dir/fentry.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wyx/miner-detector/src/c/fentry.c > CMakeFiles/fentry.dir/fentry.c.i

CMakeFiles/fentry.dir/fentry.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fentry.dir/fentry.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wyx/miner-detector/src/c/fentry.c -o CMakeFiles/fentry.dir/fentry.c.s

# Object files for target fentry
fentry_OBJECTS = \
"CMakeFiles/fentry.dir/fentry.c.o"

# External object files for target fentry
fentry_EXTERNAL_OBJECTS =

fentry: CMakeFiles/fentry.dir/fentry.c.o
fentry: CMakeFiles/fentry.dir/build.make
fentry: bpftools/libbpftool.a
fentry: libbpf/libbpf.a
fentry: CMakeFiles/fentry.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable fentry"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fentry.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fentry.dir/build: fentry
.PHONY : CMakeFiles/fentry.dir/build

CMakeFiles/fentry.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fentry.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fentry.dir/clean

CMakeFiles/fentry.dir/depend: fentry.bpf.o
CMakeFiles/fentry.dir/depend: fentry.skel.h
	cd /home/wyx/miner-detector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wyx/miner-detector/src/c /home/wyx/miner-detector/src/c /home/wyx/miner-detector/build /home/wyx/miner-detector/build /home/wyx/miner-detector/build/CMakeFiles/fentry.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fentry.dir/depend

