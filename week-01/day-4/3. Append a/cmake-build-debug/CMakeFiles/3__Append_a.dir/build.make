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
CMAKE_SOURCE_DIR = "D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/3__Append_a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3__Append_a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3__Append_a.dir/flags.make

CMakeFiles/3__Append_a.dir/main.cpp.obj: CMakeFiles/3__Append_a.dir/flags.make
CMakeFiles/3__Append_a.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3__Append_a.dir/main.cpp.obj"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\3__Append_a.dir\main.cpp.obj -c "D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a\main.cpp"

CMakeFiles/3__Append_a.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3__Append_a.dir/main.cpp.i"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a\main.cpp" > CMakeFiles\3__Append_a.dir\main.cpp.i

CMakeFiles/3__Append_a.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3__Append_a.dir/main.cpp.s"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a\main.cpp" -o CMakeFiles\3__Append_a.dir\main.cpp.s

# Object files for target 3__Append_a
3__Append_a_OBJECTS = \
"CMakeFiles/3__Append_a.dir/main.cpp.obj"

# External object files for target 3__Append_a
3__Append_a_EXTERNAL_OBJECTS =

3__Append_a.exe: CMakeFiles/3__Append_a.dir/main.cpp.obj
3__Append_a.exe: CMakeFiles/3__Append_a.dir/build.make
3__Append_a.exe: CMakeFiles/3__Append_a.dir/linklibs.rsp
3__Append_a.exe: CMakeFiles/3__Append_a.dir/objects1.rsp
3__Append_a.exe: CMakeFiles/3__Append_a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 3__Append_a.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\3__Append_a.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3__Append_a.dir/build: 3__Append_a.exe

.PHONY : CMakeFiles/3__Append_a.dir/build

CMakeFiles/3__Append_a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\3__Append_a.dir\cmake_clean.cmake
.PHONY : CMakeFiles/3__Append_a.dir/clean

CMakeFiles/3__Append_a.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a" "D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a" "D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a\cmake-build-debug" "D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a\cmake-build-debug" "D:\Sulis\Greenfox\sanyi0411\week-01\day-4\3. Append a\cmake-build-debug\CMakeFiles\3__Append_a.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/3__Append_a.dir/depend

