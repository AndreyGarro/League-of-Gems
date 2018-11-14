//
// Created by ortegajosant on 13/11/18.
//

#include "Dijkstra.h"

/**
 * Retorna el camino por que se moverá el soldado
 * @param currentRow Fila actual
 * @param currentColumn Columna actual
 * @param destRow Fila destino
 * @param destColumn Columna destino
 * @param matriz Matriz del mapa
 * @return Pila
 */
Pila<pair<int, int >>
Dijkstra::findPath(int currentRow, int currentColumn, int destRow, int destColumn, int (*matriz)[15]) {
    SimpleList<pair<int, int>> queue;
    SimpleList<PrevPath> path;
    queue.add(make_pair(currentRow, currentColumn));
    visitados.add(make_pair(currentRow, currentColumn));
    SimpleList<pair<int, int>> adyacentCells;
    path.add(PrevPath(currentRow, currentColumn, -1, -1));
    while (!queue.isEmpty()) {
        pair<int, int> temp = queue.getData(0);
        queue.deleteNode(0);
        if (temp.first == destRow && temp.second == destColumn) {
            return returnFinalPath(destRow, destColumn, path);
        }
        adyacentCells = getAdyacentCell(temp.first, temp.second, matriz);
        for (int i = 0; i < adyacentCells.getLength(); i++) {
            pair<int, int> tempAdy = adyacentCells.getData(i);
            if (!isVisited(tempAdy.first, tempAdy.second)) {
                visitados.add(tempAdy);
                queue.add(tempAdy);
                path.add(PrevPath(tempAdy.first, tempAdy.second, temp.first, temp.second));
            }
        }
    }

    return {};

}

/**
 * Retorna el camino exacto
 * @param destRow Fila destino
 * @param destColumn Columna destina
 * @param path Lista con los patrones
 * @return Pila
 */
Pila<pair<int, int>> Dijkstra::returnFinalPath(int destRow, int destColumn, SimpleList<PrevPath> path) {
    PrevPath tempPath;
    for (int i = 0; i < path.getLength(); i++) {
        PrevPath temp = path.getData(i);
        if (temp.row == destRow && temp.column == destColumn) {
            tempPath = temp;
            break;
        }
    }
    Pila<pair<int, int>> finalPath;
    while (true) {
        if (tempPath.prevRow == -1 && tempPath.prevColumn == -1) {
            return finalPath;
        }
        finalPath.push(make_pair(tempPath.row, tempPath.column));
        tempPath = findPrevPath(tempPath.prevRow, tempPath.prevColumn, path);
    }

}

/**
 * Obtiene las celdas adyacentes a la posición actual en la matriz
 * @param row Fila
 * @param column Columna
 * @param matriz Matriz
 * @return SimpleList
 */
SimpleList<pair<int, int>> Dijkstra::getAdyacentCell(int row, int column, int matriz[ROWS][COLUMNS]) {
    SimpleList<pair<int, int>> adyacent;
    if (itsOK(row, column, matriz)) {
        if (itsOK(row, column + 1, matriz)) {
            adyacent.add(make_pair(row, column + 1));
        }
        if (itsOK(row + 1, column, matriz)) {
            adyacent.add(make_pair(row + 1, column));
        }
        if (itsOK(row + 1, column + 1, matriz)) {
            adyacent.add(make_pair(row + 1, column + 1));
        }
        if (itsOK(row - 1, column, matriz)) {
            adyacent.add(make_pair(row - 1, column));
        }
        if (itsOK(row, column - 1, matriz)) {
            adyacent.add(make_pair(row, column - 1));
        }
        if (itsOK(row - 1, column - 1, matriz)) {
            adyacent.add(make_pair(row - 1, column - 1));
        }
        if (itsOK(row + 1, column - 1, matriz)) {
            adyacent.add(make_pair(row + 1, column - 1));
        }
        if (itsOK(row - 1, column + 1, matriz)) {
            adyacent.add(make_pair(row - 1, column + 1));
        }
    }
    return adyacent;
}

/**
 * Verifica que la posición sea válida
 * @param row Fila
 * @param column COlumna
 * @param matriz Matriz
 * @return bool
 */
bool Dijkstra::itsOK(int row, int column, int matriz[ROWS][COLUMNS]) {
    return row >= 0 && row < ROWS && column >= 0 && column < COLUMNS && matriz[row][column] == 1;
}

/**
 * Verifica que la posición no haya sido visitada
 * @param row Fila
 * @param column Columna
 * @return bool
 */
bool Dijkstra::isVisited(int row, int column) {
    for (int i = 0; i < visitados.getLength(); i++) {
        pair<int, int> temp = visitados.getData(i);
        if (temp.first == row && temp.second == column) {
            return true;
        }
    }
    return false;
}

/**
 * Retorna la posición anterior en el patron
 * @param row Fila
 * @param column Columna
 * @param path Patron
 * @return PrevPath
 */
PrevPath Dijkstra::findPrevPath(int row, int column, SimpleList<PrevPath> path) {
    for (int i = 0; i < path.getLength(); i++) {
        PrevPath temp = path.getData(i);
        if (temp.row == row && temp.column == column) {
            return temp;
        }
    }
    return {};
}