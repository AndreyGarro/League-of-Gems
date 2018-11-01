//
// Created by andrew on 30/10/18.
//

#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include "Player.h"
#include <string>
#include <allegro5/allegro_image.h>

using namespace std;

void Player::setIJ(int i, int j, int matriz[10][15]) {
    if(this->i != i or this->j != j) {
        this->i = i;
        this->j = j;
        s1.setIJ(i, j, matriz);
    }
}

void Player::dibujaJugador() {
    s1.dibujarSoldado();

}

Player::Player() {
    s1 = Soldier();
}


