//
// Created by andrew on 31/10/18.
//

#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include "Soldier.h"
#include "Gráficos/Sprite.h"
#include "../src/LineaVista/LineaVista.h"
#include "A*/AStarPathFinding.h"

void Soldier::caminarEste(int x, int y) {
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/running e0001.bmp");
    Sprite::dibujaPersonaje(x, y, image);
}
void Soldier::caminarOEste(int x, int y) {
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/running o0001.bmp");
    Sprite::dibujaPersonaje(x, y, image);
}
void Soldier::caminarSur(int x, int y) {
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/running s0001.bmp");
    Sprite::dibujaPersonaje(x, y, image);
}
void Soldier::caminarNorte(int x, int y) {
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/running n0001.bmp");
    Sprite::dibujaPersonaje(x, y, image);
}
void Soldier::setIJ(int i, int j, int matriz[10][15]) {

    //calcular Ruta
    AstarPathfinding AStar = AstarPathfinding();
    cout <<"( " << tempY/70 <<","<< tempX/90 <<")( "<< i <<","<< j <<")"<<endl;
    ruta2 = AStar.busquedaAStar(matriz, make_pair(tempY/70, tempX/90), make_pair(i, j));

}
Soldier::Soldier() {
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/enemy.png");
    this->tempX = 192;
    this->tempY = 644;
    xd = tempX;
    yd = tempY;
    Sprite::dibujaPersonaje(192, 644, image);
}
void Soldier::seguirRuta(){
    if(ruta2.getLenght() > 0) {
        if (this->llegue == true) {
            Pair coorTemp = ruta2.pop();
            xd = coorTemp.second * 90;
            yd = coorTemp.first * 70;
            this->llegue = false;
        }
    }
}

void Soldier::escogerPunto(int matriz[10][15], int x, int y, int xd, int yd) {
    int xf, yf;
    while(matriz[10][15]){

    }
    if(matriz[yd/70][xd/90] == 1){

    }

}


void Soldier::dibujarSoldado() {
    seguirRuta();
    if(tempX == xd && tempY == yd){
        this->llegue = true;
    }
    else if(xd > tempX && yd > tempY){
        tempX += 2;
        tempY += 2;
    }
    else if(xd < tempX && yd < tempY){
        tempX -= 2;
        tempY -= 2;
    }
    else if(xd > tempX && yd < tempY){
        tempX += 2;
        tempY -= 2;
    }
    else if(xd < tempX && yd > tempY){
        tempX -= 2;
        tempY += 2;
    }
    else if(xd > tempX){
        tempX += 2;
    }
    else if(xd < tempX){
        tempX -= 2;
    }
    else if(yd > tempY){
        tempY += 2;
    }
    else if(yd < tempY){
        tempY -= 2;
    }
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/soldier.png");
    Sprite::dibujaPersonaje(tempX, tempY, image);
}



