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
CMAKE_SOURCE_DIR = "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/30__DrawDiagonal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/30__DrawDiagonal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/30__DrawDiagonal.dir/flags.make

CMakeFiles/30__DrawDiagonal.dir/main.cpp.obj: CMakeFiles/30__DrawDiagonal.dir/flags.make
CMakeFiles/30__DrawDiagonal.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/30__DrawDiagonal.dir/main.cpp.obj"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\30__DrawDiagonal.dir\main.cpp.obj -c "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal\main.cpp"

CMakeFiles/30__DrawDiagonal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/30__DrawDiagonal.dir/main.cpp.i"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal\main.cpp" > CMakeFiles\30__DrawDiagonal.dir\main.cpp.i

CMakeFiles/30__DrawDiagonal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/30__DrawDiagonal.dir/main.cpp.s"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal\main.cpp" -o CMakeFiles\30__DrawDiagonal.dir\main.cpp.s

# Object files for target 30__DrawDiagonal
30__DrawDiagonal_OBJECTS = \
"CMakeFiles/30__DrawDiagonal.dir/main.cpp.obj"

# External object files for target 30__DrawDiagonal
30__DrawDiagonal_EXTERNAL_OBJECTS =

30__DrawDiagonal.exe: CMakeFiles/30__DrawDiagonal.dir/main.cpp.obj
30__DrawDiagonal.exe: CMakeFiles/30__DrawDiagonal.dir/build.make
30__DrawDiagonal.exe: CMakeFiles/30__DrawDiagonal.dir/linklibs.rsp
30__DrawDiagonal.exe: CMakeFiles/30__DrawDiagonal.dir/objects1.rsp
30__DrawDiagonal.exe: CMakeFiles/30__DrawDiagonal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 30__DrawDiagonal.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\30__DrawDiagonal.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/30__DrawDiagonal.dir/build: 30__DrawDiagonal.exe

.PHONY : CMakeFiles/30__DrawDiagonal.dir/build

CMakeFiles/30__DrawDiagonal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\30__DrawDiagonal.dir\cmake_clean.cmake
.PHONY : CMakeFiles/30__DrawDiagonal.dir/clean

CMakeFiles/30__DrawDiagonal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal\cmake-build-debug" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal\cmake-build-debug" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\30. DrawDiagonal\cmake-build-debug\CMakeFiles\30__DrawDiagonal.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/30__DrawDiagonal.dir/depend
