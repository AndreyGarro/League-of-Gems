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
                al_draw_scaled_bitmap(tree, 0, 0, 726, 798, x, y-15 ,85, 80,0);
                Application::matriz[i][j] = 0;
            }
        }
    }
    al_destroy_bitmap(tree);
}

void Sprite::dibujaPersonaje(int x, int y, ALLEGRO_BITMAP *image, int flag) {
    if (flag == 2){
        Application::matriz[y/70][x/90] = flag;
        al_draw_scaled_bitmap(image, 0, 0, 55, 59, x+23, y+5, 50, 60, 0);
    }
    else{
        al_draw_scaled_bitmap(image, 0, 0, 62, 76, x+20, y+7, 50, 60, 0);
    }
    al_destroy_bitmap(image);
}

void Sprite::dibujaGema(int x, int y, ALLEGRO_BITMAP *image) {
    al_draw_scaled_bitmap(image, 0, 0, 100, 100, x, y, 100, 100, 0);
    al_destroy_bitmap(image);
}

void Sprite::dibujaBarraAtaques(int (*matriz)[15]) {

    ALLEGRO_BITMAP *ataque = al_load_bitmap("../img/aumentarAtaque.png");
    ALLEGRO_BITMAP *defensa = al_load_bitmap("../img/aumentarDefensa.png");
    ALLEGRO_BITMAP *curar = al_load_bitmap("../img/aumentarVida.png");
    al_draw_scaled_bitmap(ataque, 0, 0, 70, 90, 90, 70*9, 90, 70, 0);
    al_draw_scaled_bitmap(defensa, 0, 0, 70, 90, 180, 70*9, 90, 70, 0);
    al_draw_scaled_bitmap(curar, 0, 0, 70, 90, 270, 70*9, 90, 70, 0);

    al_destroy_bitmap(ataque);
    al_destroy_bitmap(defensa);
    al_destroy_bitmap(curar);
}
