//
// Created by christian on 30/10/18.
//

#include "LineaVista.h"

/**
 * Metodo para buscar rutas por Linea-Vista
 * @param x posicion de origen en x
 * @param y posicion de origen en y
 * @param xd  posicion de destino en x
 * @param yd  posicion de destino en y
 * @param X  --- Cola para devolver la ruta
 * @param Y ---//
 * @param matrix Matriz donde se hace la busquedad de la ruta
 */
void LineaVista::lineaVista(int x, int y, int xd, int yd, Cola<int > *X, Cola<int > *Y, int matrix[15][27]) {
    origen.x = x;
    origen.y = y;
    destino.x = xd;
    destino.y = yd;

    /// Buscar ruta
    buscarRuta(destino, origen, matrix);

    /// Dar la ruta
    *X = rutaX;
    *Y = rutaY;
};

void LineaVista::rodearObstaculo(coordenada *origen, coordenada destino, int matrix[15][27]) {
    if (matrix[origen->x + 1][origen->y] == 0 && origen->x < destino.x) {
        while (matrix[origen->x + 1][origen->y] == 0) {
            rutaX.push(origen->x);
            rutaY.push(origen->y + 1);

            origen->y += 1;
        }
        rutaX.push(origen->x + 1);
        rutaY.push(origen->y);

        origen->x += 1;
    }
    if (matrix[origen->x - 1][origen->y] == 0 && origen->x > destino.x) {
        while (matrix[origen->x - 1][origen->y] == 0) {
            rutaX.push(origen->x);
            rutaY.push(origen->y + 1);

            origen->y += 1;
        }
        rutaX.push(origen->x - 1);
        rutaY.push(origen->y);

        origen->x -= 1;
    }
    if (matrix[origen->x][origen->y + 1] == 0 && origen->y < destino.y) {
        while (matrix[origen->x][origen->y + 1] == 0) {
            rutaX.push(origen->x + 1);
            rutaY.push(origen->y);

            origen->x += 1;
        }
        rutaX.push(origen->x);
        rutaY.push(origen->y + 1);

        origen->y += 1;
    }
    if (matrix[origen->x][origen->y - 1] == 0 && origen->y > destino.y) {
        while (matrix[origen->x][origen->y - 1] == 0) {
            rutaX.push(origen->x + 1);
            rutaY.push(origen->y);

            origen->x += 1;
        }
        rutaX.push(origen->x);
        rutaY.push(origen->y - 1);

        origen->y -= 1;
    }
};

void LineaVista::buscarRuta(coordenada *ruta1, coordenada destino1, int matrix[15][27]) {
    if (ruta1->x > destino1.x && matrix[ruta1->x - 1][ruta1->y] != 0) {
        rutaX.push(ruta1->x - 1);
        rutaY.push(ruta1->y);

        ruta1->x -= 1;
    }
    if (ruta1->x < destino1.x && matrix[ruta1->x + 1][ruta1->y] != 0) {
        rutaX.push(ruta1->x + 1);
        rutaY.push(ruta1->y);

        ruta1->x += 1;
    }
    if (ruta1->y > destino1.y && matrix[ruta1->x][ruta1->y - 1] != 0) {
        rutaX.push(ruta1->x);
        rutaY.push(ruta1->y - 1);

        ruta1->y -= 1;
    }
    if (ruta1->y < destino1.y && matrix[ruta1->x][ruta1->y + 1] != 0) {
        rutaX.push(ruta1->x);
        rutaY.push(ruta1->y + 1);

        ruta1->y += 1;
    }
    if (ruta1->x > destino1.x && ruta1->y > destino1.y && matrix[ruta1->x - 1][ruta1->y - 1] != 0) {
        rutaX.push(ruta1->x - 1);
        rutaY.push(ruta1->y - 1);

        ruta1->x -= 1;
        ruta1->y -= 1;
    }
    if (ruta1->x > destino1.x && ruta1->y < destino1.y && matrix[ruta1->x - 1][ruta1->y + 1] != 0) {
        rutaX.push(ruta1->x - 1);
        rutaY.push(ruta1->y + 1);

        ruta1->x -= 1;
        ruta1->y += 1;
    }
    if (ruta1->x < destino1.x && ruta1->y > destino1.y && matrix[ruta1->x - 1][ruta1->y - 1] != 0) {
        rutaX.push(ruta1->x + 1);
        rutaY.push(ruta1->y - 1);

        ruta1->x += 1;
        ruta1->y -= 1;
    }
    if (ruta1->x < destino1.x && ruta1->y < destino1.y && matrix[ruta1->x + 1][ruta1->y + 1] != 0) {
        rutaX.push(ruta1->x + 1);
        rutaY.push(ruta1->y + 1);

        ruta1->x += 1;
        ruta1->y += 1;
    } else {
        rodearObstaculo(ruta1, destino1, matrix);
    }
};
void LineaVista::buscarRuta(coordenada destino, coordenada origen, int matrix[15][27]) {
    coordenada *ruta = new coordenada;
    ruta->x = origen.x;
    ruta->y = origen.y;
    while (!(destino == *ruta)) {
        buscarRuta(ruta, destino, matrix);
    }
    while (rutaX.size() > 0 && rutaY.size() >0 ) {
        cout << rutaX.pop() << " "<< rutaY.pop() << endl;
    }
    delete (ruta);

};

bool operator==(coordenada a, coordenada b) {
    if (a.x == b.x && a.y == b.y) {
        return true;
    } else {
        return false;
    }
};