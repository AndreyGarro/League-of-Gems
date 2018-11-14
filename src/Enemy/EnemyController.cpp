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
    crearEnemigos();
    SimpleList<GeneticEnemy> listaEnemigoGenetico = genetic->makeNewEnemies(true);
    establecerCaracteristicas(listaEnemigoGenetico);
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
            listaEnemigos.getData(i)->moreDamage(listaEnemigos.getData(i)->getAtaque());
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
bool EnemyController::disminuirVida(SimpleList<pair<int, pair<int, int>>> listaEnemigos1) {
    if(!listaEnemigos1.isEmpty()) {
        for (int i = 0; i < listaEnemigos1.getLength(); ++i) {
            int numEne = buscarEnemy(listaEnemigos1.getData(i)->second.first, listaEnemigos1.getData(i)->second.second);
            if(numEne != -1){
                listaEnemigos.getData(numEne)->setVida(listaEnemigos.getData(numEne)->getVida()-listaEnemigos1.getData(i)->first - listaEnemigos.getData(numEne)->getDefensa());
                listaEnemigos.getData(numEne)->moreDefense();
                if(listaEnemigos.getData(numEne)->getVida() <= 0){
                    Application::matriz[listaEnemigos.getData(numEne)->getPosY()/70][listaEnemigos.getData(numEne)->getPosX()/90] = 1;
                    genetic->addFitnessData(listaEnemigos.getData(numEne)->getFitnessData(), listaEnemigos.getData(numEne)->getPosLista());
                    listaEnemigos.deleteNode(numEne);
                }
            }
        }
    }
    return listaEnemigos.getLength() == 0;
}

int EnemyController::buscarEnemy(int i, int j) {
    for (int k = 0; k < listaEnemigos.getLength(); ++k) {
        if(listaEnemigos.getData(k)->getPosY()/70 == i && listaEnemigos.getData(k)->getPosX()/90 == j){
            return k;
        }
    }
    return -1;
}

void EnemyController::establecerCaracteristicas(SimpleList<GeneticEnemy> listaEnemigoGenetico){
    for (int i = 0; i < listaEnemigoGenetico.getLength(); ++i) {
        GeneticEnemy *tempEnemy = listaEnemigoGenetico.getData(i);
        Enemy *temp = listaEnemigos.getData(i);
        temp->setVida(tempEnemy->getHealth());
        temp->setVidaMaxima(tempEnemy->getHealth());
        temp->setDefensa(tempEnemy->getDefence());
        temp->setAtaque(tempEnemy->getDamage());
        temp->setFrecuenciaAtaque(tempEnemy->getAtackFreq());
        temp->setPosLista(i);
    }
}

void EnemyController::crearEnemigos(){
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

void EnemyController::subirNivel() {
    while (!listaEnemigos.isEmpty()){
        listaEnemigos.deleteNode(0);
    }
    genetic->printEnemiesData();
    SimpleList<GeneticEnemy> listaGenetica = genetic->makeNewEnemies(false);
    crearEnemigos();
    establecerCaracteristicas(listaGenetica);

}
