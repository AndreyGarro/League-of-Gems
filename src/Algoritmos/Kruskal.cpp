#include <iostream>
#include "Kruskal.h"

/**
 * Algoritmo de busqueda Prim, devuelve la ruta más corta mediante un arbol de mínima expresión
 * @param currentRow Posición actual del objeto en la fila
 * @param currentColumn Posición actual del objeto en la columna
 * @param destRow Posición destino en la fila
 * @param destColumn Posición destino en la columna
 * @param graph Grafo de la matriz del mapa
 * @return Pila<pain>
 */
Pila<pair<int, int>>
Kruskal::kruskalAlgorithm(int currentRow, int currentColumn, int destRow, int destColumn, Graph graph) {
    if (graph.getVertex(destRow, destColumn).row == -1 && graph.getVertex(destRow, destColumn).column == -1) {
        return {};
    }
    Pila<pair<int, int>> stackPath;
    SimpleList<EdgePath> edges = this->makeEdges(graph, currentRow, currentColumn);
    EdgePath temp = findePrevEdge(destRow, destColumn, edges);
    while (!edges.isEmpty()) {
        if (temp.row == currentRow && temp.column == currentColumn) {
            cout<<"Kruskal encontrado"<<endl;
            return stackPath;
        }
        stackPath.push(make_pair(temp.row, temp.column));
        temp = findePrevEdge(temp.prevRow, temp.prevColumn, edges);
    }
    return {};
}

/**
 * Crea las relaciones de aristas entre los nodos
 * @param graph Grafo de la matriz
 * @param currentRow Fila de salida
 * @param currentColumn Columna de salida
 * @return Lista con las aristas
 */
SimpleList<EdgePath> Kruskal::makeEdges(Graph graph, int currentRow, int currentColumn) {
    SimpleList<EdgePath> edges;
    SimpleList<EdgePath> visited;
    Vertex currentV = graph.getVertex(currentRow, currentColumn);
    Vertex tempV;
    edges.add(EdgePath{currentV.row, currentV.column, -1, -1, 0});
    visited.add(EdgePath{currentV.row, currentV.column});
    SimpleList<Vertex> queue;
    queue.add(currentV);
    while (!queue.isEmpty()) {
        currentV = *queue.getData(0);
        queue.deleteNode(0);
        for (int j = 0; j < currentV.edge->getLength(); j++) {
            tempV = *currentV.edge->getData(j);
            if (!isVisited(tempV.row, tempV.column, visited)) {
                queue.add(tempV);
                visited.add(EdgePath{tempV.row, tempV.column});
                edges.add(EdgePath{tempV.row, tempV.column, currentV.row, currentV.column, currentV.weight + 1});
            }
        }
    }
    return edges;
}

/**
 * Busca la el anterior del path
 * @param row Fila anterior
 * @param column Columna Anterior
 * @param edges Lista con las aristas
 * @return EdgePAth
 */
EdgePath Kruskal::findePrevEdge(int row, int column, SimpleList<EdgePath> edges) {
    for (int i = 0; i < edges.getLength(); i++) {
        if (edges.getData(i)->row == row && edges.getData(i)->column == column) {
            EdgePath temp = *edges.getData(i);
            edges.deleteNode(i);
            return temp;
        }
    }
}

/**
 * Verifica que la arista no exista
 * @param row fila
 * @param column columna
 * @param visited lista de visitados
 * @return bool
 */
bool Kruskal::isVisited(int row, int column, SimpleList<EdgePath> visited) {
    for (int i = 0; i < visited.getLength(); i++) {
        if (visited.getData(i)->row == row && visited.getData(i)->column == column) {
            return true;
        }
    }
    return false;
}

