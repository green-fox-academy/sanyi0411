# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "D:\Programok\CLion\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programok\CLion\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/33__DrawChessTable.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/33__DrawChessTable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/33__DrawChessTable.dir/flags.make

CMakeFiles/33__DrawChessTable.dir/main.cpp.obj: CMakeFiles/33__DrawChessTable.dir/flags.make
CMakeFiles/33__DrawChessTable.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/33__DrawChessTable.dir/main.cpp.obj"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\33__DrawChessTable.dir\main.cpp.obj -c "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable\main.cpp"

CMakeFiles/33__DrawChessTable.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/33__DrawChessTable.dir/main.cpp.i"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable\main.cpp" > CMakeFiles\33__DrawChessTable.dir\main.cpp.i

CMakeFiles/33__DrawChessTable.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/33__DrawChessTable.dir/main.cpp.s"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable\main.cpp" -o CMakeFiles\33__DrawChessTable.dir\main.cpp.s

# Object files for target 33__DrawChessTable
33__DrawChessTable_OBJECTS = \
"CMakeFiles/33__DrawChessTable.dir/main.cpp.obj"

# External object files for target 33__DrawChessTable
33__DrawChessTable_EXTERNAL_OBJECTS =

33__DrawChessTable.exe: CMakeFiles/33__DrawChessTable.dir/main.cpp.obj
33__DrawChessTable.exe: CMakeFiles/33__DrawChessTable.dir/build.make
33__DrawChessTable.exe: CMakeFiles/33__DrawChessTable.dir/linklibs.rsp
33__DrawChessTable.exe: CMakeFiles/33__DrawChessTable.dir/objects1.rsp
33__DrawChessTable.exe: CMakeFiles/33__DrawChessTable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 33__DrawChessTable.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\33__DrawChessTable.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/33__DrawChessTable.dir/build: 33__DrawChessTable.exe

.PHONY : CMakeFiles/33__DrawChessTable.dir/build

CMakeFiles/33__DrawChessTable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\33__DrawChessTable.dir\cmake_clean.cmake
.PHONY : CMakeFiles/33__DrawChessTable.dir/clean

CMakeFiles/33__DrawChessTable.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable\cmake-build-debug" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable\cmake-build-debug" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\33. DrawChessTable\cmake-build-debug\CMakeFiles\33__DrawChessTable.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/33__DrawChessTable.dir/depend

