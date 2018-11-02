//
// Created by andrew on 31/10/18.
//

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

//void Enemy::atacar() {
//
//}
