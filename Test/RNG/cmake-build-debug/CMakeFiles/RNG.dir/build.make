# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = D:\Programming\JetBrains\CLion\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\Programming\JetBrains\CLion\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Documents\GitHub\Labs_Progs\Test\RNG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\GitHub\Labs_Progs\Test\RNG\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RNG.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RNG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RNG.dir/flags.make

CMakeFiles/RNG.dir/main.cpp.obj: CMakeFiles/RNG.dir/flags.make
CMakeFiles/RNG.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\GitHub\Labs_Progs\Test\RNG\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RNG.dir/main.cpp.obj"
	D:\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RNG.dir\main.cpp.obj -c D:\Documents\GitHub\Labs_Progs\Test\RNG\main.cpp

CMakeFiles/RNG.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RNG.dir/main.cpp.i"
	D:\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\GitHub\Labs_Progs\Test\RNG\main.cpp > CMakeFiles\RNG.dir\main.cpp.i

CMakeFiles/RNG.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RNG.dir/main.cpp.s"
	D:\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\GitHub\Labs_Progs\Test\RNG\main.cpp -o CMakeFiles\RNG.dir\main.cpp.s

# Object files for target RNG
RNG_OBJECTS = \
"CMakeFiles/RNG.dir/main.cpp.obj"

# External object files for target RNG
RNG_EXTERNAL_OBJECTS =

RNG.exe: CMakeFiles/RNG.dir/main.cpp.obj
RNG.exe: CMakeFiles/RNG.dir/build.make
RNG.exe: CMakeFiles/RNG.dir/linklibs.rsp
RNG.exe: CMakeFiles/RNG.dir/objects1.rsp
RNG.exe: CMakeFiles/RNG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\GitHub\Labs_Progs\Test\RNG\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RNG.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RNG.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RNG.dir/build: RNG.exe

.PHONY : CMakeFiles/RNG.dir/build

CMakeFiles/RNG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RNG.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RNG.dir/clean

CMakeFiles/RNG.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\GitHub\Labs_Progs\Test\RNG D:\Documents\GitHub\Labs_Progs\Test\RNG D:\Documents\GitHub\Labs_Progs\Test\RNG\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Test\RNG\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Test\RNG\cmake-build-debug\CMakeFiles\RNG.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RNG.dir/depend
