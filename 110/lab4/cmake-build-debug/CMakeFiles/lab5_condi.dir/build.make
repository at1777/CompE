# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/atuser/git/CompE/110/lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/atuser/git/CompE/110/lab4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab5_condi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab5_condi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab5_condi.dir/flags.make

CMakeFiles/lab5_condi.dir/lab5_condi.c.o: CMakeFiles/lab5_condi.dir/flags.make
CMakeFiles/lab5_condi.dir/lab5_condi.c.o: ../lab5_condi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/atuser/git/CompE/110/lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab5_condi.dir/lab5_condi.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab5_condi.dir/lab5_condi.c.o   -c /home/atuser/git/CompE/110/lab4/lab5_condi.c

CMakeFiles/lab5_condi.dir/lab5_condi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab5_condi.dir/lab5_condi.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/atuser/git/CompE/110/lab4/lab5_condi.c > CMakeFiles/lab5_condi.dir/lab5_condi.c.i

CMakeFiles/lab5_condi.dir/lab5_condi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab5_condi.dir/lab5_condi.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/atuser/git/CompE/110/lab4/lab5_condi.c -o CMakeFiles/lab5_condi.dir/lab5_condi.c.s

# Object files for target lab5_condi
lab5_condi_OBJECTS = \
"CMakeFiles/lab5_condi.dir/lab5_condi.c.o"

# External object files for target lab5_condi
lab5_condi_EXTERNAL_OBJECTS =

lab5_condi: CMakeFiles/lab5_condi.dir/lab5_condi.c.o
lab5_condi: CMakeFiles/lab5_condi.dir/build.make
lab5_condi: CMakeFiles/lab5_condi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/atuser/git/CompE/110/lab4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab5_condi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab5_condi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab5_condi.dir/build: lab5_condi

.PHONY : CMakeFiles/lab5_condi.dir/build

CMakeFiles/lab5_condi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab5_condi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab5_condi.dir/clean

CMakeFiles/lab5_condi.dir/depend:
	cd /home/atuser/git/CompE/110/lab4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/atuser/git/CompE/110/lab4 /home/atuser/git/CompE/110/lab4 /home/atuser/git/CompE/110/lab4/cmake-build-debug /home/atuser/git/CompE/110/lab4/cmake-build-debug /home/atuser/git/CompE/110/lab4/cmake-build-debug/CMakeFiles/lab5_condi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab5_condi.dir/depend
