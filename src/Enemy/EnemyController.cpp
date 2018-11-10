//
// Created by andrew on 01/11/18.
//

#include <iostream>
#include <allegro5/allegro_native_dialog.h>
#include "EnemyController.h"

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
        if(listaEnemigos.getData(i)->getPosY() == 0){
            al_draw_filled_rectangle(listaEnemigos.getData(i)->getPosX(), listaEnemigos.getData(i)->getPosY()+5,
                    listaEnemigos.getData(i)->getPosX()+90, listaEnemigos.getData(i)->getPosY(), al_map_rgb_f(255, 0, 0));
        }else{
            al_draw_filled_rectangle(listaEnemigos.getData(i)->getPosX(), listaEnemigos.getData(i)->getPosY()-5,
                    listaEnemigos.getData(i)->getPosX()+90, listaEnemigos.getData(i)->getPosY(), al_map_rgb_f(255, 0, 0));
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
        for (int i = 0; i < listaEnemigos.getLength(); ++i) {
            if (listaEnemigos1.getData(0)->second.first == listaEnemigos.getData(i)->getPosY() / 70
                && listaEnemigos1.getData(0)->second.second == listaEnemigos.getData(i)->getPosX() / 90) {
                listaEnemigos.getData(i)->setVida(listaEnemigos.getData(i)->getVida() - 1);
                if(listaEnemigos.getData(i)->getVida() == 0){
                    Application::matriz[listaEnemigos.getData(i)->getPosY()/70][listaEnemigos.getData(i)->getPosX()/90] = 1;
                    listaEnemigos.deleteNode(i);
                }
                break;
            }
        }
    }
}

