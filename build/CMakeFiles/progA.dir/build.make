# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\amevu\Desktop\mtm\EX1\matam\ex3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\amevu\Desktop\mtm\EX1\matam\build

# Include any dependencies generated for this target.
include CMakeFiles/progA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/progA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/progA.dir/flags.make

CMakeFiles/progA.dir/partA/date_wrap.cpp.obj: CMakeFiles/progA.dir/flags.make
CMakeFiles/progA.dir/partA/date_wrap.cpp.obj: CMakeFiles/progA.dir/includes_CXX.rsp
CMakeFiles/progA.dir/partA/date_wrap.cpp.obj: C:/Users/amevu/Desktop/mtm/EX1/matam/ex3/partA/date_wrap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\amevu\Desktop\mtm\EX1\matam\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/progA.dir/partA/date_wrap.cpp.obj"
	C:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\progA.dir\partA\date_wrap.cpp.obj -c C:\Users\amevu\Desktop\mtm\EX1\matam\ex3\partA\date_wrap.cpp

CMakeFiles/progA.dir/partA/date_wrap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progA.dir/partA/date_wrap.cpp.i"
	C:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\amevu\Desktop\mtm\EX1\matam\ex3\partA\date_wrap.cpp > CMakeFiles\progA.dir\partA\date_wrap.cpp.i

CMakeFiles/progA.dir/partA/date_wrap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progA.dir/partA/date_wrap.cpp.s"
	C:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\amevu\Desktop\mtm\EX1\matam\ex3\partA\date_wrap.cpp -o CMakeFiles\progA.dir\partA\date_wrap.cpp.s

CMakeFiles/progA.dir/provided/test_partA.cpp.obj: CMakeFiles/progA.dir/flags.make
CMakeFiles/progA.dir/provided/test_partA.cpp.obj: CMakeFiles/progA.dir/includes_CXX.rsp
CMakeFiles/progA.dir/provided/test_partA.cpp.obj: C:/Users/amevu/Desktop/mtm/EX1/matam/ex3/provided/test_partA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\amevu\Desktop\mtm\EX1\matam\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/progA.dir/provided/test_partA.cpp.obj"
	C:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\progA.dir\provided\test_partA.cpp.obj -c C:\Users\amevu\Desktop\mtm\EX1\matam\ex3\provided\test_partA.cpp

CMakeFiles/progA.dir/provided/test_partA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/progA.dir/provided/test_partA.cpp.i"
	C:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\amevu\Desktop\mtm\EX1\matam\ex3\provided\test_partA.cpp > CMakeFiles\progA.dir\provided\test_partA.cpp.i

CMakeFiles/progA.dir/provided/test_partA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/progA.dir/provided/test_partA.cpp.s"
	C:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\amevu\Desktop\mtm\EX1\matam\ex3\provided\test_partA.cpp -o CMakeFiles\progA.dir\provided\test_partA.cpp.s

# Object files for target progA
progA_OBJECTS = \
"CMakeFiles/progA.dir/partA/date_wrap.cpp.obj" \
"CMakeFiles/progA.dir/provided/test_partA.cpp.obj"

# External object files for target progA
progA_EXTERNAL_OBJECTS =

progA.exe: CMakeFiles/progA.dir/partA/date_wrap.cpp.obj
progA.exe: CMakeFiles/progA.dir/provided/test_partA.cpp.obj
progA.exe: CMakeFiles/progA.dir/build.make
progA.exe: C:/Users/amevu/Desktop/mtm/EX1/matam/ex3/provided/libdate.a
progA.exe: CMakeFiles/progA.dir/linklibs.rsp
progA.exe: CMakeFiles/progA.dir/objects1.rsp
progA.exe: CMakeFiles/progA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\amevu\Desktop\mtm\EX1\matam\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable progA.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\progA.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/progA.dir/build: progA.exe

.PHONY : CMakeFiles/progA.dir/build

CMakeFiles/progA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\progA.dir\cmake_clean.cmake
.PHONY : CMakeFiles/progA.dir/clean

CMakeFiles/progA.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\amevu\Desktop\mtm\EX1\matam\ex3 C:\Users\amevu\Desktop\mtm\EX1\matam\ex3 C:\Users\amevu\Desktop\mtm\EX1\matam\build C:\Users\amevu\Desktop\mtm\EX1\matam\build C:\Users\amevu\Desktop\mtm\EX1\matam\build\CMakeFiles\progA.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/progA.dir/depend

