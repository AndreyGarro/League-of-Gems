//
// Created by ortegajosant on 31/10/18.
//

#ifndef ALGORITMOS_PRIM_H
#define ALGORITMOS_PRIM_H

#include <vector>
#include "../Estructuras/SimpleList.h"
#include <climits>
#include "Graph.h"
#include "../Estructuras/Pila.h"
#include<bits/stdc++.h>

using namespace std;

struct Path {
    Path() {

    }

    Path(int row, int column, int prevRow, int prevColumn) {
        this->row = row;
        this->column = column;
        this->prevRow = prevRow;
        this->prevColumn = prevColumn;
    }

    int row, column, prevRow, prevColumn;
};

class Prim {
private:
    Graph graph;
    SimpleList<Vertex> visited;

    Pila<pair<int, int>> queueGenerator(int row, int column, int destRow, int destColumn, SimpleList<Path> cola);

    bool isVisited(Vertex vertex);

    Path findPrevPath(int prevRow, int prevColumn, SimpleList<Path> path);

public:
    Pila<pair<int, int>> primAlgorithm(int currentRow, int currentColumn, int destRow, int destColumn, Graph graph);
};


#endif //ALGORITMOS_PRIM_H
