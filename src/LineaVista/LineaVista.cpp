//
// Created by christian on 30/10/18.
//

#include "LineaVista.h"
#include "../Algoritmos/AStarPathFinding.h"
#include "../App/Aplicacion.h"

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
    int a=0,b=0;
    if (ruta1->i > destino1.i ) {
        a = ruta1->i -1;
    }
    else if (ruta1->i < destino1.i) {
        a = ruta1->i +1;
    }
    if (ruta1->j > destino1.j) {
        b = ruta1->j -1;
    }
    else if (ruta1->j < destino1.j) {
        b = ruta1->j +1;
    }
    
    Pair posff = escogerPunto(matrix,a,b);
    AstarPathfinding AStar = AstarPathfinding();
    Pila<pair<int, int>> pila = AStar.busquedaAStar(matrix, make_pair(ruta1->i, ruta1->j), posff);
    int len = pila.getLenght();
    for (int i = 0; i < len; ++i) {
        ruta->push(pila.pop());
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
    }
    else {
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
        buscarRuta(XYtemp, destino, matrix, ruta);
        cout <<"XY "<< XYtemp->i <<" "<< XYtemp->j << endl;
        cout <<"D "<< destino.i <<" "<< destino.j << endl;
    }
    /**/
    int a = ruta->size();
    cout << a << endl;
    for (int i = 0; i < a; ++i) {
        cout << ruta->consultar().first << ruta->pop().second<<", ";
    }
    cout << endl;
     /**/
    delete (XYtemp);

};

bool coordenada::operator==(coordenada a) {
    if (this->i == a.i){
        return this->j == a.j;
    }
    else {
        return false;
    }
}

pair<int,int> LineaVista::escogerPunto(int matriz[10][15], int id, int jd) {
        try {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j <3; ++j) {
                    if ((id + i) < 0) {
                        cout<<"1"<< endl;
                        id = 0;
                    }
                    if ((id + i )> 9) {
                        cout<<"2"<< endl;
                        id -= abs((i + 1));
                    }
                    if ((jd + j) < 0) {
                        cout<<"3"<< endl;
                        jd = 0;
                    }
                    if ((jd + j) > 14) {
                        cout<<"4"<< endl;
                        jd = abs(jd - (j + 1));
                    }
                    if (matriz[abs(id + i)][abs(jd + j)] == 1) {
                        return make_pair(id + i, jd + j);
                    }
                }
            }
        }
        catch(...) { }
}