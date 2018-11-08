//
// Created by andrew on 31/10/18.
//

#include <iostream>
#include "Enemy.h"

Enemy::Enemy(int x, int y) {
    this->posX = x;
    this->posY = y;
}

int Enemy::getPosX() const {
    return posX;
}

int Enemy::getPosY() const {
    return posY;
}

ALLEGRO_BITMAP *Enemy::getEnemy() const {
    return enemy;
}

void Enemy::setEnemy(ALLEGRO_BITMAP *enemy) {
    Enemy::enemy = enemy;
}

pair<int, int> Enemy::revisaAtaque(int matriz[10][15]) {
    if (this->cont > 20 && this->cont > 10){
        this->cont = 0;
    }
    this->cont ++;
    if(this->cont < 10) {
        int posIX = (this->getPosX() / 90) - 1;
        int posIY = (this->getPosY() / 70) - 1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (posIX+j < 15 && matriz[abs(posIY + i)][abs(posIX + j)] == 3) {
                    this->atacando = true;
                    return make_pair(abs(posIY + i), abs(posIX + j));
                }
            }
        }
    }
    this->atacando = false;
    return make_pair(-1, -1);
}

