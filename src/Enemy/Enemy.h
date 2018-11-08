//
// Created by andrew on 31/10/18.
//

#ifndef LEAGUEOFGEMS_ENEMY_H
#define LEAGUEOFGEMS_ENEMY_H


#include "../App/Sprite.h"
#include "../Estructuras/SimpleList.h"

class Enemy {

private:
    ALLEGRO_BITMAP *enemy = al_load_bitmap("../img/enemy.png");
    int posX;
    int posY;
    int cont = 0;
    int vida = 7;
    int defensa = 5;
    int ataque = 1;
    int rango = 1;
public:
    void setAtaque(int ataque);

    int getAtaque() const;

    Enemy(){};
    Enemy(int x, int y);
    int getPosX() const;
    void setEnemy(ALLEGRO_BITMAP *enemy);
    int getPosY() const;
    ALLEGRO_BITMAP *getEnemy() const;
    pair<int, int> revisaAtaque(int matriz[10][15]);

    bool atacando = false;

    int getVida() const;

    void setVida(int vida);
};


#endif //LEAGUEOFGEMS_ENEMY_H
