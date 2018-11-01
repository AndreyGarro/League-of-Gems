//
// Created by andrew on 30/10/18.
//

#ifndef LEAGUEOFGEMS_SPRITE_H
#define LEAGUEOFGEMS_SPRITE_H

#include <string>
#include <allegro5/haptic.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Sprite.h"

using namespace std;

class Sprite {

public:
    static void dibujaObstaculo(int matriz[10][15]);
    static void dibujaPersonaje(int x, int y, ALLEGRO_BITMAP *);
    static void dibujaGema(int x, int y, ALLEGRO_BITMAP *);
};

#endif //LEAGUEOFGEMS_SPRITE_H
