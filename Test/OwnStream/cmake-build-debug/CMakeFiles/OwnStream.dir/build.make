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
CMAKE_SOURCE_DIR = D:\Documents\GitHub\Labs_Progs\Test\OwnStream

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\GitHub\Labs_Progs\Test\OwnStream\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OwnStream.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OwnStream.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OwnStream.dir/flags.make

CMakeFiles/OwnStream.dir/main.cpp.obj: CMakeFiles/OwnStream.dir/flags.make
CMakeFiles/OwnStream.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\GitHub\Labs_Progs\Test\OwnStream\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OwnStream.dir/main.cpp.obj"
	D:\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OwnStream.dir\main.cpp.obj -c D:\Documents\GitHub\Labs_Progs\Test\OwnStream\main.cpp

CMakeFiles/OwnStream.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OwnStream.dir/main.cpp.i"
	D:\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\GitHub\Labs_Progs\Test\OwnStream\main.cpp > CMakeFiles\OwnStream.dir\main.cpp.i

CMakeFiles/OwnStream.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OwnStream.dir/main.cpp.s"
	D:\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\GitHub\Labs_Progs\Test\OwnStream\main.cpp -o CMakeFiles\OwnStream.dir\main.cpp.s

# Object files for target OwnStream
OwnStream_OBJECTS = \
"CMakeFiles/OwnStream.dir/main.cpp.obj"

# External object files for target OwnStream
OwnStream_EXTERNAL_OBJECTS =

OwnStream.exe: CMakeFiles/OwnStream.dir/main.cpp.obj
OwnStream.exe: CMakeFiles/OwnStream.dir/build.make
OwnStream.exe: CMakeFiles/OwnStream.dir/linklibs.rsp
OwnStream.exe: CMakeFiles/OwnStream.dir/objects1.rsp
OwnStream.exe: CMakeFiles/OwnStream.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\GitHub\Labs_Progs\Test\OwnStream\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OwnStream.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OwnStream.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OwnStream.dir/build: OwnStream.exe

.PHONY : CMakeFiles/OwnStream.dir/build

CMakeFiles/OwnStream.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OwnStream.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OwnStream.dir/clean

CMakeFiles/OwnStream.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\GitHub\Labs_Progs\Test\OwnStream D:\Documents\GitHub\Labs_Progs\Test\OwnStream D:\Documents\GitHub\Labs_Progs\Test\OwnStream\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Test\OwnStream\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Test\OwnStream\cmake-build-debug\CMakeFiles\OwnStream.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OwnStream.dir/depend
