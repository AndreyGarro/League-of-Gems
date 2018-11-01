//
// Created by andrew on 30/10/18.
//
#include "Sprite.h"
#include "Aplicacion.h"

void Sprite::dibujaObstaculo(int matriz[10][15]) {
    ALLEGRO_BITMAP *tree = al_load_bitmap("../img/treeSprite.png");
    al_convert_mask_to_alpha(tree, al_map_rgb(1,1,1));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 15; ++j) {
            al_draw_rectangle(j*90, i*70, j*90+90, i*70+70, al_map_rgb(0,0,0), 0);
            if(matriz[i][j] == 0){
                float x =  j*90;
                float y = i*70;
                al_draw_scaled_bitmap(tree, 0, 0, 726, 798, x-3, y-10 ,90, 90,0);
                Application::matriz[i][j] = 0;
            }
        }
    }
    al_destroy_bitmap(tree);
}

void Sprite::dibujaPersonaje(int x, int y, ALLEGRO_BITMAP *image, int flag) {
    //al_convert_mask_to_alpha(soldier, al_map_rgb(106, 76,48));
    al_draw_scaled_bitmap(image, 0, 0, 62, 76, x+23, y-10, 50, 60, 0);
    al_destroy_bitmap(image);

    if (flag == 2){
        Application::matriz[y/70][x/90] = flag;
    }
}

void Sprite::dibujaGema(int x, int y, ALLEGRO_BITMAP *image) {
    al_draw_scaled_bitmap(image, 0, 0, 100, 100, x, y, 100, 100, 0);
    al_destroy_bitmap(image);
}
