# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/mtm/cmake-3.17.0-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/mtm/cmake-3.17.0-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/assafklein/mtm/matam/ex3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/assafklein/mtm/matam/ex3/build

# Include any dependencies generated for this target.
include CMakeFiles/progA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/progA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/progA.dir/flags.make

CMakeFiles/progA.dir/partA/date_wrap.cpp.o: CMakeFiles/progA.dir/flags.make
CMakeFiles/progA.dir/partA/date_wrap.cpp.o: ../partA/date_wrap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/assafklein/mtm/matam/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/progA.dir/partA/date_wrap.cpp.o"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/progA.dir/partA/date_wrap.cpp.o -c /home/assafklein/mtm/matam/ex3/partA/date_wrap.cpp

CMakeFiles/progA.dir/partA/date_wrap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progA.dir/partA/date_wrap.cpp.i"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/assafklein/mtm/matam/ex3/partA/date_wrap.cpp > CMakeFiles/progA.dir/partA/date_wrap.cpp.i

CMakeFiles/progA.dir/partA/date_wrap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progA.dir/partA/date_wrap.cpp.s"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/assafklein/mtm/matam/ex3/partA/date_wrap.cpp -o CMakeFiles/progA.dir/partA/date_wrap.cpp.s

CMakeFiles/progA.dir/provided/test_partA.cpp.o: CMakeFiles/progA.dir/flags.make
CMakeFiles/progA.dir/provided/test_partA.cpp.o: ../provided/test_partA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/assafklein/mtm/matam/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/progA.dir/provided/test_partA.cpp.o"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/progA.dir/provided/test_partA.cpp.o -c /home/assafklein/mtm/matam/ex3/provided/test_partA.cpp

CMakeFiles/progA.dir/provided/test_partA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progA.dir/provided/test_partA.cpp.i"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/assafklein/mtm/matam/ex3/provided/test_partA.cpp > CMakeFiles/progA.dir/provided/test_partA.cpp.i

CMakeFiles/progA.dir/provided/test_partA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progA.dir/provided/test_partA.cpp.s"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/assafklein/mtm/matam/ex3/provided/test_partA.cpp -o CMakeFiles/progA.dir/provided/test_partA.cpp.s

# Object files for target progA
progA_OBJECTS = \
"CMakeFiles/progA.dir/partA/date_wrap.cpp.o" \
"CMakeFiles/progA.dir/provided/test_partA.cpp.o"

# External object files for target progA
progA_EXTERNAL_OBJECTS =

progA: CMakeFiles/progA.dir/partA/date_wrap.cpp.o
progA: CMakeFiles/progA.dir/provided/test_partA.cpp.o
progA: CMakeFiles/progA.dir/build.make
progA: ../provided/libdate.a
progA: CMakeFiles/progA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/assafklein/mtm/matam/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable progA"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/progA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/progA.dir/build: progA

.PHONY : CMakeFiles/progA.dir/build

CMakeFiles/progA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/progA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/progA.dir/clean

CMakeFiles/progA.dir/depend:
	cd /home/assafklein/mtm/matam/ex3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/assafklein/mtm/matam/ex3 /home/assafklein/mtm/matam/ex3 /home/assafklein/mtm/matam/ex3/build /home/assafklein/mtm/matam/ex3/build /home/assafklein/mtm/matam/ex3/build/CMakeFiles/progA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/progA.dir/depend

