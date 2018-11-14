//
// Created by ortegajosant on 13/11/18.
//

#ifndef ALGORITMOS_DIJKSTRA_H
#define ALGORITMOS_DIJKSTRA_H


#include "../Estructuras/SimpleList.h"
#include "../Estructuras/Pila.h"
#include <iostream>


#define ROWS 10
#define COLUMNS 15

using namespace std;

struct PrevPath {
    PrevPath(int row, int column, int prevRow, int prevColumn) {
        this->row = row;
        this->column = column;
        this->prevRow = prevRow;
        this->prevColumn = prevColumn;
    }

    PrevPath() {
        this->row = -1;
        this->column = -1;
        this->prevRow = -1;
        this->prevColumn = -1;
    }
    int row, column, prevRow, prevColumn;
};

class Dijkstra {
private:
    SimpleList<pair<int, int>> getAdyacentCell(int row, int column, int matriz[ROWS][COLUMNS]);
    bool itsOK(int row, int column, int matriz[ROWS][COLUMNS]);
    SimpleList<pair<int, int>> visitados;
    bool isVisited(int row, int column);
    Pila<pair<int, int>> returnFinalPath(int destRow, int destColumn, SimpleList<PrevPath> path);
    PrevPath findPrevPath(int row, int column, SimpleList<PrevPath> path);
public:
    Pila<pair<int, int >> findPath(int currentRow, int currentColumn, int destRow, int destColumn, int matriz[ROWS][COLUMNS]);
};


#endif //ALGORITMOS_DIJKSTRA_H
