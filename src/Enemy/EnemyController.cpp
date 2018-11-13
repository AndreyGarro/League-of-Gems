//
// Created by andrew on 01/11/18.
//

#include <iostream>
#include <allegro5/allegro_native_dialog.h>
#include "EnemyController.h"
#include "../App/Aplicacion.h"

/**
 * Constructor, carga todas las imagenes de los
 * enemigos en una lista simple
 */
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

/**
 * Se encarga de dibujar el enemigo en pantalla
 */
void EnemyController::dibujaEnemigo() {
    for(int i = 0; i < listaEnemigos.getLength(); i++){
        Sprite::dibujaPersonaje(listaEnemigos.getData(i)->getPosX(), listaEnemigos.getData(i)->getPosY(),
                listaEnemigos.getData(i)->getEnemy(), 2);
        auto enemigoTemp = listaEnemigos.getData(i);
        float tempVida = listaEnemigos.getData(i)->getVida() / (listaEnemigos.getData(i)->getVidaMaxima() + 0.0f);
        if(listaEnemigos.getData(i)->getPosY() == 0){
            al_draw_filled_rectangle(enemigoTemp->getPosX(), enemigoTemp->getPosY()+5,
                                     enemigoTemp->getPosX()+(90*tempVida), enemigoTemp->getPosY(), al_map_rgb_f(255, 0, 0));
        }else{
            al_draw_filled_rectangle(enemigoTemp->getPosX(), enemigoTemp->getPosY()-5,
                                     enemigoTemp->getPosX()+(90*tempVida), enemigoTemp->getPosY(), al_map_rgb_f(255, 0, 0));
        }
    }
    Sprite::dibujaGema(14*86, 0, al_load_bitmap("../img/gem.png"));
}

/**
 * Valida si tiene soldados a la par y los ataca
 * @param matriz matriz con las posiciones actuales del mapa
 * @return lista con los soldados a los que atacó
 */
SimpleList<pair<int, pair<int, int>>> EnemyController::atacar(int matriz[10][15]) {

    auto listaAtacados = SimpleList<pair<int, pair<int, int>>>();
    for(int i = 0; i < listaEnemigos.getLength(); i++){
        pair <int, int> par = listaEnemigos.getData(i)->revisaAtaque(matriz);
        if(par.first != -1 && par.second != -1) {
            listaAtacados.add(make_pair(listaEnemigos.getData(i)->getAtaque(), par));
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

/**
 * Disminuye la vida de los enemigos a los que el usuario ha atacado
 * @param listaEnemigos1 lista de los enemigos a los que los soldados atacaron
 * @param display pantalla en la que se está trabajando todos los gráficos
 */
void EnemyController::disminuirVida(SimpleList<pair<int, pair<int, int>>> listaEnemigos1) {
    if(!listaEnemigos1.isEmpty()) {
        for (int i = 0; i < listaEnemigos1.getLength(); ++i) {
            int numEne = buscarEnemy(listaEnemigos1.getData(i)->second.first, listaEnemigos1.getData(i)->second.second);
            if(numEne != -1){
                listaEnemigos.getData(numEne)->setVida(listaEnemigos.getData(numEne)->getVida()-listaEnemigos1.getData(i)->first - listaEnemigos.getData(numEne)->getDefensa());
                if(listaEnemigos.getData(numEne)->getVida() <= 0){
                    Application::matriz[listaEnemigos.getData(numEne)->getPosY()/70][listaEnemigos.getData(numEne)->getPosX()/90] = 1;
                    listaEnemigos.deleteNode(numEne);
                }

            }
        }
    }
}

int EnemyController::buscarEnemy(int i, int j) {
    for (int k = 0; k < listaEnemigos.getLength(); ++k) {
        if(listaEnemigos.getData(k)->getPosY()/70 == i && listaEnemigos.getData(k)->getPosX()/90 == j){
            return k;
        }
    }
    return -1;
}
