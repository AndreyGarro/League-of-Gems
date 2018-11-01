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
    Soldier s1 = Soldier(96,500);
    Soldier s2 = Soldier(2*48, 600);
    Soldier s3 = Soldier(3*48, 600);
    Soldier s4 = Soldier(4*48, 600);
    Soldier s5 = Soldier(4*48, 600);
    Soldier s6 = Soldier(48, 600);

public:
    Player();
    void setIJ(int i, int j, int matriz[10][15]);
    void dibujaJugador();

private:

};


#endif //LEAGUEOFGEMS_PLAYER_H
