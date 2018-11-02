//
// Created by andrew on 01/11/18.
//

#include "EnemyController.h"

EnemyController::EnemyController() {
    auto e1 = new Enemy(10*90, 0*70);
    auto e2 = new Enemy(12*90, 0*70);
    auto e3 = new Enemy(10*90, 2*70);
    auto e4 = new Enemy(12*90, 2*70);
    auto e5 = new Enemy(14*90, 2*70);
    auto e6 = new Enemy(10*90, 4*70);
    auto e7 = new Enemy(12*90, 4*70);
    auto e8 = new Enemy(14*90, 4*70);
    listaEnemigos.add(*e1);
    listaEnemigos.add(*e2);
    listaEnemigos.add(*e3);
    listaEnemigos.add(*e4);
    listaEnemigos.add(*e5);
    listaEnemigos.add(*e6);
    listaEnemigos.add(*e7);
    listaEnemigos.add(*e8);
}


void EnemyController::dibujaEnemigo() {
    for(int i = 0; i < 8; i++){
        Sprite::dibujaPersonaje(listaEnemigos.getData(i).getPosX(), listaEnemigos.getData(i).getPosY(),
                al_load_bitmap("../img/enemy.png"), 2);
    }
    Sprite::dibujaGema(13*90, 0, al_load_bitmap("../img/gem.png"));
}

