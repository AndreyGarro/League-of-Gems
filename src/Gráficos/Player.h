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
    Soldier s1 = Soldier(0,560);
    Soldier s2 = Soldier(90,560);
    Soldier s3 = Soldier(180,560);
    Soldier s4 = Soldier(0,620);
    Soldier s5 = Soldier(90,620);
    Soldier s6 = Soldier(180,620);


public:
    Player();
    void setIJ(int i, int j, int matriz[10][15]);
    void dibujaJugador();

};


#endif //LEAGUEOFGEMS_PLAYER_H
