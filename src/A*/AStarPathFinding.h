//
// Created by andrew on 26/10/18.
//

using namespace std;

#ifndef A_ASTARPATHFINDING_H
#define A_ASTARPATHFINDING_H
#include<bits/stdc++.h>
#include "../Estructuras/Pila.h"

#define FILA 10
#define COLUMNA 15

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
    Pila<Pair> trazarCamino(celda detallesCelda[][COLUMNA], Pair destino);
    Pila<Pair> busquedaAStar(int grid[][COLUMNA], Pair inicio, Pair destino);

};


#endif //A_ASTARPATHFINDING_H
