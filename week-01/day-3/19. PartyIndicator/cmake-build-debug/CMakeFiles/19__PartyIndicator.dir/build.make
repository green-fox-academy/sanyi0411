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
CMAKE_SOURCE_DIR = "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/19__PartyIndicator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/19__PartyIndicator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/19__PartyIndicator.dir/flags.make

CMakeFiles/19__PartyIndicator.dir/main.cpp.obj: CMakeFiles/19__PartyIndicator.dir/flags.make
CMakeFiles/19__PartyIndicator.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/19__PartyIndicator.dir/main.cpp.obj"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\19__PartyIndicator.dir\main.cpp.obj -c "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator\main.cpp"

CMakeFiles/19__PartyIndicator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/19__PartyIndicator.dir/main.cpp.i"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator\main.cpp" > CMakeFiles\19__PartyIndicator.dir\main.cpp.i

CMakeFiles/19__PartyIndicator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/19__PartyIndicator.dir/main.cpp.s"
	D:\Programok\CLion\MinGW\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator\main.cpp" -o CMakeFiles\19__PartyIndicator.dir\main.cpp.s

# Object files for target 19__PartyIndicator
19__PartyIndicator_OBJECTS = \
"CMakeFiles/19__PartyIndicator.dir/main.cpp.obj"

# External object files for target 19__PartyIndicator
19__PartyIndicator_EXTERNAL_OBJECTS =

19__PartyIndicator.exe: CMakeFiles/19__PartyIndicator.dir/main.cpp.obj
19__PartyIndicator.exe: CMakeFiles/19__PartyIndicator.dir/build.make
19__PartyIndicator.exe: CMakeFiles/19__PartyIndicator.dir/linklibs.rsp
19__PartyIndicator.exe: CMakeFiles/19__PartyIndicator.dir/objects1.rsp
19__PartyIndicator.exe: CMakeFiles/19__PartyIndicator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 19__PartyIndicator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\19__PartyIndicator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/19__PartyIndicator.dir/build: 19__PartyIndicator.exe

.PHONY : CMakeFiles/19__PartyIndicator.dir/build

CMakeFiles/19__PartyIndicator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\19__PartyIndicator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/19__PartyIndicator.dir/clean

CMakeFiles/19__PartyIndicator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator\cmake-build-debug" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator\cmake-build-debug" "D:\Sulis\Greenfox\sanyi0411\week-01\day-3\19. PartyIndicator\cmake-build-debug\CMakeFiles\19__PartyIndicator.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/19__PartyIndicator.dir/depend

