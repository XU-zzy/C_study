# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/zzy/clion-2019.2.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zzy/clion-2019.2.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zzy/Study/CLionProjects/my_string

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zzy/Study/CLionProjects/my_string/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/my_string.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/my_string.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_string.dir/flags.make

CMakeFiles/my_string.dir/main.cpp.o: CMakeFiles/my_string.dir/flags.make
CMakeFiles/my_string.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzy/Study/CLionProjects/my_string/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_string.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/my_string.dir/main.cpp.o -c /home/zzy/Study/CLionProjects/my_string/main.cpp

CMakeFiles/my_string.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_string.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzy/Study/CLionProjects/my_string/main.cpp > CMakeFiles/my_string.dir/main.cpp.i

CMakeFiles/my_string.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_string.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzy/Study/CLionProjects/my_string/main.cpp -o CMakeFiles/my_string.dir/main.cpp.s

# Object files for target my_string
my_string_OBJECTS = \
"CMakeFiles/my_string.dir/main.cpp.o"

# External object files for target my_string
my_string_EXTERNAL_OBJECTS =

my_string: CMakeFiles/my_string.dir/main.cpp.o
my_string: CMakeFiles/my_string.dir/build.make
my_string: CMakeFiles/my_string.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zzy/Study/CLionProjects/my_string/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable my_string"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_string.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_string.dir/build: my_string

.PHONY : CMakeFiles/my_string.dir/build

CMakeFiles/my_string.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_string.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_string.dir/clean

CMakeFiles/my_string.dir/depend:
	cd /home/zzy/Study/CLionProjects/my_string/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zzy/Study/CLionProjects/my_string /home/zzy/Study/CLionProjects/my_string /home/zzy/Study/CLionProjects/my_string/cmake-build-debug /home/zzy/Study/CLionProjects/my_string/cmake-build-debug /home/zzy/Study/CLionProjects/my_string/cmake-build-debug/CMakeFiles/my_string.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_string.dir/depend

