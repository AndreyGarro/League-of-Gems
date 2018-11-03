//
// Created by christian on 30/10/18.
//

#ifndef LEAGUEOFGEMS_LINEAVISTA_H
#define LEAGUEOFGEMS_LINEAVISTA_H

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string>
#include "../Estructuras/Cola.h"

struct coordenada {
    int i = 0;
    int j = 0;
    bool operator ==(coordenada a){
        if (this->i == a.i) {
            if (this->j == a.j) {
                return true;
            }
        }
        else {
            return false;
        }
    }
};

using namespace std;


class LineaVista {
private:
    coordenada destino;
    coordenada origen;



public:
    Cola<pair<int, int >> lineaVista(int i, int j, int id, int jd, int matix[10][15]);

private:

    void rodearObstaculo(coordenada *origen, coordenada destino, int matrix[10][15], Cola<pair<int, int>> *ruta);
    void buscarRuta(coordenada *ruta1, coordenada destino1, int matrix[10][15], Cola<pair<int, int>> *ruta);
    void buscarRuta(coordenada destino, coordenada origen, int matrix[10][15], Cola<pair<int, int>> *ruta);

};


#endif //LEAGUEOFGEMS_LINEAVISTA_H
