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
include CMakeFiles/progC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/progC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/progC.dir/flags.make

CMakeFiles/progC.dir/provided/test_partC.cpp.o: CMakeFiles/progC.dir/flags.make
CMakeFiles/progC.dir/provided/test_partC.cpp.o: ../provided/test_partC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/assafklein/mtm/matam/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/progC.dir/provided/test_partC.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/progC.dir/provided/test_partC.cpp.o -c /home/assafklein/mtm/matam/ex3/provided/test_partC.cpp

CMakeFiles/progC.dir/provided/test_partC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progC.dir/provided/test_partC.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/assafklein/mtm/matam/ex3/provided/test_partC.cpp > CMakeFiles/progC.dir/provided/test_partC.cpp.i

CMakeFiles/progC.dir/provided/test_partC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progC.dir/provided/test_partC.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/assafklein/mtm/matam/ex3/provided/test_partC.cpp -o CMakeFiles/progC.dir/provided/test_partC.cpp.s

CMakeFiles/progC.dir/partC/schedule.cpp.o: CMakeFiles/progC.dir/flags.make
CMakeFiles/progC.dir/partC/schedule.cpp.o: ../partC/schedule.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/assafklein/mtm/matam/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/progC.dir/partC/schedule.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/progC.dir/partC/schedule.cpp.o -c /home/assafklein/mtm/matam/ex3/partC/schedule.cpp

CMakeFiles/progC.dir/partC/schedule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progC.dir/partC/schedule.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/assafklein/mtm/matam/ex3/partC/schedule.cpp > CMakeFiles/progC.dir/partC/schedule.cpp.i

CMakeFiles/progC.dir/partC/schedule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progC.dir/partC/schedule.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/assafklein/mtm/matam/ex3/partC/schedule.cpp -o CMakeFiles/progC.dir/partC/schedule.cpp.s

# Object files for target progC
progC_OBJECTS = \
"CMakeFiles/progC.dir/provided/test_partC.cpp.o" \
"CMakeFiles/progC.dir/partC/schedule.cpp.o"

# External object files for target progC
progC_EXTERNAL_OBJECTS =

$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)progC: CMakeFiles/progC.dir/provided/test_partC.cpp.o
$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)progC: CMakeFiles/progC.dir/partC/schedule.cpp.o
$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)progC: CMakeFiles/progC.dir/build.make
$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)progC: ../provided/libdate.a
$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)progC: CMakeFiles/progC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/assafklein/mtm/matam/ex3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ======progC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/progC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/progC.dir/build: $(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)$(EQUALS)progC

.PHONY : CMakeFiles/progC.dir/build

CMakeFiles/progC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/progC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/progC.dir/clean

CMakeFiles/progC.dir/depend:
	cd /home/assafklein/mtm/matam/ex3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/assafklein/mtm/matam/ex3 /home/assafklein/mtm/matam/ex3 /home/assafklein/mtm/matam/ex3/build /home/assafklein/mtm/matam/ex3/build /home/assafklein/mtm/matam/ex3/build/CMakeFiles/progC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/progC.dir/depend

