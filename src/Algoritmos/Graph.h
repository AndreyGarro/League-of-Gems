//
// Created by ortegajosant on 30/10/18.
//

#ifndef ALGORITMOS_GRAPH_H
#define ALGORITMOS_GRAPH_H

#include "../Estructuras/SimpleList.h"

struct Vertex {
    Vertex() = default;

    Vertex(int row, int column, int weight) {
        this->weight = weight;
        this->row = row;
        this->column = column;
        edge = new SimpleList<Vertex>();
    }

    int row, column, weight = 0;
    SimpleList<Vertex> *edge;

};

class Graph {
private:
    SimpleList<Vertex> vertexs;
    SimpleList<SimpleList<int>> adjMatrix;
    int number = 0;
public:
    bool addVertex(int row, int column);

    bool addEdge(int row, int column, int adyRow, int adyColumn);

    int findByCoord(int row, int column);

    Vertex getVertex(int row, int column);

    void printGraph();

    const SimpleList<Vertex> &getVertexs() const;

    int getNumber() const;

};

#endif //ALGORITMOS_GRAPH_H
