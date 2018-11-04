//
// Created by christian on 30/10/18.
//

#include "LineaVista.h"
/**
 * Metodo para buscar rutas por Linea-Vista
 * @param i posicion de origen en x
 * @param j posicion de origen en y
 * @param id  posicion de destino en x
 * @param jd  posicion de destino en y
 * @param X  --- Cola para devolver la ruta
 * @param Y ---//
 * @param matrix Matriz donde se hace la busquedad de la ruta
 */
Cola<pair<int, int>> LineaVista::lineaVista(int i, int j, int id, int jd, int matrix[10][15]) {
    origen.i = i;
    origen.j = j;
    destino.i = id;
    destino.j = jd;

    /// Buscar ruta
    Cola<pair<int, int>> *ruta = new Cola<pair<int, int >>();
    buscarRuta(destino, origen, matrix, ruta);

    return *ruta;
};
/**
 * Bordea un obstaculo
 * @param ruta1 Punto donde se encuentra el soldado
 * @param destino1
 * @param matrix
 * @param ruta Cola donde almacena la ruta para bordear el obstaculo
 */
void LineaVista::rodearObstaculo(coordenada *ruta1, coordenada destino1, int matrix[10][15], Cola<pair<int, int>> *ruta) {
    if (ruta1->i > destino1.i && matrix[ruta1->i - 1][ruta1->j] == 1) {
        ruta1->i--;
        pair<int, int> a; a.first = ruta1->i;a.second = ruta1->j;
        ruta->push(a);
    }
    if (ruta1->i < destino1.i && matrix[ruta1->i + 1][ruta1->j] == 1) {
        ruta1->i++;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    if (ruta1->j > destino1.j && matrix[ruta1->i][ruta1->j - 1] == 1) {
        ruta1->j--;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    if (ruta1->j < destino1.j && matrix[ruta1->i][ruta1->j + 1] == 1) {
        ruta1->j++;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    if (ruta1->i > destino1.i && ruta1->j > destino1.j && matrix[ruta1->i - 1][ruta1->j - 1] == 1 ) {
        ruta1->i--;
        ruta1->j--;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    if (ruta1->i > destino1.i && ruta1->j < destino1.j && matrix[ruta1->i - 1][ruta1->j + 1] == 1) {
        ruta1->i--;
        ruta1->j++;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    if (ruta1->i < destino1.i && ruta1->j > destino1.j && matrix[ruta1->i- 1][ruta1->j - 1] == 1) {
        ruta1->i++;
        ruta1->j--;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    if (ruta1->i < destino1.i && ruta1->j < destino1.j && matrix[ruta1->i + 1][ruta1->j + 1] == 1) {
        ruta1->i++;
        ruta1->j++;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
};
/**
 * Busca una dirreccion en la que caminar la cual lleve al punto de destino
 * @param ruta1  ultima posicon de la ruta que lleva formada
 * @param destino1
 * @param matrix
 * @param ruta Cola donde se almacena el punto encontra
 */
void LineaVista::buscarRuta(coordenada *ruta1, coordenada destino1, int matrix[10][15], Cola<pair<int, int>> *ruta) {
    if (ruta1->i > destino1.i && matrix[ruta1->i - 1][ruta1->j] == 1) {
        ruta1->i--;
        pair<int, int> a; a.first = ruta1->i;a.second = ruta1->j;
        ruta->push(a);
    }
    else if (ruta1->i < destino1.i && matrix[ruta1->i + 1][ruta1->j] == 1) {
        ruta1->i++;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    else if (ruta1->j > destino1.j && matrix[ruta1->i][ruta1->j - 1] == 1) {
        ruta1->j--;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    else if (ruta1->j < destino1.j && matrix[ruta1->i][ruta1->j + 1] == 1) {
        ruta1->j++;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    if (ruta1->i > destino1.i && ruta1->j > destino1.j && matrix[ruta1->i - 1][ruta1->j - 1] == 1 ) {
        ruta1->i--;
        ruta1->j--;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    else if (ruta1->i > destino1.i && ruta1->j < destino1.j && matrix[ruta1->i - 1][ruta1->j + 1] == 1) {
        ruta1->i--;
        ruta1->j++;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    else if (ruta1->i < destino1.i && ruta1->j > destino1.j && matrix[ruta1->i- 1][ruta1->j - 1] == 1) {
        ruta1->i++;
        ruta1->j--;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    }
    else if (ruta1->i < destino1.i && ruta1->j < destino1.j && matrix[ruta1->i + 1][ruta1->j + 1] == 1) {
        ruta1->i++;
        ruta1->j++;
        pair<int, int> a; a.first = ruta1->i; a.second = ruta1->j;
        ruta->push(a);
    } else {
        rodearObstaculo(ruta1, destino1, matrix, ruta);
    }
};
/**
 * Busca un punto para ir del punto de inicio hasta el destino
 * @param destino
 * @param origen
 * @param matrix
 * @param ruta Cola donde se devuelve la ruta
 */
void LineaVista::buscarRuta(coordenada destino, coordenada origen, int matrix[10][15], Cola<pair<int, int>> *ruta) {
    coordenada *XYtemp = new coordenada;
    *XYtemp = origen;
    while (!(destino == *XYtemp)) {
//        cout <<"D "<< destino.i << destino.j << endl;
//        cout <<"XY "<< XYtemp->i << XYtemp->j << endl;
        buscarRuta(XYtemp, destino, matrix, ruta);
    }
    delete (XYtemp);

};