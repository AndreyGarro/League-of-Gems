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
    static void dibujaObstaculo(int matriz[25][50]);
    static void dibujaSoldado(int matriz[25][50]);
};


void Sprite::dibujaObstaculo(int matriz[25][50]) {
    ALLEGRO_BITMAP *tree = al_load_bitmap("../img/treeSprite.png");
    al_convert_mask_to_alpha(tree, al_map_rgb(0,0,0));
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 50; ++j) {
            if(matriz[i][j] == 0){
                float x =  j*50;
                float y = i*25;
                al_draw_rectangle(x,y,x+26,y+28,al_map_rgb_f(1,1,1), 0);
                al_draw_scaled_bitmap(tree, 0, 0, 900, 560, x, y ,26, 28,0);
            }
        }
    }
}

void Sprite::dibujaSoldado(int matriz[25][50]) {
    ALLEGRO_BITMAP *soldier = al_load_bitmap("../img/looking s0001.bmp");
    al_convert_mask_to_alpha(soldier, al_map_rgb(0,0,0));
//    al_draw_rectangle(0, 0, 26,, 28, al_map_rgb_f(1,1,1), 0);
    al_draw_scaled_bitmap(soldier, 0, 0, 900, 560, 0, 0, 26, 28, 0);

}
#endif //LEAGUEOFGEMS_SPRITE_H
