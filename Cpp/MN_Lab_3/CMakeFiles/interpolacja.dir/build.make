# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3

# Include any dependencies generated for this target.
include CMakeFiles/interpolacja.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/interpolacja.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/interpolacja.dir/flags.make

CMakeFiles/interpolacja.dir/src/main.cpp.o: CMakeFiles/interpolacja.dir/flags.make
CMakeFiles/interpolacja.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/interpolacja.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpolacja.dir/src/main.cpp.o -c /home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3/src/main.cpp

CMakeFiles/interpolacja.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpolacja.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3/src/main.cpp > CMakeFiles/interpolacja.dir/src/main.cpp.i

CMakeFiles/interpolacja.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpolacja.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3/src/main.cpp -o CMakeFiles/interpolacja.dir/src/main.cpp.s

CMakeFiles/interpolacja.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/interpolacja.dir/src/main.cpp.o.requires

CMakeFiles/interpolacja.dir/src/main.cpp.o.provides: CMakeFiles/interpolacja.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/interpolacja.dir/build.make CMakeFiles/interpolacja.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/interpolacja.dir/src/main.cpp.o.provides

CMakeFiles/interpolacja.dir/src/main.cpp.o.provides.build: CMakeFiles/interpolacja.dir/src/main.cpp.o


# Object files for target interpolacja
interpolacja_OBJECTS = \
"CMakeFiles/interpolacja.dir/src/main.cpp.o"

# External object files for target interpolacja
interpolacja_EXTERNAL_OBJECTS =

interpolacja: CMakeFiles/interpolacja.dir/src/main.cpp.o
interpolacja: CMakeFiles/interpolacja.dir/build.make
interpolacja: CMakeFiles/interpolacja.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable interpolacja"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/interpolacja.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/interpolacja.dir/build: interpolacja

.PHONY : CMakeFiles/interpolacja.dir/build

CMakeFiles/interpolacja.dir/requires: CMakeFiles/interpolacja.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/interpolacja.dir/requires

CMakeFiles/interpolacja.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/interpolacja.dir/cmake_clean.cmake
.PHONY : CMakeFiles/interpolacja.dir/clean

CMakeFiles/interpolacja.dir/depend:
	cd /home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3 /home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3 /home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3 /home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3 /home/muser/Desktop/dev/Learning/Cpp/MN_Lab_3/CMakeFiles/interpolacja.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/interpolacja.dir/depend

