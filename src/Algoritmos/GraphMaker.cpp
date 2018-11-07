//
// Created by ortegajosant on 30/10/18.
//

#include <iostream>
#include "GraphMaker.h"

Graph GraphMaker::createGraph(int matrix[ROWS][COLUMNS]) {
    int row = 0;
    while (row < ROWS) {
        int column = 0;
        while (column < COLUMNS) {
            if (itsOk(row, column, matrix)) {
                graph.addVertex(row, column);
                if (itsOk(row + 1, column, matrix)) {
                    graph.addVertex(row + 1, column);
                    graph.addEdge(row, column, row + 1, column);
                }
                if (itsOk(row - 1, column, matrix)) {
                    graph.addVertex(row - 1, column);
                    graph.addEdge(row, column, row - 1, column);
                }
                if (itsOk(row, column + 1, matrix)) {
                    graph.addVertex(row, column + 1);
                    graph.addEdge(row, column, row, column + 1);
                }
                if (itsOk(row, column - 1, matrix)) {
                    graph.addVertex(row, column + 1);
                    graph.addEdge(row, column, row, column - 1);
                }
                if (itsOk(row - 1, column - 1, matrix)) {
                    graph.addVertex(row - 1, column - 1);
                    graph.addEdge(row, column, row - 1, column - 1);
                }
                if (itsOk(row - 1, column + 1, matrix)) {
                    graph.addVertex(row - 1, column + 1);
                    graph.addEdge(row, column, row - 1, column + 1);
                }
                if (itsOk(row + 1, column + 1, matrix)) {

                    graph.addVertex(row + 1, column + 1);
                    graph.addEdge(row, column, row + 1, column + 1);
                }
                if (itsOk(row + 1, column - 1, matrix)) {
                    graph.addVertex(row + 1, column - 1);
                    graph.addEdge(row, column, row + 1, column - 1);
                }
            }
            column++;
        }
        row++;
    }
    return this->graph;
}

bool GraphMaker::itsOk(int row, int column, int matriz[ROWS][COLUMNS]) {
    return row >= 0 && row < ROWS && column >= 0 && column < COLUMNS && matriz[row][column] == 1;
}



