cmake_minimum_required(VERSION 3.12)
project(LeagueOfGems)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(LeagueOfGems main.cpp src/Gráficos/Aplicacion.h src/Gráficos/Aplicacion.cpp src/A*/AStarPathFinding.cpp src/A*/AStarPathFinding.h src/Estructuras/SimpleList.h src/Estructuras/Pila.h src/Estructuras/Cola.h src/LineaVista/LineaVista.cpp src/LineaVista/LineaVista.h src/Gráficos/Sprite.cpp src/Gráficos/Sprite.h src/Gráficos/Player.cpp src/Gráficos/Player.h)
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