//
// Created by ortegajosant on 30/10/18.
//

#ifndef ALGORITMOS_KRUSKAL_H
#define ALGORITMOS_KRUSKAL_H

#include <vector>
#include "../Estructuras/Pila.h"
#include "Graph.h"

using namespace std;

struct EdgePath {
    EdgePath() {
    }

    EdgePath(int row, int column, int prevRow, int prevColumn, int weight) {
        this->row = row;
        this->column = column;
        this->prevRow = prevRow;
        this->prevColumn = prevColumn;
        this->weight = weight;
    }

    EdgePath(int row, int column) {
        this->row = row;
        this->column = column;
    }

    int row, column, prevRow, prevColumn, weight;

};

class Kruskal {
private:
    SimpleList<EdgePath> makeEdges(Graph graph, int currentRow, int currentColumn);

    EdgePath findePrevEdge(int row, int column, SimpleList<EdgePath> edges);

    bool isVisited(int row, int column, SimpleList<EdgePath> visited);

public:
    Pila<pair<int, int>> kruskalAlgorithm(int currentRow, int currentColumn, int destRow, int destColumn, Graph graph);

};


#endif //ALGORITMOS_KRUSKAL_H
