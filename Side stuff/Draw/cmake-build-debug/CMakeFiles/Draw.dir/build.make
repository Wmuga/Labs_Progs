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
CMAKE_SOURCE_DIR = "D:\Documents\GitHub\Labs_Progs\Side stuff\Draw"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Documents\GitHub\Labs_Progs\Side stuff\Draw\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Draw.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Draw.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Draw.dir/flags.make

CMakeFiles/Draw.dir/main.cpp.obj: CMakeFiles/Draw.dir/flags.make
CMakeFiles/Draw.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documents\GitHub\Labs_Progs\Side stuff\Draw\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Draw.dir/main.cpp.obj"
	D:\Mingw\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Draw.dir\main.cpp.obj -c "D:\Documents\GitHub\Labs_Progs\Side stuff\Draw\main.cpp"

CMakeFiles/Draw.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Draw.dir/main.cpp.i"
	D:\Mingw\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents\GitHub\Labs_Progs\Side stuff\Draw\main.cpp" > CMakeFiles\Draw.dir\main.cpp.i

CMakeFiles/Draw.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Draw.dir/main.cpp.s"
	D:\Mingw\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents\GitHub\Labs_Progs\Side stuff\Draw\main.cpp" -o CMakeFiles\Draw.dir\main.cpp.s

# Object files for target Draw
Draw_OBJECTS = \
"CMakeFiles/Draw.dir/main.cpp.obj"

# External object files for target Draw
Draw_EXTERNAL_OBJECTS =

Draw.exe: CMakeFiles/Draw.dir/main.cpp.obj
Draw.exe: CMakeFiles/Draw.dir/build.make
Draw.exe: CMakeFiles/Draw.dir/linklibs.rsp
Draw.exe: CMakeFiles/Draw.dir/objects1.rsp
Draw.exe: CMakeFiles/Draw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Documents\GitHub\Labs_Progs\Side stuff\Draw\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Draw.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Draw.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Draw.dir/build: Draw.exe

.PHONY : CMakeFiles/Draw.dir/build

CMakeFiles/Draw.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Draw.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Draw.dir/clean

CMakeFiles/Draw.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Documents\GitHub\Labs_Progs\Side stuff\Draw" "D:\Documents\GitHub\Labs_Progs\Side stuff\Draw" "D:\Documents\GitHub\Labs_Progs\Side stuff\Draw\cmake-build-debug" "D:\Documents\GitHub\Labs_Progs\Side stuff\Draw\cmake-build-debug" "D:\Documents\GitHub\Labs_Progs\Side stuff\Draw\cmake-build-debug\CMakeFiles\Draw.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Draw.dir/depend

