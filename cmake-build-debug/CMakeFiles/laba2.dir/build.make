# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kirill\CLionProjects\laba2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kirill\CLionProjects\laba2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/laba2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/laba2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/laba2.dir/flags.make

CMakeFiles/laba2.dir/main.cpp.obj: CMakeFiles/laba2.dir/flags.make
CMakeFiles/laba2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kirill\CLionProjects\laba2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/laba2.dir/main.cpp.obj"
	C:\python\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\laba2.dir\main.cpp.obj -c C:\Users\kirill\CLionProjects\laba2\main.cpp

CMakeFiles/laba2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/laba2.dir/main.cpp.i"
	C:\python\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kirill\CLionProjects\laba2\main.cpp > CMakeFiles\laba2.dir\main.cpp.i

CMakeFiles/laba2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/laba2.dir/main.cpp.s"
	C:\python\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kirill\CLionProjects\laba2\main.cpp -o CMakeFiles\laba2.dir\main.cpp.s

# Object files for target laba2
laba2_OBJECTS = \
"CMakeFiles/laba2.dir/main.cpp.obj"

# External object files for target laba2
laba2_EXTERNAL_OBJECTS =

laba2.exe: CMakeFiles/laba2.dir/main.cpp.obj
laba2.exe: CMakeFiles/laba2.dir/build.make
laba2.exe: CMakeFiles/laba2.dir/linklibs.rsp
laba2.exe: CMakeFiles/laba2.dir/objects1.rsp
laba2.exe: CMakeFiles/laba2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kirill\CLionProjects\laba2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable laba2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\laba2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/laba2.dir/build: laba2.exe

.PHONY : CMakeFiles/laba2.dir/build

CMakeFiles/laba2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\laba2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/laba2.dir/clean

CMakeFiles/laba2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kirill\CLionProjects\laba2 C:\Users\kirill\CLionProjects\laba2 C:\Users\kirill\CLionProjects\laba2\cmake-build-debug C:\Users\kirill\CLionProjects\laba2\cmake-build-debug C:\Users\kirill\CLionProjects\laba2\cmake-build-debug\CMakeFiles\laba2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/laba2.dir/depend
