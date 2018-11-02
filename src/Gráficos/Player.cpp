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

        this->s1.setIJ(i,j, matriz);
        this->s2.setIJ(i,j, matriz);
        this->s3.setIJ(i,j, matriz);
        this->s4.setIJ(i,j, matriz);
        this->s5.setIJ(i,j, matriz);
        this->s6.setIJ(i,j, matriz);
    }
}

void Player::dibujaJugador() {
    this->s1.dibujarSoldado();
    this->s2.dibujarSoldado();
    this->s3.dibujarSoldado();
    this->s4.dibujarSoldado();
    this->s5.dibujarSoldado();
    this->s6.dibujarSoldado();

}

Player::Player() {
}


