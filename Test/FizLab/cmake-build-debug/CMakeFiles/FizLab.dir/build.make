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
CMAKE_SOURCE_DIR = D:\Documents\GitHub\Labs_Progs\Test\FizLab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\GitHub\Labs_Progs\Test\FizLab\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FizLab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FizLab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FizLab.dir/flags.make

CMakeFiles/FizLab.dir/main.cpp.obj: CMakeFiles/FizLab.dir/flags.make
CMakeFiles/FizLab.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Documents\GitHub\Labs_Progs\Test\FizLab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FizLab.dir/main.cpp.obj"
	D:\Mingw\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\FizLab.dir\main.cpp.obj -c D:\Documents\GitHub\Labs_Progs\Test\FizLab\main.cpp

CMakeFiles/FizLab.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FizLab.dir/main.cpp.i"
	D:\Mingw\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Documents\GitHub\Labs_Progs\Test\FizLab\main.cpp > CMakeFiles\FizLab.dir\main.cpp.i

CMakeFiles/FizLab.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FizLab.dir/main.cpp.s"
	D:\Mingw\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Documents\GitHub\Labs_Progs\Test\FizLab\main.cpp -o CMakeFiles\FizLab.dir\main.cpp.s

# Object files for target FizLab
FizLab_OBJECTS = \
"CMakeFiles/FizLab.dir/main.cpp.obj"

# External object files for target FizLab
FizLab_EXTERNAL_OBJECTS =

FizLab.exe: CMakeFiles/FizLab.dir/main.cpp.obj
FizLab.exe: CMakeFiles/FizLab.dir/build.make
FizLab.exe: CMakeFiles/FizLab.dir/linklibs.rsp
FizLab.exe: CMakeFiles/FizLab.dir/objects1.rsp
FizLab.exe: CMakeFiles/FizLab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Documents\GitHub\Labs_Progs\Test\FizLab\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FizLab.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FizLab.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FizLab.dir/build: FizLab.exe

.PHONY : CMakeFiles/FizLab.dir/build

CMakeFiles/FizLab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FizLab.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FizLab.dir/clean

CMakeFiles/FizLab.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\GitHub\Labs_Progs\Test\FizLab D:\Documents\GitHub\Labs_Progs\Test\FizLab D:\Documents\GitHub\Labs_Progs\Test\FizLab\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Test\FizLab\cmake-build-debug D:\Documents\GitHub\Labs_Progs\Test\FizLab\cmake-build-debug\CMakeFiles\FizLab.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FizLab.dir/depend

