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
CMAKE_SOURCE_DIR = D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StudPractice.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StudPractice.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StudPractice.dir/flags.make

CMakeFiles/StudPractice.dir/main.cpp.obj: CMakeFiles/StudPractice.dir/flags.make
CMakeFiles/StudPractice.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StudPractice.dir/main.cpp.obj"
	D:\Mingw\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\StudPractice.dir\main.cpp.obj -c D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice\main.cpp

CMakeFiles/StudPractice.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StudPractice.dir/main.cpp.i"
	D:\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice\main.cpp > CMakeFiles\StudPractice.dir\main.cpp.i

CMakeFiles/StudPractice.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StudPractice.dir/main.cpp.s"
	D:\Mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice\main.cpp -o CMakeFiles\StudPractice.dir\main.cpp.s

# Object files for target StudPractice
StudPractice_OBJECTS = \
"CMakeFiles/StudPractice.dir/main.cpp.obj"

# External object files for target StudPractice
StudPractice_EXTERNAL_OBJECTS =

StudPractice.exe: CMakeFiles/StudPractice.dir/main.cpp.obj
StudPractice.exe: CMakeFiles/StudPractice.dir/build.make
StudPractice.exe: CMakeFiles/StudPractice.dir/linklibs.rsp
StudPractice.exe: CMakeFiles/StudPractice.dir/objects1.rsp
StudPractice.exe: CMakeFiles/StudPractice.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StudPractice.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\StudPractice.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StudPractice.dir/build: StudPractice.exe

.PHONY : CMakeFiles/StudPractice.dir/build

CMakeFiles/StudPractice.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\StudPractice.dir\cmake_clean.cmake
.PHONY : CMakeFiles/StudPractice.dir/clean

CMakeFiles/StudPractice.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Sem2\StudPractice\cmake-build-debug\CMakeFiles\StudPractice.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StudPractice.dir/depend
