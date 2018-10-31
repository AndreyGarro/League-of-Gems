//
// Created by andrew on 30/10/18.
//
#include "Sprite.h"

void Sprite::dibujaObstaculo(int matriz[15][27]) {
    ALLEGRO_BITMAP *tree = al_load_bitmap("../img/treeSprite.jpg");
    al_convert_mask_to_alpha(tree, al_map_rgb(1,1,1));
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 27; ++j) {
            if(matriz[i][j] == 0){
                float x =  j*48;
                float y = i*46;
                al_draw_scaled_bitmap(tree, 0, 0, 525, 480, x, y ,48, 46,0);
            }
        }
    }
    al_destroy_bitmap(tree);
}

void Sprite::dibujaSoldado(int x, int y,ALLEGRO_BITMAP *soldier) {
    al_convert_mask_to_alpha(soldier, al_map_rgb(106, 76,48));
    al_draw_scaled_bitmap(soldier, 0, 0, 96, 96, x, y, 55, 46, 0);
    al_destroy_bitmap(soldier);
}
