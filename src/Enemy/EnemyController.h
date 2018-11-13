//
// Created by andrew on 01/11/18.
//

#ifndef LEAGUEOFGEMS_ENEMYCONTROLLER_H
#define LEAGUEOFGEMS_ENEMYCONTROLLER_H


#include "../Estructuras/SimpleList.h"
#include "Enemy.h"

class EnemyController {

private:
    SimpleList<Enemy> listaEnemigos;
    int contAtaque = 0;

public:
    EnemyController();
    void dibujaEnemigo();
    SimpleList<pair<int, pair<int, int>>> atacar(int matriz[10][15]);
    void disminuirVida(SimpleList<pair<int, pair<int, int>>> listaEnemigos);
    int buscarEnemy(int i, int j);

};


#endif //LEAGUEOFGEMS_ENEMYCONTROLLER_H
