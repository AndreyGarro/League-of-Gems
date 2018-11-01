//
// Created by andrew on 31/10/18.
//

#ifndef LEAGUEOFGEMS_SOLDIER_H
#define LEAGUEOFGEMS_SOLDIER_H

#include "../src/Estructuras/Cola.h"
#include "Estructuras/Pila.h"
#include "A*/AStarPathFinding.h"
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include <utility>

using namespace std;
class Soldier {
private:
    int vida = 7;
    int xd, yd, tempX, tempY;
    bool llegue = false;

    Cola<Pair> ruta = Cola<Pair>();
    Pila<Pair> ruta2 = Pila<Pair>();

public:
    Soldier(int x, int y);
    Soldier();
    void setIJ(int i, int j, int matriz[10][15]);
    void dibujarSoldado();
    void seguirRuta();
    Pair escogerPunto(int matriz[10][15], int xd, int yd);


};
#endif //LEAGUEOFGEMS_SOLDIER_H
