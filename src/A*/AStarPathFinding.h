//
// Created by andrew on 26/10/18.
//

using namespace std;

#ifndef A_ASTARPATHFINDING_H
#define A_ASTARPATHFINDING_H
#include<bits/stdc++.h>

#define FILA 5
#define COLUMNA 5

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;

struct celda{
    int parent_i, parent_j;
    double f, g, h;
};

class AstarPathfinding {

public:
    bool esValido(int fila, int columna);
    bool estaDesbloqueda(int grid[][COLUMNA], int fila, int columna);
    bool esDestino(int fila, int columna, Pair destino);
    double calcularValorH(int fila, int columna, Pair destino);
    void trazarCamino(celda detallesCelda[][COLUMNA], Pair destino);
    void busquedaAStar(int grid[][COLUMNA], Pair inicio, Pair destino);

};


#endif //A_ASTARPATHFINDING_H
