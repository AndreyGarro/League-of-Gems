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
CMAKE_COMMAND = /snap/clion/49/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/49/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/christian/Escritorio/LOG git"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/christian/Escritorio/LOG git/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/LeagueOfGems.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LeagueOfGems.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LeagueOfGems.dir/flags.make

CMakeFiles/LeagueOfGems.dir/main.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LeagueOfGems.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/main.cpp.o -c "/home/christian/Escritorio/LOG git/main.cpp"

CMakeFiles/LeagueOfGems.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/main.cpp" > CMakeFiles/LeagueOfGems.dir/main.cpp.i

CMakeFiles/LeagueOfGems.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/main.cpp" -o CMakeFiles/LeagueOfGems.dir/main.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.o: ../src/Algoritmos/GeneticEnemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.o -c "/home/christian/Escritorio/LOG git/src/Algoritmos/GeneticEnemy.cpp"

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Algoritmos/GeneticEnemy.cpp" > CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Algoritmos/GeneticEnemy.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.o: ../src/Algoritmos/GeneticAlgorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.o -c "/home/christian/Escritorio/LOG git/src/Algoritmos/GeneticAlgorithm.cpp"

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Algoritmos/GeneticAlgorithm.cpp" > CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Algoritmos/GeneticAlgorithm.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.s

CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.o: ../src/App/Aplicacion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.o -c "/home/christian/Escritorio/LOG git/src/App/Aplicacion.cpp"

CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/App/Aplicacion.cpp" > CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.i

CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/App/Aplicacion.cpp" -o CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.o: ../src/Algoritmos/AStarPathFinding.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.o -c "/home/christian/Escritorio/LOG git/src/Algoritmos/AStarPathFinding.cpp"

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Algoritmos/AStarPathFinding.cpp" > CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Algoritmos/AStarPathFinding.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.o: ../src/Algoritmos/LineaVista.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.o -c "/home/christian/Escritorio/LOG git/src/Algoritmos/LineaVista.cpp"

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Algoritmos/LineaVista.cpp" > CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Algoritmos/LineaVista.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.s

CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.o: ../src/App/Sprite.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.o -c "/home/christian/Escritorio/LOG git/src/App/Sprite.cpp"

CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/App/Sprite.cpp" > CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.i

CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/App/Sprite.cpp" -o CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.o: ../src/Soldier/SoldierController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.o -c "/home/christian/Escritorio/LOG git/src/Soldier/SoldierController.cpp"

CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Soldier/SoldierController.cpp" > CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Soldier/SoldierController.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.o: ../src/Soldier/Soldier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.o -c "/home/christian/Escritorio/LOG git/src/Soldier/Soldier.cpp"

CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Soldier/Soldier.cpp" > CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Soldier/Soldier.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.o: ../src/Algoritmos/Dijkstra.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.o -c "/home/christian/Escritorio/LOG git/src/Algoritmos/Dijkstra.cpp"

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Algoritmos/Dijkstra.cpp" > CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Algoritmos/Dijkstra.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.o: ../src/Enemy/Enemy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.o -c "/home/christian/Escritorio/LOG git/src/Enemy/Enemy.cpp"

CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Enemy/Enemy.cpp" > CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Enemy/Enemy.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.o: ../src/Enemy/EnemyController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.o -c "/home/christian/Escritorio/LOG git/src/Enemy/EnemyController.cpp"

CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Enemy/EnemyController.cpp" > CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Enemy/EnemyController.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.o: ../src/Algoritmos/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.o -c "/home/christian/Escritorio/LOG git/src/Algoritmos/Graph.cpp"

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Algoritmos/Graph.cpp" > CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Algoritmos/Graph.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.o: ../src/Algoritmos/GraphMaker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.o -c "/home/christian/Escritorio/LOG git/src/Algoritmos/GraphMaker.cpp"

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Algoritmos/GraphMaker.cpp" > CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Algoritmos/GraphMaker.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.o: ../src/Algoritmos/Kruskal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.o -c "/home/christian/Escritorio/LOG git/src/Algoritmos/Kruskal.cpp"

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Algoritmos/Kruskal.cpp" > CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Algoritmos/Kruskal.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.s

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.o: CMakeFiles/LeagueOfGems.dir/flags.make
CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.o: ../src/Algoritmos/Prim.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.o -c "/home/christian/Escritorio/LOG git/src/Algoritmos/Prim.cpp"

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/christian/Escritorio/LOG git/src/Algoritmos/Prim.cpp" > CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.i

CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/christian/Escritorio/LOG git/src/Algoritmos/Prim.cpp" -o CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.s

# Object files for target LeagueOfGems
LeagueOfGems_OBJECTS = \
"CMakeFiles/LeagueOfGems.dir/main.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.o" \
"CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.o"

# External object files for target LeagueOfGems
LeagueOfGems_EXTERNAL_OBJECTS =

LeagueOfGems: CMakeFiles/LeagueOfGems.dir/main.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticEnemy.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GeneticAlgorithm.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/App/Aplicacion.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Algoritmos/AStarPathFinding.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Algoritmos/LineaVista.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/App/Sprite.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Soldier/SoldierController.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Soldier/Soldier.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Dijkstra.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Enemy/Enemy.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Enemy/EnemyController.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Graph.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Algoritmos/GraphMaker.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Kruskal.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/src/Algoritmos/Prim.cpp.o
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/build.make
LeagueOfGems: CMakeFiles/LeagueOfGems.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable LeagueOfGems"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LeagueOfGems.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LeagueOfGems.dir/build: LeagueOfGems

.PHONY : CMakeFiles/LeagueOfGems.dir/build

CMakeFiles/LeagueOfGems.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LeagueOfGems.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LeagueOfGems.dir/clean

CMakeFiles/LeagueOfGems.dir/depend:
	cd "/home/christian/Escritorio/LOG git/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/christian/Escritorio/LOG git" "/home/christian/Escritorio/LOG git" "/home/christian/Escritorio/LOG git/cmake-build-debug" "/home/christian/Escritorio/LOG git/cmake-build-debug" "/home/christian/Escritorio/LOG git/cmake-build-debug/CMakeFiles/LeagueOfGems.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LeagueOfGems.dir/depend

