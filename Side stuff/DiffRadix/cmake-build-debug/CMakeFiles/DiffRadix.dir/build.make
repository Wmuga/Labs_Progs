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
CMAKE_COMMAND = "D:\Programs\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programs\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/DiffRadix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DiffRadix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DiffRadix.dir/flags.make

CMakeFiles/DiffRadix.dir/main.cpp.obj: CMakeFiles/DiffRadix.dir/flags.make
CMakeFiles/DiffRadix.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DiffRadix.dir/main.cpp.obj"
	D:\Programs\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DiffRadix.dir\main.cpp.obj -c "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\main.cpp"

CMakeFiles/DiffRadix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiffRadix.dir/main.cpp.i"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\main.cpp" > CMakeFiles\DiffRadix.dir\main.cpp.i

CMakeFiles/DiffRadix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiffRadix.dir/main.cpp.s"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\main.cpp" -o CMakeFiles\DiffRadix.dir\main.cpp.s

CMakeFiles/DiffRadix.dir/double_r.cpp.obj: CMakeFiles/DiffRadix.dir/flags.make
CMakeFiles/DiffRadix.dir/double_r.cpp.obj: ../double_r.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DiffRadix.dir/double_r.cpp.obj"
	D:\Programs\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DiffRadix.dir\double_r.cpp.obj -c "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\double_r.cpp"

CMakeFiles/DiffRadix.dir/double_r.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DiffRadix.dir/double_r.cpp.i"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\double_r.cpp" > CMakeFiles\DiffRadix.dir\double_r.cpp.i

CMakeFiles/DiffRadix.dir/double_r.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DiffRadix.dir/double_r.cpp.s"
	D:\Programs\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\double_r.cpp" -o CMakeFiles\DiffRadix.dir\double_r.cpp.s

# Object files for target DiffRadix
DiffRadix_OBJECTS = \
"CMakeFiles/DiffRadix.dir/main.cpp.obj" \
"CMakeFiles/DiffRadix.dir/double_r.cpp.obj"

# External object files for target DiffRadix
DiffRadix_EXTERNAL_OBJECTS =

DiffRadix.exe: CMakeFiles/DiffRadix.dir/main.cpp.obj
DiffRadix.exe: CMakeFiles/DiffRadix.dir/double_r.cpp.obj
DiffRadix.exe: CMakeFiles/DiffRadix.dir/build.make
DiffRadix.exe: CMakeFiles/DiffRadix.dir/linklibs.rsp
DiffRadix.exe: CMakeFiles/DiffRadix.dir/objects1.rsp
DiffRadix.exe: CMakeFiles/DiffRadix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable DiffRadix.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DiffRadix.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DiffRadix.dir/build: DiffRadix.exe

.PHONY : CMakeFiles/DiffRadix.dir/build

CMakeFiles/DiffRadix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DiffRadix.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DiffRadix.dir/clean

CMakeFiles/DiffRadix.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix" "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix" "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\cmake-build-debug" "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\cmake-build-debug" "D:\Documents\GitHub\Labs_Progs\Side stuff\DiffRadix\cmake-build-debug\CMakeFiles\DiffRadix.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/DiffRadix.dir/depend

