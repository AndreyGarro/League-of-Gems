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
            this->listSoldier.getData(k)->setIJ(i,j, matriz,nivel);
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
 * Constructor
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
    if(this->tiempo > 90) {
        this->tiempo = 0;
        this->fast = 1;
    }
    this->tiempo++;
    return atacados;
}
/**
 * Revisa la lista con los soldados atacados por los enemigos
 *
 * @param listaAtacados
 */
void SoldierController::disminuirVida(SimpleList<pair<int, pair<int, int>>> listaAtacados) {
    if(!listaAtacados.isEmpty()){
        for (int k = 0; k < listaAtacados.getLength(); ++k) {
            int numS = buscarSoldado(listaAtacados.getData(k)->second.first, listaAtacados.getData(k)->second.second);
            if(numS != -1){
                listSoldier.getData(numS)->disminuirVida(abs(listaAtacados.getData(k)->first - listSoldier.getData(numS)->getDefensa()));
                if(listSoldier.getData(numS)->getVida() <= 0){
                    listSoldier.deleteNode(numS);
                }
            }
        }
    }

}
/**
 * Complementario para buscar el soldado atacado por los enemigos
 *
 * @param i Fila en la que se ataco
 * @param j Columna en la que se ataco
 * @return Numero de la lista donde esta el soldado que se ataco
 */
int SoldierController::buscarSoldado(int i, int j) {
    for (int k = 0; k < listSoldier.getLength(); ++k) {
        if(listSoldier.getData(k)->getYd()/70 == i && listSoldier.getData(k)->getXd()/90 == j){
            return k;
        }
    }
    return -1;
}
/**
 * Valida cual poder selecciono de la barra de ataques
 * @param i numero de fila
 * @param j numero de columna
 */
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
        } else if (j == 3 && numCuras !=0) {
            for (int k = 0; k < listSoldier.getLength(); ++k) {
                listSoldier.getData(k)->setVida(listSoldier.getData(k)->getVidaMaxima());
            }
//            this->numCuras--;
            cout << "Se eligio curar"<<endl;
        } else if (j == 4) {

        }
    }

}
/**
 * Elimina la lista de soldados y crea una nueva para el siguiente nivel
 * Aumenta los poderes.
 *
 * @param nivel
 */
void SoldierController::subirNivel(int nivel) {
    while (!listSoldier.isEmpty()){
        listSoldier.deleteNode(0);
        cout << "eliminado" << endl;
    }
    this->listSoldier.add(Soldier(0,490));
    this->listSoldier.add(Soldier(90,490));
    this->listSoldier.add(Soldier(180,490));
    this->listSoldier.add(Soldier(0,560));
    this->listSoldier.add(Soldier(90,560));
    this->listSoldier.add(Soldier(180,560));
    this->tiempo = 30 * nivel;
    this->numCuras = 3 + nivel;
}
