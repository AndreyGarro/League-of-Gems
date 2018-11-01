//
// Created by andrew on 30/10/18.
//

#ifndef LEAGUEOFGEMS_PLAYER_H
#define LEAGUEOFGEMS_PLAYER_H

#include <allegro5/allegro_primitives.h>
#include "../Soldier.h"


class Player {
private:
    int vida;
    int i,j;
    Soldier s1;

public:
    Player();
    void setIJ(int i, int j, int matriz[10][15]);
    void dibujaJugador();

private:

};


#endif //LEAGUEOFGEMS_PLAYER_H
