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
    Pair posff = escogerPunto(matriz,i,j);
//   Pair posff = make_pair(i,j);
    AstarPathfinding AStar = AstarPathfinding();
    ruta2 = AStar.busquedaAStar(matriz, make_pair(yd/70, xd/90), posff);
    Application::matriz[posff.first][posff.second] = 4;



}
void Soldier::seguirRuta(){
    if(ruta2.getLenght() > 0) {
        if (this->llegue) {
            Pair coorTemp = ruta2.pop();
            xd = coorTemp.second * 90;
            yd = coorTemp.first * 70;
            this->llegue = false;
        }
    }else{
        flagAttack = true;
    }
}

Pair Soldier::escogerPunto(int matriz[10][15], int id, int jd) {
    if(matriz[id][jd] == 1){
        return make_pair(id,jd);
    }
    int a=3, b=3;
    while(true){
        cout<<"0"<< endl;
        id -=1;
        jd -=1;
        try {
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    if ((id + i) < 0) {
                        cout<<"1"<< endl;
                        id = 0;
                    }
                    if ((id + i )> 9) {
                        cout<<"2"<< endl;
                        id -= abs((i + 1));
                    }
                    if ((jd + j) < 0) {
                        cout<<"3"<< endl;
                        jd = 0;
                    }
                    if ((jd + j) > 14) {
                        cout<<"4"<< endl;
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

void Soldier::dibujarSoldado() {
    seguirRuta();

    ALLEGRO_BITMAP *image;
    image = al_load_bitmap("../img/soldier.png");

    if(tempX == xd && tempY == yd){
        this->llegue = true;
        if(atacar(yd/70, xd/90, Application::matriz) && flagAttack) {
            image = al_load_bitmap("../img/enemy.png");
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

bool Soldier::atacar(int i, int j, int matriz[10][15]) {
    i--; j--;
    for (int k = 0; k < 3; ++k) {
        for (int l = 0; l < 3; ++l) {
            if(matriz[abs(i+k)][abs(j+l)] == 2){
                return true;
            }
        }
    }
    return false;
}





