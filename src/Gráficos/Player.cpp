//
// Created by andrew on 30/10/18.
//

#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include "Player.h"
#include <string>
#include <allegro5/allegro_image.h>

using namespace std;

void Player::caminaEste() {
    if(++frameCount >= frameDelay){
        if(++curFrame >= 12){
            curFrame = 0;
        }
        frameCount = 0;
    }
}

void Player::loadCaminaEste() {

    al_init_image_addon();

    image[0] = al_load_bitmap("../img/walking e0000.bmp");
    image[1] = al_load_bitmap("../img/walking e0001.bmp");
    image[2] = al_load_bitmap("../img/walking e0002.bmp");
    image[3] = al_load_bitmap("../img/walking e0003.bmp");
    image[4] = al_load_bitmap("../img/walking e0004.bmp");
    image[5] = al_load_bitmap("../img/walking e0005.bmp");
    image[6] = al_load_bitmap("../img/walking e0006.bmp");
    image[7] = al_load_bitmap("../img/walking e0007.bmp");
    image[8] = al_load_bitmap("../img/walking e0008.bmp");
    image[9] = al_load_bitmap("../img/walking e0009.bmp");
    image[10] = al_load_bitmap("../img/walking e0010.bmp");
    image[11] = al_load_bitmap("../img/walking e0011.bmp");

    for(int i = 0; i < 12; i++){
        al_convert_mask_to_alpha(image[i], al_map_rgb(106, 76, 48));
    }
}

void Player::dibujaCaminaEste() {
    al_draw_bitmap(image[curFrame], 200, 100, 0);
}
