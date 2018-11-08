//
// Created by andrew on 30/10/18.
//

#ifndef LEAGUEOFGEMS_PLAYER_H
#define LEAGUEOFGEMS_PLAYER_H

#include <allegro5/allegro_primitives.h>
#include "Soldier.h"
#include "../Estructuras/SimpleList.h"

/**
 * Clase jugardor controla todos los soldados que se muestran
 */
class SoldierController {
private:
    int vida, fast = 1, dano = 1, tiempo = 30;
    int i,j;
    SimpleList<Soldier> listSoldier =  SimpleList<Soldier>();

public:
    SoldierController();
    void setIJ(int i, int j, int matriz[10][15]);
    void dibujaJugador();
    SimpleList<pair<int, pair<int ,int >>> atacar (int matriz [10][15]);
    void disminuirVida(SimpleList<pair<int, pair<int, int>>> listaAtacados );
    int buscarSoldado(int i, int j);
    void escogerAtaque(int i, int j);

};


#endif //LEAGUEOFGEMS_PLAYER_H
