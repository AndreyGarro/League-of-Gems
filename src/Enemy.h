//
// Created by andrew on 31/10/18.
//

#ifndef LEAGUEOFGEMS_ENEMY_H
#define LEAGUEOFGEMS_ENEMY_H


#include "Gráficos/Sprite.h"
#include "Estructuras/SimpleList.h"

class Enemy {

private:
    ALLEGRO_BITMAP *enemy;
    int posX;
    int posY;
    int vida;
public:
    int getPosX() const;
    int getPosY() const;

    ALLEGRO_BITMAP *getEnemy() const;

private:
    int defensa = 5;
    int ataque = 5;
    int rango = 1;

public:
    Enemy(){};
    Enemy(int x, int y);
//    void atacar(int matriz[][]);

};


#endif //LEAGUEOFGEMS_ENEMY_H
