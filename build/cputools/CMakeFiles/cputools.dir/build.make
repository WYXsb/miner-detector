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
include cputools/CMakeFiles/cputools.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include cputools/CMakeFiles/cputools.dir/compiler_depend.make

# Include the progress variables for this target.
include cputools/CMakeFiles/cputools.dir/progress.make

# Include the compile flags for this target's objects.
include cputools/CMakeFiles/cputools.dir/flags.make

cputools/CMakeFiles/cputools.dir/cpuusage.c.o: cputools/CMakeFiles/cputools.dir/flags.make
cputools/CMakeFiles/cputools.dir/cpuusage.c.o: /home/sp0002/workspace-wyx/miner-detector/src/c/cputools/cpuusage.c
cputools/CMakeFiles/cputools.dir/cpuusage.c.o: cputools/CMakeFiles/cputools.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sp0002/workspace-wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object cputools/CMakeFiles/cputools.dir/cpuusage.c.o"
	cd /home/sp0002/workspace-wyx/miner-detector/build/cputools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT cputools/CMakeFiles/cputools.dir/cpuusage.c.o -MF CMakeFiles/cputools.dir/cpuusage.c.o.d -o CMakeFiles/cputools.dir/cpuusage.c.o -c /home/sp0002/workspace-wyx/miner-detector/src/c/cputools/cpuusage.c

cputools/CMakeFiles/cputools.dir/cpuusage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cputools.dir/cpuusage.c.i"
	cd /home/sp0002/workspace-wyx/miner-detector/build/cputools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sp0002/workspace-wyx/miner-detector/src/c/cputools/cpuusage.c > CMakeFiles/cputools.dir/cpuusage.c.i

cputools/CMakeFiles/cputools.dir/cpuusage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cputools.dir/cpuusage.c.s"
	cd /home/sp0002/workspace-wyx/miner-detector/build/cputools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sp0002/workspace-wyx/miner-detector/src/c/cputools/cpuusage.c -o CMakeFiles/cputools.dir/cpuusage.c.s

cputools/CMakeFiles/cputools.dir/memusage.c.o: cputools/CMakeFiles/cputools.dir/flags.make
cputools/CMakeFiles/cputools.dir/memusage.c.o: /home/sp0002/workspace-wyx/miner-detector/src/c/cputools/memusage.c
cputools/CMakeFiles/cputools.dir/memusage.c.o: cputools/CMakeFiles/cputools.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sp0002/workspace-wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object cputools/CMakeFiles/cputools.dir/memusage.c.o"
	cd /home/sp0002/workspace-wyx/miner-detector/build/cputools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT cputools/CMakeFiles/cputools.dir/memusage.c.o -MF CMakeFiles/cputools.dir/memusage.c.o.d -o CMakeFiles/cputools.dir/memusage.c.o -c /home/sp0002/workspace-wyx/miner-detector/src/c/cputools/memusage.c

cputools/CMakeFiles/cputools.dir/memusage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cputools.dir/memusage.c.i"
	cd /home/sp0002/workspace-wyx/miner-detector/build/cputools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sp0002/workspace-wyx/miner-detector/src/c/cputools/memusage.c > CMakeFiles/cputools.dir/memusage.c.i

cputools/CMakeFiles/cputools.dir/memusage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cputools.dir/memusage.c.s"
	cd /home/sp0002/workspace-wyx/miner-detector/build/cputools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sp0002/workspace-wyx/miner-detector/src/c/cputools/memusage.c -o CMakeFiles/cputools.dir/memusage.c.s

# Object files for target cputools
cputools_OBJECTS = \
"CMakeFiles/cputools.dir/cpuusage.c.o" \
"CMakeFiles/cputools.dir/memusage.c.o"

# External object files for target cputools
cputools_EXTERNAL_OBJECTS =

cputools/libcputools.a: cputools/CMakeFiles/cputools.dir/cpuusage.c.o
cputools/libcputools.a: cputools/CMakeFiles/cputools.dir/memusage.c.o
cputools/libcputools.a: cputools/CMakeFiles/cputools.dir/build.make
cputools/libcputools.a: cputools/CMakeFiles/cputools.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sp0002/workspace-wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libcputools.a"
	cd /home/sp0002/workspace-wyx/miner-detector/build/cputools && $(CMAKE_COMMAND) -P CMakeFiles/cputools.dir/cmake_clean_target.cmake
	cd /home/sp0002/workspace-wyx/miner-detector/build/cputools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cputools.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cputools/CMakeFiles/cputools.dir/build: cputools/libcputools.a
.PHONY : cputools/CMakeFiles/cputools.dir/build

cputools/CMakeFiles/cputools.dir/clean:
	cd /home/sp0002/workspace-wyx/miner-detector/build/cputools && $(CMAKE_COMMAND) -P CMakeFiles/cputools.dir/cmake_clean.cmake
.PHONY : cputools/CMakeFiles/cputools.dir/clean

cputools/CMakeFiles/cputools.dir/depend:
	cd /home/sp0002/workspace-wyx/miner-detector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sp0002/workspace-wyx/miner-detector/src/c /home/sp0002/workspace-wyx/miner-detector/src/c/cputools /home/sp0002/workspace-wyx/miner-detector/build /home/sp0002/workspace-wyx/miner-detector/build/cputools /home/sp0002/workspace-wyx/miner-detector/build/cputools/CMakeFiles/cputools.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : cputools/CMakeFiles/cputools.dir/depend

