//
// Created by andrew on 31/10/18.
//

#include <allegro5/allegro.h>
#include "Soldier.h"
#include "Gráficos/Sprite.h"
#include "../src/LineaVista/LineaVista.h"
#include "A*/AStarPathFinding.h"

Soldier::Soldier(int x , int y) {
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/enemy.png");
    this->tempX = x;
    this->tempY = y;
    xd = tempX;
    yd = tempY;
    Sprite::dibujaPersonaje(192, 644, image, 3);
}
Soldier::Soldier() {}

void Soldier::setIJ(int i, int j, int matriz[10][15]) {

    //calcular Ruta
//    Pair posff = escogerPunto(matriz,i,j);
    Pair posff = make_pair(i,j);
    AstarPathfinding AStar = AstarPathfinding();
    ruta2 = AStar.busquedaAStar(matriz, make_pair(tempY/70, tempX/90), posff);
//    Application::matriz[posff.first][posff.second] = 4;


}
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

Pair Soldier::escogerPunto(int matriz[10][15], int id, int jd) {
    srand(static_cast<unsigned int>(time(0)));
    while(true){
        int iff = (id +1) , jff = jd;
        if(matriz[id][jd] == 1){
            return make_pair(id, jd);
        }
        else {
            if(matriz[iff][jff] == 1){
                return make_pair(iff, jff);
            }
            id = iff; jd = jff;
        }
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
    Sprite::dibujaPersonaje(tempX, tempY, image, 3);
    Application::matriz[yd/70][xd/90] = 3;


}



