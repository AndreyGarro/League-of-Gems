//
// Created by andrew on 31/10/18.
//

#include "Enemy.h"
#include "Sprite.h"

void Enemy::dibujaEnemigo() {
    ALLEGRO_BITMAP *enemigo = al_load_bitmap("../img/enemy.png");
    ALLEGRO_BITMAP *gema = al_load_bitmap("../img/gem.png");
    Sprite::dibujaPersonaje(1100, 100, enemigo, 2);
    Sprite::dibujaGema(1190, 10, gema);
}

//void Enemy::atacar() {
//
//}
