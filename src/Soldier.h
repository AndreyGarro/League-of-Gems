//
// Created by andrew on 31/10/18.
//

#ifndef LEAGUEOFGEMS_SOLDIER_H
#define LEAGUEOFGEMS_SOLDIER_H

#include "../src/Estructuras/Cola.h"
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>

class Soldier {
private:
    int vida = 7;
    int xd, yd, tempX, tempY;
    bool llegue = false;

    Cola<int> *colaX = new Cola<int >;
    Cola<int> *colaY = new Cola<int >;

public:
    Soldier();
    void setIJ(int i, int j, int matriz[15][27]);
    void caminarEste(int , int);
    void caminarOEste(int , int);
    void caminarSur(int , int);
    void caminarNorte(int , int);
    void dibujarSoldado();


};
#endif //LEAGUEOFGEMS_SOLDIER_H
