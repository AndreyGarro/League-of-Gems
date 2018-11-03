//
// Created by andrew on 01/11/18.
//

#ifndef LEAGUEOFGEMS_ENEMYCONTROLLER_H
#define LEAGUEOFGEMS_ENEMYCONTROLLER_H


#include "../Estructuras/SimpleList.h"
#include "../Enemy.h"

class EnemyController {

private:
    SimpleList<Enemy> listaEnemigos;

public:
    EnemyController();
    void dibujaEnemigo();
    void atacar(int matriz[10][15]);
};


#endif //LEAGUEOFGEMS_ENEMYCONTROLLER_H
