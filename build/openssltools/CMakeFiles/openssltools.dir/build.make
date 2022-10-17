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
include openssltools/CMakeFiles/openssltools.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include openssltools/CMakeFiles/openssltools.dir/compiler_depend.make

# Include the progress variables for this target.
include openssltools/CMakeFiles/openssltools.dir/progress.make

# Include the compile flags for this target's objects.
include openssltools/CMakeFiles/openssltools.dir/flags.make

openssltools/CMakeFiles/openssltools.dir/sha256test.c.o: openssltools/CMakeFiles/openssltools.dir/flags.make
openssltools/CMakeFiles/openssltools.dir/sha256test.c.o: /home/wyx/miner-detector/src/c/openssltools/sha256test.c
openssltools/CMakeFiles/openssltools.dir/sha256test.c.o: openssltools/CMakeFiles/openssltools.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object openssltools/CMakeFiles/openssltools.dir/sha256test.c.o"
	cd /home/wyx/miner-detector/build/openssltools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT openssltools/CMakeFiles/openssltools.dir/sha256test.c.o -MF CMakeFiles/openssltools.dir/sha256test.c.o.d -o CMakeFiles/openssltools.dir/sha256test.c.o -c /home/wyx/miner-detector/src/c/openssltools/sha256test.c

openssltools/CMakeFiles/openssltools.dir/sha256test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/openssltools.dir/sha256test.c.i"
	cd /home/wyx/miner-detector/build/openssltools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/wyx/miner-detector/src/c/openssltools/sha256test.c > CMakeFiles/openssltools.dir/sha256test.c.i

openssltools/CMakeFiles/openssltools.dir/sha256test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/openssltools.dir/sha256test.c.s"
	cd /home/wyx/miner-detector/build/openssltools && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/wyx/miner-detector/src/c/openssltools/sha256test.c -o CMakeFiles/openssltools.dir/sha256test.c.s

# Object files for target openssltools
openssltools_OBJECTS = \
"CMakeFiles/openssltools.dir/sha256test.c.o"

# External object files for target openssltools
openssltools_EXTERNAL_OBJECTS =

openssltools/libopenssltools.so: openssltools/CMakeFiles/openssltools.dir/sha256test.c.o
openssltools/libopenssltools.so: openssltools/CMakeFiles/openssltools.dir/build.make
openssltools/libopenssltools.so: openssltools/CMakeFiles/openssltools.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wyx/miner-detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libopenssltools.so"
	cd /home/wyx/miner-detector/build/openssltools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/openssltools.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
openssltools/CMakeFiles/openssltools.dir/build: openssltools/libopenssltools.so
.PHONY : openssltools/CMakeFiles/openssltools.dir/build

openssltools/CMakeFiles/openssltools.dir/clean:
	cd /home/wyx/miner-detector/build/openssltools && $(CMAKE_COMMAND) -P CMakeFiles/openssltools.dir/cmake_clean.cmake
.PHONY : openssltools/CMakeFiles/openssltools.dir/clean

openssltools/CMakeFiles/openssltools.dir/depend:
	cd /home/wyx/miner-detector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wyx/miner-detector/src/c /home/wyx/miner-detector/src/c/openssltools /home/wyx/miner-detector/build /home/wyx/miner-detector/build/openssltools /home/wyx/miner-detector/build/openssltools/CMakeFiles/openssltools.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : openssltools/CMakeFiles/openssltools.dir/depend

