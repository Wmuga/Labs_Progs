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
CMAKE_SOURCE_DIR = D:\Documents\GitHub\Labs_Progs\Sem2\Lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\GitHub\Labs_Progs\Sem2\Lab5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab5.dir/flags.make

CMakeFiles/Lab5.dir/main.cpp.obj: CMakeFiles/Lab5.dir/flags.make
CMakeFiles/Lab5.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\GitHub\Labs_Progs\Sem2\Lab5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab5.dir/main.cpp.obj"
	D:\Programs\mingw-w64\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab5.dir\main.cpp.obj -c D:\Documents\GitHub\Labs_Progs\Sem2\Lab5\main.cpp

CMakeFiles/Lab5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab5.dir/main.cpp.i"
	D:\Programs\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\GitHub\Labs_Progs\Sem2\Lab5\main.cpp > CMakeFiles\Lab5.dir\main.cpp.i

CMakeFiles/Lab5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab5.dir/main.cpp.s"
	D:\Programs\mingw-w64\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\GitHub\Labs_Progs\Sem2\Lab5\main.cpp -o CMakeFiles\Lab5.dir\main.cpp.s

# Object files for target Lab5
Lab5_OBJECTS = \
"CMakeFiles/Lab5.dir/main.cpp.obj"

# External object files for target Lab5
Lab5_EXTERNAL_OBJECTS =

Lab5.exe: CMakeFiles/Lab5.dir/main.cpp.obj
Lab5.exe: CMakeFiles/Lab5.dir/build.make
Lab5.exe: CMakeFiles/Lab5.dir/linklibs.rsp
Lab5.exe: CMakeFiles/Lab5.dir/objects1.rsp
Lab5.exe: CMakeFiles/Lab5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\GitHub\Labs_Progs\Sem2\Lab5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab5.dir/build: Lab5.exe

.PHONY : CMakeFiles/Lab5.dir/build

CMakeFiles/Lab5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab5.dir/clean

CMakeFiles/Lab5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\GitHub\Labs_Progs\Sem2\Lab5 D:\Documents\GitHub\Labs_Progs\Sem2\Lab5 D:\Documents\GitHub\Labs_Progs\Sem2\Lab5\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Sem2\Lab5\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Sem2\Lab5\cmake-build-debug\CMakeFiles\Lab5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab5.dir/depend

