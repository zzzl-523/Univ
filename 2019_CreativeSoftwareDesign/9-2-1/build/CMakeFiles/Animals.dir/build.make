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
CMAKE_SOURCE_DIR = /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/build

# Include any dependencies generated for this target.
include CMakeFiles/Animals.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Animals.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Animals.dir/flags.make

CMakeFiles/Animals.dir/main.cpp.o: CMakeFiles/Animals.dir/flags.make
CMakeFiles/Animals.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Animals.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Animals.dir/main.cpp.o -c /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/main.cpp

CMakeFiles/Animals.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Animals.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/main.cpp > CMakeFiles/Animals.dir/main.cpp.i

CMakeFiles/Animals.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Animals.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/main.cpp -o CMakeFiles/Animals.dir/main.cpp.s

CMakeFiles/Animals.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Animals.dir/main.cpp.o.requires

CMakeFiles/Animals.dir/main.cpp.o.provides: CMakeFiles/Animals.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Animals.dir/build.make CMakeFiles/Animals.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Animals.dir/main.cpp.o.provides

CMakeFiles/Animals.dir/main.cpp.o.provides.build: CMakeFiles/Animals.dir/main.cpp.o


CMakeFiles/Animals.dir/animal.cpp.o: CMakeFiles/Animals.dir/flags.make
CMakeFiles/Animals.dir/animal.cpp.o: ../animal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Animals.dir/animal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Animals.dir/animal.cpp.o -c /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/animal.cpp

CMakeFiles/Animals.dir/animal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Animals.dir/animal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/animal.cpp > CMakeFiles/Animals.dir/animal.cpp.i

CMakeFiles/Animals.dir/animal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Animals.dir/animal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/animal.cpp -o CMakeFiles/Animals.dir/animal.cpp.s

CMakeFiles/Animals.dir/animal.cpp.o.requires:

.PHONY : CMakeFiles/Animals.dir/animal.cpp.o.requires

CMakeFiles/Animals.dir/animal.cpp.o.provides: CMakeFiles/Animals.dir/animal.cpp.o.requires
	$(MAKE) -f CMakeFiles/Animals.dir/build.make CMakeFiles/Animals.dir/animal.cpp.o.provides.build
.PHONY : CMakeFiles/Animals.dir/animal.cpp.o.provides

CMakeFiles/Animals.dir/animal.cpp.o.provides.build: CMakeFiles/Animals.dir/animal.cpp.o


# Object files for target Animals
Animals_OBJECTS = \
"CMakeFiles/Animals.dir/main.cpp.o" \
"CMakeFiles/Animals.dir/animal.cpp.o"

# External object files for target Animals
Animals_EXTERNAL_OBJECTS =

Animals: CMakeFiles/Animals.dir/main.cpp.o
Animals: CMakeFiles/Animals.dir/animal.cpp.o
Animals: CMakeFiles/Animals.dir/build.make
Animals: CMakeFiles/Animals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Animals"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Animals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Animals.dir/build: Animals

.PHONY : CMakeFiles/Animals.dir/build

CMakeFiles/Animals.dir/requires: CMakeFiles/Animals.dir/main.cpp.o.requires
CMakeFiles/Animals.dir/requires: CMakeFiles/Animals.dir/animal.cpp.o.requires

.PHONY : CMakeFiles/Animals.dir/requires

CMakeFiles/Animals.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Animals.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Animals.dir/clean

CMakeFiles/Animals.dir/depend:
	cd /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1 /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1 /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/build /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/build /home/zzigang/Documents/2019_ITE1015_2019060164/9-2-1/build/CMakeFiles/Animals.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Animals.dir/depend

