//
// Created by andrew on 30/10/18.
//
#include "Sprite.h"

void Sprite::dibujaObstaculo(int matriz[10][15]) {
    ALLEGRO_BITMAP *tree = al_load_bitmap("../img/treeSprite.png");
    al_convert_mask_to_alpha(tree, al_map_rgb(1,1,1));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 15; ++j) {
            if(matriz[i][j] == 0){
                float x =  j*90;
                float y = i*70;
                al_draw_scaled_bitmap(tree, 0, 0, 726, 798, x, y ,90, 70,0);
            }
        }
    }
    al_destroy_bitmap(tree);
}

void Sprite::dibujaPersonaje(int x, int y, ALLEGRO_BITMAP *image) {
    //al_convert_mask_to_alpha(soldier, al_map_rgb(106, 76,48));
    al_draw_scaled_bitmap(image, 0, 0, 62, 76, x, y, 50, 60, 0);
    al_destroy_bitmap(image);
}

void Sprite::dibujaGema(int x, int y, ALLEGRO_BITMAP *image) {
    al_draw_scaled_bitmap(image, 0, 0, 100, 100, x, y, 100, 100, 0);
    al_destroy_bitmap(image);
}
