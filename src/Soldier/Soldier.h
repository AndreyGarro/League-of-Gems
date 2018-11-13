//
// Created by andrew on 31/10/18.
//

#ifndef LEAGUEOFGEMS_SOLDIER_H
#define LEAGUEOFGEMS_SOLDIER_H

#include "../Estructuras/Cola.h"
#include "../Estructuras/Pila.h"
#include "../Algoritmos/AStarPathFinding.h"
#include "../Algoritmos/Graph.h"
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include <utility>

using namespace std;
/**
 * Clase del soldado individual, controla cada soldado independientemente de los demas
 */
class Soldier {
private:
    int vida = 250;
    int defensa = 10;
    int ataque = 20;
    int vidaMaxima = 250;
    int xd, yd, tempX, tempY;
    bool llegue = false;
    bool flagAttack = false;
    int freAtaque = 0;
    ALLEGRO_BITMAP *image;
    Graph graph;
    bool graphActivo = false;
    Cola<Pair> ruta = Cola<Pair>();
    Pila<Pair> ruta2 = Pila<Pair>();

public:
    int getDefensa() const;
    void setDefensa(int defensa);
    int getAtaque() const;
    void setAtaque(int ataque);
    int getVidaMaxima() const;
    void setVida(int vida);
    int getVida() const;
    int getXd() const;
    int getYd() const;
    Soldier(int x, int y);
    Soldier();
    void setIJ(int i, int j, int matriz[10][15], int nivel);
    void dibujarSoldado();
    void seguirRuta();
    Pair escogerPunto(int matriz[10][15], int xd, int yd);
    pair<int, int > atacar(int matriz [10][15], int fast);
    void disminuirVida(int vida);
};
#endif //LEAGUEOFGEMS_SOLDIER_H
