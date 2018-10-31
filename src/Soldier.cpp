//
// Created by andrew on 31/10/18.
//

#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include "Soldier.h"
#include "Gráficos/Sprite.h"
#include "../src/LineaVista/LineaVista.h"

void Soldier::caminarEste(int x, int y) {
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/running e0001.bmp");
    Sprite::dibujaSoldado(x, y, image);
}
void Soldier::caminarOEste(int x, int y) {
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/running o0001.bmp");
    Sprite::dibujaSoldado(x, y, image);
}
void Soldier::caminarSur(int x, int y) {
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/running s0001.bmp");
    Sprite::dibujaSoldado(x, y, image);
}
void Soldier::caminarNorte(int x, int y) {
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/running n0001.bmp");
    Sprite::dibujaSoldado(x, y, image);
}
void Soldier::setIJ(int i, int j, int matriz[15][27]) {
    this->xd = j*48;
    this->yd = i*46;

    // calcular Ruta
    //LineaVista ruta1 = LineaVista();
    //ruta1.lineaVista(tempX, tempY,i,j,colaX, colaY,matriz);
    //std::cout <<colaX->size() << std::endl;
}
Soldier::Soldier() {
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/running e0001.bmp");
    Sprite::dibujaSoldado(192, 644, image);
    this->tempX = 192;
    this->tempY = 644;
    xd = tempX;
    yd = tempY;
}

void Soldier::dibujarSoldado() {
    if(tempX == xd && tempY == yd){

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
    ALLEGRO_BITMAP *image = al_load_bitmap("../img/running e0001.bmp");
    Sprite::dibujaSoldado(tempX, tempY, image);
}


