# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jon/Code/src/misc-code/key_logger

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jon/Code/src/misc-code/build-key_logger-Desktop-Default

# Include any dependencies generated for this target.
include CMakeFiles/key_logger.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/key_logger.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/key_logger.dir/flags.make

CMakeFiles/key_logger.dir/main.cpp.o: CMakeFiles/key_logger.dir/flags.make
CMakeFiles/key_logger.dir/main.cpp.o: /home/jon/Code/src/misc-code/key_logger/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jon/Code/src/misc-code/build-key_logger-Desktop-Default/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/key_logger.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/key_logger.dir/main.cpp.o -c /home/jon/Code/src/misc-code/key_logger/main.cpp

CMakeFiles/key_logger.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/key_logger.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jon/Code/src/misc-code/key_logger/main.cpp > CMakeFiles/key_logger.dir/main.cpp.i

CMakeFiles/key_logger.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/key_logger.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jon/Code/src/misc-code/key_logger/main.cpp -o CMakeFiles/key_logger.dir/main.cpp.s

CMakeFiles/key_logger.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/key_logger.dir/main.cpp.o.requires

CMakeFiles/key_logger.dir/main.cpp.o.provides: CMakeFiles/key_logger.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/key_logger.dir/build.make CMakeFiles/key_logger.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/key_logger.dir/main.cpp.o.provides

CMakeFiles/key_logger.dir/main.cpp.o.provides.build: CMakeFiles/key_logger.dir/main.cpp.o

# Object files for target key_logger
key_logger_OBJECTS = \
"CMakeFiles/key_logger.dir/main.cpp.o"

# External object files for target key_logger
key_logger_EXTERNAL_OBJECTS =

key_logger: CMakeFiles/key_logger.dir/main.cpp.o
key_logger: CMakeFiles/key_logger.dir/build.make
key_logger: CMakeFiles/key_logger.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable key_logger"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/key_logger.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/key_logger.dir/build: key_logger
.PHONY : CMakeFiles/key_logger.dir/build

CMakeFiles/key_logger.dir/requires: CMakeFiles/key_logger.dir/main.cpp.o.requires
.PHONY : CMakeFiles/key_logger.dir/requires

CMakeFiles/key_logger.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/key_logger.dir/cmake_clean.cmake
.PHONY : CMakeFiles/key_logger.dir/clean

CMakeFiles/key_logger.dir/depend:
	cd /home/jon/Code/src/misc-code/build-key_logger-Desktop-Default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jon/Code/src/misc-code/key_logger /home/jon/Code/src/misc-code/key_logger /home/jon/Code/src/misc-code/build-key_logger-Desktop-Default /home/jon/Code/src/misc-code/build-key_logger-Desktop-Default /home/jon/Code/src/misc-code/build-key_logger-Desktop-Default/CMakeFiles/key_logger.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/key_logger.dir/depend
