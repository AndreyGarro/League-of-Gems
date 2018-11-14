//
// Created by andrew on 31/10/18.
//

#include <allegro5/allegro.h>
#include "Soldier.h"
#include "../App/Sprite.h"
#include "../Algoritmos/LineaVista.h"
#include "../Algoritmos/AStarPathFinding.h"
#include "../Algoritmos/LineaVista.h"
#include "../Algoritmos/Kruskal.h"
#include "../Algoritmos/Prim.h"
#include "../Algoritmos/GraphMaker.h"
#include "../App/Aplicacion.h"
#include "../Algoritmos/Dijkstra.h"


/**
 * Construtuor con parametros
 * @param x posicion horizontal donde se dibujara el soldado la primera vez
 * @param y posicion vertical donde se dibujara el soldado la primera vez
 */
Soldier::Soldier(int x, int y) {
    image = al_load_bitmap("../img/soldier.png");
    this->tempX = x;
    this->tempY = y;
    xd = tempX;
    yd = tempY;
    Sprite::dibujaPersonaje(192, 644, image, 3);
}

/**
 * Constructor
 */
Soldier::Soldier() {}

/**
 * Insertar posiciones a cada soldado
 * @param i
 * @param j
 * @param matriz
 */
void Soldier::setIJ(int i, int j, int matriz[10][15], int nivel) {
    Pair posff = escogerPunto(matriz, i, j);
    if (nivel == 0) {
        cout << "Linea Vista" << endl;
        LineaVista vista = LineaVista();
        ruta = vista.lineaVista(yd / 70, xd / 90, posff.first, posff.second, matriz);
        imprimirPathCola(ruta);
        Application::matriz[posff.first][posff.second] = 4;
    } else if (nivel == 1) {
        cout << "Prim" << endl;
        Prim prim;
        if (!graphActivo) {
            GraphMaker maker;
            graph = maker.createGraph(matriz);
            this->graphActivo = true;
        }
        ruta2 = prim.primAlgorithm(yd / 70, xd / 90, posff.first, posff.second, graph);
        imprimirPath(ruta2);
        Application::matriz[posff.first][posff.second] = 4;
    } else if (nivel == 2) {
        cout << "Kruscal" << endl;
        Kruskal kruskal;
        if (!graphActivo) {
            GraphMaker maker;
            graph = maker.createGraph(matriz);
            this->graphActivo = true;
        }
        ruta2 = kruskal.kruskalAlgorithm(yd / 70, xd / 90, posff.first, posff.second, graph);
        imprimirPath(ruta2);
        Application::matriz[posff.first][posff.second] = 4;
    } else if (nivel == 3) {
        cout << "Dijkstra" << endl;
        Dijkstra dijkstra;
        ruta2 = dijkstra.findPath(yd / 70, xd / 90, posff.first, posff.second, matriz);
        imprimirPath(ruta2);
        Application::matriz[posff.first][posff.second] = 4;
    } else if (nivel == 4) {
        cout << "A star" << endl;
        AstarPathfinding AStar = AstarPathfinding();
        ruta2 = AStar.busquedaAStar(matriz, make_pair(yd / 70, xd / 90), posff);
        imprimirPath(ruta2);
        Application::matriz[posff.first][posff.second] = 4;
    }
}

/**
 * Toma la ruta punto a punto dada por el algoritmo de busquedad
 */
void Soldier::seguirRuta() {
    if (ruta2.getLenght() > 0) {
        if (this->llegue) {
            Pair coorTemp = ruta2.pop();
            xd = coorTemp.second * 90;
            yd = coorTemp.first * 70;
            this->llegue = false;
        }
    }
    if (ruta.size() > 0) {
        if (this->llegue) {
            Pair coorTemp = ruta.pop();
            xd = coorTemp.second * 90;
            yd = coorTemp.first * 70;
            this->llegue = false;
        }
    }
}

/**
 * Escoge un punto libre los mas cercano al punto seleccionado por el jugador
 * @param matriz
 * @param id  Punto de destino
 * @param jd Punto de destino
 * @return Punto escogido
 */
Pair Soldier::escogerPunto(int matriz[10][15], int id, int jd) {
    if (matriz[id][jd] == 1) {
        return make_pair(id, jd);
    }
    int a = 3, b = 3;
    while (true) {
        id -= 1;
        jd -= 1;
        try {
            for (int i = 0; i < a; ++i) {
                for (int j = 0; j < b; ++j) {
                    if ((id + i) < 0) {
                        id = 0;
                    }
                    if ((id + i) > 9) {
                        id -= abs((i + 1));
                    }
                    if ((jd + j) < 0) {
                        jd = 0;
                    }
                    if ((jd + j) > 14) {
                        jd = abs(jd - (j + 1));
                    }
                    if (matriz[abs(id + i)][abs(jd + j)] == 1) {
                        return make_pair(id + i, jd + j);
                    }
                }
            }
        }
        catch (...) {}
        a++, b++;
    }
}

/**
 * Realiza el efecto caminar de punto a punto dados por el algoritmo de busqueda
 */
void Soldier::dibujarSoldado() {
    seguirRuta();
    image = al_load_bitmap("../img/soldier.png");

    if (tempX == xd && tempY == yd) {
        this->llegue = true;
        if (flagAttack) {
            image = al_load_bitmap("../img/soldierAttack.png");
        }
    } else if (xd > tempX && yd > tempY) {
        tempX += 5;
        tempY += 5;
    } else if (xd < tempX && yd < tempY) {
        tempX -= 5;
        tempY -= 5;
    } else if (xd > tempX && yd < tempY) {
        tempX += 5;
        tempY -= 5;
    } else if (xd < tempX && yd > tempY) {
        tempX -= 5;
        tempY += 5;
    } else if (xd > tempX) {
        tempX += 5;
    } else if (xd < tempX) {
        tempX -= 5;
    } else if (yd > tempY) {
        tempY += 5;
    } else if (yd < tempY) {
        tempY -= 5;
    }
    float tempVida = this->getVida() / (this->getVidaMaxima() + 0.0f);
    if (tempY == 0) {
        al_draw_filled_rectangle(tempX, tempY + 5, tempX + (90 * tempVida), tempY, al_map_rgb_f(0, 255, 0));
    } else {
        al_draw_filled_rectangle(tempX, tempY - 5, tempX + (90 * tempVida), tempY, al_map_rgb_f(0, 255, 0));
    }
    Sprite::dibujaPersonaje(tempX, tempY, image, 3);
    Application::matriz[yd / 70][xd / 90] = 3;
}

/**
 * Revisa si es posible atacar a un enemgio dentro del rango
 * @param matriz
 * @return Posicion a la que ataco
 */
pair<int, int> Soldier::atacar(int matriz[10][15], int fast) {
    if (this->freAtaque > 30) {
        this->freAtaque = 0;
    }
    this->freAtaque++;
    if (this->freAtaque <= fast) {
        int i = (yd / 70) - 1, j = (xd / 90) - 1;
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                if (matriz[abs(i + k)][abs(j + l)] == 2) {
                    flagAttack = true;
                    return make_pair(abs(i + k), abs(j + l));
                }
            }
        }
    }
    if (this->freAtaque > 10) {
        flagAttack = false;
    }
    return make_pair(-1, -1);
}

/// Getter and setter
int Soldier::getXd() const {
    return xd;
}

int Soldier::getYd() const {
    return yd;
}

void Soldier::disminuirVida(int vida) {
    this->vida -= vida;
}

int Soldier::getVida() const {
    return vida;
}

int Soldier::getVidaMaxima() const {
    return vidaMaxima;
}

void Soldier::setVida(int vida) {
    Soldier::vida = vida;
}

int Soldier::getAtaque() const {
    return ataque;
}

void Soldier::setAtaque(int ataque) {
    Soldier::ataque = ataque;
}

int Soldier::getDefensa() const {
    return defensa;
}

void Soldier::setDefensa(int defensa) {
    Soldier::defensa = defensa;
}

void Soldier::imprimirPath(Pila<Pair> path) {
    int a = path.getLenght();
    while(path.getLenght() != 0) {
        cout << "(" << path.peek().first << " , " << path.peek().second << ")" << "-> ";
        path.pop();
    }
    cout << endl;
}

void Soldier::imprimirPathCola(Cola<Pair> path) {
    int a = path.size();
    for (int i = 0; i < a; ++i) {
        cout << "(" << path.consultar().first << " , " << path.pop().second << ")" << "-> ";
    }
    cout << endl;
}





