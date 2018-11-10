cmake_minimum_required(VERSION 3.12)
project(LeagueOfGems)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(LeagueOfGems main.cpp src/Algoritmos/GeneticAlgorithm.h src/Algoritmos/GeneticEnemy.cpp src/Algoritmos/GeneticEnemy.h src/Algoritmos/GeneticAlgorithm.cpp src/App/Aplicacion.h src/App/Aplicacion.cpp src/Algoritmos/AStarPathFinding.cpp src/Algoritmos/AStarPathFinding.h src/Estructuras/SimpleList.h src/Estructuras/Pila.h src/Estructuras/Cola.h src/LineaVista/LineaVista.cpp src/LineaVista/LineaVista.h src/App/Sprite.cpp src/App/Sprite.h src/Soldier/SoldierController.cpp src/Soldier/SoldierController.h src/Soldier/Soldier.cpp src/Soldier/Soldier.h src/Algoritmos/Dijkstra.cpp src/Algoritmos/Dijkstra.h src/Enemy/Enemy.cpp src/Enemy/Enemy.h src/Enemy/EnemyController.cpp src/Enemy/EnemyController.h src/Algoritmos/Graph.cpp src/Algoritmos/Graph.h src/Algoritmos/GraphMaker.cpp src/Algoritmos/GraphMaker.h src/Algoritmos/Kruskal.cpp src/Algoritmos/Kruskal.h src/Algoritmos/Prim.cpp src/Algoritmos/Prim.h)

INCLUDE_DIRECTORIES( allegro/5.0.11/include )

LINK_DIRECTORIES( allegro/5.0.11/lib )


TARGET_LINK_LIBRARIES(LeagueOfGems  allegro_acodec
        allegro_audio
        allegro_color
        allegro_dialog
        allegro_image
        allegro_main
        allegro_memfile
        allegro_physfs
        allegro_primitives
        allegro_ttf
        allegro_font
        allegro)