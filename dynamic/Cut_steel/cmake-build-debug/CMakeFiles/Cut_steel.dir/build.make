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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mac/Desktop/suanfa/dynamic/Cut_steel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mac/Desktop/suanfa/dynamic/Cut_steel/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Cut_steel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Cut_steel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cut_steel.dir/flags.make

CMakeFiles/Cut_steel.dir/main.cpp.o: CMakeFiles/Cut_steel.dir/flags.make
CMakeFiles/Cut_steel.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mac/Desktop/suanfa/dynamic/Cut_steel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cut_steel.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Cut_steel.dir/main.cpp.o -c /Users/mac/Desktop/suanfa/dynamic/Cut_steel/main.cpp

CMakeFiles/Cut_steel.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cut_steel.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mac/Desktop/suanfa/dynamic/Cut_steel/main.cpp > CMakeFiles/Cut_steel.dir/main.cpp.i

CMakeFiles/Cut_steel.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cut_steel.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mac/Desktop/suanfa/dynamic/Cut_steel/main.cpp -o CMakeFiles/Cut_steel.dir/main.cpp.s

# Object files for target Cut_steel
Cut_steel_OBJECTS = \
"CMakeFiles/Cut_steel.dir/main.cpp.o"

# External object files for target Cut_steel
Cut_steel_EXTERNAL_OBJECTS =

Cut_steel: CMakeFiles/Cut_steel.dir/main.cpp.o
Cut_steel: CMakeFiles/Cut_steel.dir/build.make
Cut_steel: CMakeFiles/Cut_steel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mac/Desktop/suanfa/dynamic/Cut_steel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Cut_steel"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Cut_steel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cut_steel.dir/build: Cut_steel

.PHONY : CMakeFiles/Cut_steel.dir/build

CMakeFiles/Cut_steel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Cut_steel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Cut_steel.dir/clean

CMakeFiles/Cut_steel.dir/depend:
	cd /Users/mac/Desktop/suanfa/dynamic/Cut_steel/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mac/Desktop/suanfa/dynamic/Cut_steel /Users/mac/Desktop/suanfa/dynamic/Cut_steel /Users/mac/Desktop/suanfa/dynamic/Cut_steel/cmake-build-debug /Users/mac/Desktop/suanfa/dynamic/Cut_steel/cmake-build-debug /Users/mac/Desktop/suanfa/dynamic/Cut_steel/cmake-build-debug/CMakeFiles/Cut_steel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cut_steel.dir/depend
