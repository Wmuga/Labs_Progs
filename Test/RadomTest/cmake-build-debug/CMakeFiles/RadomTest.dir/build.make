# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Programs\JetBrains\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\Programs\JetBrains\CLion\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Documents\GitHub\Labs_Progs\Test\RadomTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\GitHub\Labs_Progs\Test\RadomTest\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RadomTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RadomTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RadomTest.dir/flags.make

CMakeFiles/RadomTest.dir/main.cpp.obj: CMakeFiles/RadomTest.dir/flags.make
CMakeFiles/RadomTest.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\GitHub\Labs_Progs\Test\RadomTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RadomTest.dir/main.cpp.obj"
	D:\Programs\mingw-w64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RadomTest.dir\main.cpp.obj -c D:\Documents\GitHub\Labs_Progs\Test\RadomTest\main.cpp

CMakeFiles/RadomTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RadomTest.dir/main.cpp.i"
	D:\Programs\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\GitHub\Labs_Progs\Test\RadomTest\main.cpp > CMakeFiles\RadomTest.dir\main.cpp.i

CMakeFiles/RadomTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RadomTest.dir/main.cpp.s"
	D:\Programs\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\GitHub\Labs_Progs\Test\RadomTest\main.cpp -o CMakeFiles\RadomTest.dir\main.cpp.s

# Object files for target RadomTest
RadomTest_OBJECTS = \
"CMakeFiles/RadomTest.dir/main.cpp.obj"

# External object files for target RadomTest
RadomTest_EXTERNAL_OBJECTS =

RadomTest.exe: CMakeFiles/RadomTest.dir/main.cpp.obj
RadomTest.exe: CMakeFiles/RadomTest.dir/build.make
RadomTest.exe: CMakeFiles/RadomTest.dir/linklibs.rsp
RadomTest.exe: CMakeFiles/RadomTest.dir/objects1.rsp
RadomTest.exe: CMakeFiles/RadomTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\GitHub\Labs_Progs\Test\RadomTest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RadomTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RadomTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RadomTest.dir/build: RadomTest.exe

.PHONY : CMakeFiles/RadomTest.dir/build

CMakeFiles/RadomTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RadomTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RadomTest.dir/clean

CMakeFiles/RadomTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\GitHub\Labs_Progs\Test\RadomTest D:\Documents\GitHub\Labs_Progs\Test\RadomTest D:\Documents\GitHub\Labs_Progs\Test\RadomTest\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Test\RadomTest\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Test\RadomTest\cmake-build-debug\CMakeFiles\RadomTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RadomTest.dir/depend

