# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/nick/Halide

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/Halide/build

# Utility rule file for Halide_autogen_timestamp_deps.

# Include any custom commands dependencies for this target.
include CMakeFiles/Halide_autogen_timestamp_deps.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Halide_autogen_timestamp_deps.dir/progress.make

Halide_autogen_timestamp_deps: CMakeFiles/Halide_autogen_timestamp_deps.dir/build.make
.PHONY : Halide_autogen_timestamp_deps

# Rule to build all files generated by this target.
CMakeFiles/Halide_autogen_timestamp_deps.dir/build: Halide_autogen_timestamp_deps
.PHONY : CMakeFiles/Halide_autogen_timestamp_deps.dir/build

CMakeFiles/Halide_autogen_timestamp_deps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Halide_autogen_timestamp_deps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Halide_autogen_timestamp_deps.dir/clean

CMakeFiles/Halide_autogen_timestamp_deps.dir/depend:
	cd /home/nick/Halide/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/Halide /home/nick/Halide /home/nick/Halide/build /home/nick/Halide/build /home/nick/Halide/build/CMakeFiles/Halide_autogen_timestamp_deps.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Halide_autogen_timestamp_deps.dir/depend

