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
void SoldierController::setIJ(int i, int j, int matriz[10][15], int nivel) {
    if(this->i != i or this->j != j) {
        this->i = i;
        this->j = j;
        for (int k = 0; k < listSoldier.getLength(); ++k) {
            this->listSoldier.getData(k)->setIJ(i,j, matriz,1);
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
    listSoldier.add(Soldier(0,490));
    listSoldier.add(Soldier(90,490));
    listSoldier.add(Soldier(180,490));
    listSoldier.add(Soldier(0,560));
    listSoldier.add(Soldier(90,560));
    listSoldier.add(Soldier(180,560));
}
/**
 * Verfica si hay enemigos cerca de los soldados a los que se pueden atacar
 * @param matriz
 * @return  Lista <pair<int dano, pair<int i, int j>>>
 */
SimpleList<pair<int, pair<int, int >>> SoldierController::atacar(int matriz[10][15]) {
    SimpleList< pair<int, pair<int, int>> > atacados = SimpleList<pair<int, pair<int, int >>>();
    for (int k = 0; k < listSoldier.getLength(); ++k) {
        pair<int, int> temp = listSoldier.getData(k)->atacar(matriz,this->fast);
        if (temp.first != -1 && temp.second != -1) {
            atacados.add(make_pair(listSoldier.getData(k)->getAtaque(), temp));
        }
    }
//    for (int l = 0; l < atacados.getLength(); ++l) {
//        cout << atacados.getData(l)->second.first<<" "<< atacados.getData(l)->second.second<<endl;
//    }
    if(this->tiempo > 90) {
//        cout << "Tiempo de poder agotado"<< endl;
        this->tiempo = 0;
        this->fast = 1;
    }
    this->tiempo++;
    return atacados;
}

void SoldierController::disminuirVida(SimpleList<pair<int, pair<int, int>>> listaAtacados) {
    if(!listaAtacados.isEmpty()){
        for (int k = 0; k < listaAtacados.getLength(); ++k) {
            int numS = buscarSoldado(listaAtacados.getData(k)->second.first, listaAtacados.getData(k)->second.second);
            if(numS != -1){
                listSoldier.getData(numS)->disminuirVida(listaAtacados.getData(k)->first - listSoldier.getData(numS)->getDefensa());
                if(listSoldier.getData(numS)->getVida() <= 0){
                    listSoldier.deleteNode(numS);
                }
            }
        }
    }

}
int SoldierController::buscarSoldado(int i, int j) {
    for (int k = 0; k < listSoldier.getLength(); ++k) {
        if(listSoldier.getData(k)->getYd()/70 == i && listSoldier.getData(k)->getXd()/90 == j){
            return k;
        }
    }
    return -1;
}

void SoldierController::escogerAtaque(int i, int j) {
    if(tiempo > 90) {

    }
    else{
        if (j == 1) {
            for (int k = 0; k < listSoldier.getLength(); ++k) {
                listSoldier.getData(k)->setAtaque(60);
            }
            cout << "Se eligio daño"<<endl;
        } else if (j == 2) {
            for (int k = 0; k < listSoldier.getLength(); ++k) {
                listSoldier.getData(k)->setDefensa(25);
            }
            cout << "Se eligio defensa"<<endl;
        } else if (j == 3) {
            for (int k = 0; k < listSoldier.getLength(); ++k) {
                listSoldier.getData(k)->setVida(250);
            }
            cout << "Se eligio curar"<<endl;
        } else if (j == 4) {

        }
    }

}



