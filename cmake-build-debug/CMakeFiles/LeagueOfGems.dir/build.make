# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /snap/clion/44/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/44/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/christian/Escritorio/LOG3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christian/Escritorio/LOG3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LeagueOfGems.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LeagueOfGems.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LeagueOfGems.dir/flags.make

CMakeFiles/LeagueOfGems.dir/main.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/Escritorio/LOG3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LeagueOfGems.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/main.cpp.o -c /home/christian/Escritorio/LOG3/main.cpp

CMakeFiles/LeagueOfGems.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/Escritorio/LOG3/main.cpp > CMakeFiles/LeagueOfGems.dir/main.cpp.i

CMakeFiles/LeagueOfGems.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/Escritorio/LOG3/main.cpp -o CMakeFiles/LeagueOfGems.dir/main.cpp.s

CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.o: ../src/pantalla/Aplicacion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christian/Escritorio/LOG3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.o -c /home/christian/Escritorio/LOG3/src/pantalla/Aplicacion.cpp

CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christian/Escritorio/LOG3/src/pantalla/Aplicacion.cpp > CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.i

CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christian/Escritorio/LOG3/src/pantalla/Aplicacion.cpp -o CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.s

# Object files for target LeagueOfGems
LeagueOfGems_OBJECTS = \
"CMakeFiles/LeagueOfGems.dir/main.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.o"

# External object files for target LeagueOfGems
LeagueOfGems_EXTERNAL_OBJECTS =

LeagueOfGems: CMakeFiles/LeagueOfGems.dir/main.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/pantalla/Aplicacion.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/build.make
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christian/Escritorio/LOG3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable LeagueOfGems"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LeagueOfGems.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LeagueOfGems.dir/build: LeagueOfGems

.PHONY : CMakeFiles/LeagueOfGems.dir/build

CMakeFiles/LeagueOfGems.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LeagueOfGems.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LeagueOfGems.dir/clean

CMakeFiles/LeagueOfGems.dir/depend:
	cd /home/christian/Escritorio/LOG3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christian/Escritorio/LOG3 /home/christian/Escritorio/LOG3 /home/christian/Escritorio/LOG3/cmake-build-debug /home/christian/Escritorio/LOG3/cmake-build-debug /home/christian/Escritorio/LOG3/cmake-build-debug/CMakeFiles/LeagueOfGems.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LeagueOfGems.dir/depend

