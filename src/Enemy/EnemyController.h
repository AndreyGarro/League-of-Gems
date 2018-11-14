//
// Created by andrew on 01/11/18.
//

#ifndef LEAGUEOFGEMS_ENEMYCONTROLLER_H
#define LEAGUEOFGEMS_ENEMYCONTROLLER_H


#include "../Estructuras/SimpleList.h"
#include "Enemy.h"
#include "../Algoritmos/GeneticAlgorithm.h"

class EnemyController {

private:
    SimpleList<Enemy> listaEnemigos;
    int contAtaque = 0;
    GeneticAlgorithm *genetic = new GeneticAlgorithm();
public:
    EnemyController();
    void dibujaEnemigo();
    SimpleList<pair<int, pair<int, int>>> atacar(int matriz[10][15]);
    bool disminuirVida(SimpleList<pair<int, pair<int, int>>> listaEnemigos);
    int buscarEnemy(int i, int j);
    void establecerCaracteristicas(SimpleList<GeneticEnemy> listaEnemigoGenetico);
    void crearEnemigos();
    void subirNivel();

};


#endif //LEAGUEOFGEMS_ENEMYCONTROLLER_H
