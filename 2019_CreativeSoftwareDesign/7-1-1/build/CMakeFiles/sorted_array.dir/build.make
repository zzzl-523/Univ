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
CMAKE_SOURCE_DIR = /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/build

# Include any dependencies generated for this target.
include CMakeFiles/sorted_array.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sorted_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sorted_array.dir/flags.make

CMakeFiles/sorted_array.dir/main.cpp.o: CMakeFiles/sorted_array.dir/flags.make
CMakeFiles/sorted_array.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sorted_array.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sorted_array.dir/main.cpp.o -c /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/main.cpp

CMakeFiles/sorted_array.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sorted_array.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/main.cpp > CMakeFiles/sorted_array.dir/main.cpp.i

CMakeFiles/sorted_array.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sorted_array.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/main.cpp -o CMakeFiles/sorted_array.dir/main.cpp.s

CMakeFiles/sorted_array.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/sorted_array.dir/main.cpp.o.requires

CMakeFiles/sorted_array.dir/main.cpp.o.provides: CMakeFiles/sorted_array.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sorted_array.dir/build.make CMakeFiles/sorted_array.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/sorted_array.dir/main.cpp.o.provides

CMakeFiles/sorted_array.dir/main.cpp.o.provides.build: CMakeFiles/sorted_array.dir/main.cpp.o


CMakeFiles/sorted_array.dir/sorted.cpp.o: CMakeFiles/sorted_array.dir/flags.make
CMakeFiles/sorted_array.dir/sorted.cpp.o: ../sorted.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sorted_array.dir/sorted.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sorted_array.dir/sorted.cpp.o -c /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/sorted.cpp

CMakeFiles/sorted_array.dir/sorted.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sorted_array.dir/sorted.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/sorted.cpp > CMakeFiles/sorted_array.dir/sorted.cpp.i

CMakeFiles/sorted_array.dir/sorted.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sorted_array.dir/sorted.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/sorted.cpp -o CMakeFiles/sorted_array.dir/sorted.cpp.s

CMakeFiles/sorted_array.dir/sorted.cpp.o.requires:

.PHONY : CMakeFiles/sorted_array.dir/sorted.cpp.o.requires

CMakeFiles/sorted_array.dir/sorted.cpp.o.provides: CMakeFiles/sorted_array.dir/sorted.cpp.o.requires
	$(MAKE) -f CMakeFiles/sorted_array.dir/build.make CMakeFiles/sorted_array.dir/sorted.cpp.o.provides.build
.PHONY : CMakeFiles/sorted_array.dir/sorted.cpp.o.provides

CMakeFiles/sorted_array.dir/sorted.cpp.o.provides.build: CMakeFiles/sorted_array.dir/sorted.cpp.o


# Object files for target sorted_array
sorted_array_OBJECTS = \
"CMakeFiles/sorted_array.dir/main.cpp.o" \
"CMakeFiles/sorted_array.dir/sorted.cpp.o"

# External object files for target sorted_array
sorted_array_EXTERNAL_OBJECTS =

sorted_array: CMakeFiles/sorted_array.dir/main.cpp.o
sorted_array: CMakeFiles/sorted_array.dir/sorted.cpp.o
sorted_array: CMakeFiles/sorted_array.dir/build.make
sorted_array: CMakeFiles/sorted_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable sorted_array"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sorted_array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sorted_array.dir/build: sorted_array

.PHONY : CMakeFiles/sorted_array.dir/build

CMakeFiles/sorted_array.dir/requires: CMakeFiles/sorted_array.dir/main.cpp.o.requires
CMakeFiles/sorted_array.dir/requires: CMakeFiles/sorted_array.dir/sorted.cpp.o.requires

.PHONY : CMakeFiles/sorted_array.dir/requires

CMakeFiles/sorted_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sorted_array.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sorted_array.dir/clean

CMakeFiles/sorted_array.dir/depend:
	cd /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1 /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1 /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/build /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/build /home/zzigang/Documents/2019_ITE1015_2019060164/7-1-1/build/CMakeFiles/sorted_array.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sorted_array.dir/depend

