//
// Created by ortegajosant on 30/10/18.
//

#ifndef ALGORITMOS_GRAPHMAKER_H
#define ALGORITMOS_GRAPHMAKER_H

#include "Graph.h"

#define ROWS 4
#define COLUMNS 4

class GraphMaker {
private:
    Graph graph;

public:
    Graph createGraph(int matrix[ROWS][COLUMNS] );

    bool itsOk(int row, int column, int matriz[ROWS][COLUMNS]);

};


#endif //ALGORITMOS_GRAPHMAKER_H
