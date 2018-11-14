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
    int posLista = 0;

private:
    int posX;
    int posY;
    int cont = 0;
    int vida = 0;
    int defensa = 0;
    int ataque = 0;
    int vidaMaxima = 0;
    int frecuenciaAtaque = 0;
    int fitnessData[3];

public:
    int getPosLista() const;
    void setPosLista(int posLista);
    int getFrecuenciaAtaque() const;
    void setFrecuenciaAtaque(int frecuenciaAtaque);
    void setVidaMaxima(int vidaMaxima);
    int getDefensa() const;
    void setDefensa(int defensa);
    void setAtaque(int ataque);
    int getAtaque() const;
    int getVidaMaxima() const;
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
    void moreDamage(int);
    void moreDefense();
    int *getFitnessData();
};


#endif //LEAGUEOFGEMS_ENEMY_H
