//
// Created by andrew on 01/11/18.
//

#include <iostream>
#include "EnemyController.h"

EnemyController::EnemyController() {
    auto e1 = Enemy(10*90, 0*70);
    auto e2 = Enemy(12*90, 0*70);
    auto e3 = Enemy(10*90, 2*70);
    auto e4 = Enemy(12*90, 2*70);
    auto e5 = Enemy(14*90, 2*70);
    auto e6 = Enemy(10*90, 4*70);
    auto e7 = Enemy(12*90, 4*70);
    auto e8 = Enemy(14*90, 4*70);
    listaEnemigos.add(e1);
    listaEnemigos.add(e2);
    listaEnemigos.add(e3);
    listaEnemigos.add(e4);
    listaEnemigos.add(e5);
    listaEnemigos.add(e6);
    listaEnemigos.add(e7);
    listaEnemigos.add(e8);
}


void EnemyController::dibujaEnemigo() {
    for(int i = 0; i < listaEnemigos.getLength(); i++){
        Sprite::dibujaPersonaje(listaEnemigos.getData(i)->getPosX(), listaEnemigos.getData(i)->getPosY(),
                listaEnemigos.getData(i)->getEnemy(), 2);
    }
    Sprite::dibujaGema(13*90, 0, al_load_bitmap("../img/gem.png"));
}

SimpleList<pair<int, pair<int, int>>> EnemyController::atacar(int matriz[10][15]) {

    auto listaAtacados = SimpleList<pair<int, pair<int, int>>>();
    for(int i = 0; i < listaEnemigos.getLength(); i++){
        pair <int, int> par = listaEnemigos.getData(i)->revisaAtaque(matriz);
        if(par.first != -1 && par.second != -1) {
            listaAtacados.add(make_pair(1, par));
        }
        if(listaEnemigos.getData(i)->atacando){
            listaEnemigos.getData(i)->setEnemy(al_load_bitmap("../img/attackEast.png"));
        }
        else{
            listaEnemigos.getData(i)->setEnemy(al_load_bitmap("../img/enemy.png"));
        }

    }
    return listaAtacados;
}

void EnemyController::disminuirVida(SimpleList<pair<int, pair<int, int>>> listaEnemigos1) {

    if(!listaEnemigos1.isEmpty()) {
        for (int i = 0; i < listaEnemigos.getLength(); ++i) {
            if (listaEnemigos1.getData(0)->second.first == listaEnemigos.getData(i)->getPosY() / 70
                && listaEnemigos1.getData(0)->second.second == listaEnemigos.getData(i)->getPosX() / 90) {
                listaEnemigos.getData(i)->setVida(listaEnemigos.getData(i)->getVida() - 1);
                if(listaEnemigos.getData(i)->getVida() == 0){
                    listaEnemigos.deleteNode(i);
                }
                break;
            }
        }
    }
}

