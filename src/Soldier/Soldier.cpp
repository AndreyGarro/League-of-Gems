//
// Created by andrew on 31/10/18.
//

#include <allegro5/allegro.h>
#include "Soldier.h"
#include "../App/Sprite.h"
#include "../LineaVista/LineaVista.h"
#include "../Algoritmos/AStarPathFinding.h"
/**
 * Construtuor con parametros
 * @param x posicion horizontal donde se dibujara el soldado la primera vez
 * @param y posicion vertical donde se dibujara el soldado la primera vez
 */
Soldier::Soldier(int x , int y) {
    image = al_load_bitmap("../img/soldier.png");
    this->tempX = x;
    this->tempY = y;
    xd = tempX;
    yd = tempY;
    Sprite::dibujaPersonaje(192, 644, image, 3);
}
/**
 * Constructor
 */
Soldier::Soldier() {}

/**
 * Insertar posiciones a cada soldado
 * @param i
 * @param j
 * @param matriz
 */
void Soldier::setIJ(int i, int j, int matriz[10][15], int nivel) {
    if (nivel == 0) {

    }
    else if (nivel == 1) {
        Pair posff = escogerPunto(matriz, i, j);
        AstarPathfinding AStar = AstarPathfinding();
        ruta2 = AStar.busquedaAStar(matriz, make_pair(yd / 70, xd / 90), posff);
        Application::matriz[posff.first][posff.second] = 4;
    }
    else if(nivel == 2){
        
    }
    else if(nivel == 3){
        
    }
    else if (nivel == 4){
        
    }
}
/**
 * Toma la ruta punto a punto dada por el algoritmo de busquedad
 */
void Soldier::seguirRuta(){
    if(ruta2.getLenght() > 0) {
        if (this->llegue) {
            Pair coorTemp = ruta2.pop();
            xd = coorTemp.second * 90;
            yd = coorTemp.first * 70;
            this->llegue = false;
        }
    }
}

/**
 * Escoge un punto libre los mas cercano al punto seleccionado por el jugador
 * @param matriz
 * @param id  Punto de destino
 * @param jd Punto de destino
 * @return Punto escogido
 */
Pair Soldier::escogerPunto(int matriz[10][15], int id, int jd) {
    if(matriz[id][jd] == 1){
        return make_pair(id,jd);
    }
    int a=3, b=3;
    while(true){
        id -=1;
        jd -=1;
        try {
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    if ((id + i) < 0) {
                        id = 0;
                    }
                    if ((id + i )> 9) {
                        id -= abs((i + 1));
                    }
                    if ((jd + j) < 0) {
                        jd = 0;
                    }
                    if ((jd + j) > 14) {
                        jd = abs(jd - (j + 1));
                    }
                    if (matriz[abs(id + i)][abs(jd + j)] == 1) {
                        return make_pair(id + i, jd + j);
                    }
                }
            }
        }
        catch(...) { }
        a++,b++;
    }
}
/**
 * Realiza el efecto caminar de punto a punto dados por el algoritmo de busqueda
 */
void Soldier::dibujarSoldado() {
    seguirRuta();
    image = al_load_bitmap("../img/soldier.png");

    if(tempX == xd && tempY == yd){
        this->llegue = true;
        if(flagAttack){
            image = al_load_bitmap("../img/soldierAttack.png");
        }
    }
    else if(xd > tempX && yd > tempY){
        tempX += 5;
        tempY += 5;
    }
    else if(xd < tempX && yd < tempY){
        tempX -= 5;
        tempY -= 5;
    }
    else if(xd > tempX && yd < tempY){
        tempX += 5;
        tempY -= 5;
    }
    else if(xd < tempX && yd > tempY){
        tempX -= 5;
        tempY += 5;
    }
    else if(xd > tempX){
        tempX += 5;
    }
    else if(xd < tempX){
        tempX -= 5;
    }
    else if(yd > tempY){
        tempY += 5;
    }
    else if(yd < tempY){
        tempY -= 5;
    }
    Sprite::dibujaPersonaje(tempX, tempY, image, 3);
    Application::matriz[yd/70][xd/90] = 3;
}
/**
 * Revida si es posible atacar a un enemgio dentro del rango
 * @param matriz
 * @return Posicion a la que ataco
 */
pair<int, int> Soldier::atacar(int matriz[10][15], int fast) {
    if (this->freAtaque > 30){
        this->freAtaque = 0;
    }
    this->freAtaque++;
    if(this->freAtaque <= fast) {
        int i = (yd / 70) - 1, j = (xd / 90) - 1;
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                if (matriz[abs(i + k)][abs(j + l)] == 2) {
                    flagAttack = true;
                    return make_pair(abs(i + k), abs(j + l));
                }
            }
        }
    }
    if(this->freAtaque > 10){
        flagAttack = false;
    }
    return make_pair(-1,-1);
}

int Soldier::getXd() const {
    return xd;
}

int Soldier::getYd() const {
    return yd;
}

void Soldier::disminuirVida(int vida) {
    this->vida -= vida;
}

int Soldier::getVida() const {
    return vida;
}





