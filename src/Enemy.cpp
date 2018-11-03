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

void Enemy::setEnemy(ALLEGRO_BITMAP *enemy) {
    Enemy::enemy = enemy;
}

pair<int, int> Enemy::revisaAtaque(int matriz[10][15]) {
    int posIX = this->getPosX();
    int posIY = this->getPosY();
}

//void Enemy::atacar() {
//
//}
