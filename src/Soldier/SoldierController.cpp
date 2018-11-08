//
// Created by andrew on 30/10/18.
//

#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include "SoldierController.h"
#include <string>
#include <allegro5/allegro_image.h>

using namespace std;
/**
 * Insertar nuevas posiciones hacia donde se deben dirigir los soldados
 * @param i Fila
 * @param j Columna
 * @param matriz
 */
void SoldierController::setIJ(int i, int j, int matriz[10][15]) {
    if(this->i != i or this->j != j) {
        this->i = i;
        this->j = j;
        for (int k = 0; k < listSoldier.getLength(); ++k) {
            this->listSoldier.getData(k)->setIJ(i,j, matriz);
        }
    }
}
/**
 * Dibujar los soldados en las nuevas posiciones
 */
void SoldierController::dibujaJugador() {
    for (int k = 0; k < listSoldier.getLength(); ++k) {
        listSoldier.getData(k)->dibujarSoldado();
    }
}
/**
 * Costructor
 */
SoldierController::SoldierController() {
    listSoldier.add(Soldier(0,560));
    listSoldier.add(Soldier(90,560));
    listSoldier.add(Soldier(180,560));
    listSoldier.add(Soldier(0,620));
    listSoldier.add(Soldier(90,620));
    listSoldier.add(Soldier(180,620));
}
/**
 * Verfica si hay enemigos cerca de los soldados a los que se pueden atacar
 * @param matriz
 * @return  Lista <pair<int dano, pair<int i, int j>>>
 */
SimpleList<pair<int, pair<int, int >>> SoldierController::atacar(int matriz[10][15]) {
    SimpleList< pair<int, pair<int, int>> > atacados = SimpleList<pair<int, pair<int, int >>>();
    for (int k = 0; k < listSoldier.getLength(); ++k) {
        pair<int, int> temp = listSoldier.getData(k)->atacar(matriz);
        if (temp.first != -1 && temp.second != -1) {
            atacados.add(make_pair(1, temp));
        }
    }
    return atacados;
}


