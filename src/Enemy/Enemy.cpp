//
// Created by andrew on 31/10/18.
//

#include <iostream>
#include "Enemy.h"

/**
 * Constructor
 * @param x posicion en X donde se va a colocar
 * @param y posicion en Y donde se va a colocar
 */
Enemy::Enemy(int x, int y) {
    this->posX = x;
    this->posY = y;
    this->fitnessData[0] = 0;
    this->fitnessData[1] = 0;
    this->fitnessData[2] = 0;
}

//_________________________GETTERS AND SETTERS__________________________________

int Enemy::getPosX() const {
    return posX;
}

int Enemy::getPosY() const {
    return posY;
}

ALLEGRO_BITMAP *Enemy::getEnemy() const {
    return enemy;
}

void Enemy::setEnemy(ALLEGRO_BITMAP *enemy) {
    Enemy::enemy = enemy;
}

int Enemy::getVida() const {
    return vida;
}

void Enemy::setVida(int vida) {
    Enemy::vida = vida;
}

void Enemy::setAtaque(int ataque) {
    Enemy::ataque = ataque;
}

int Enemy::getAtaque() const {
    return ataque;
}

int Enemy::getVidaMaxima() const {
    return vidaMaxima;
}

int Enemy::getDefensa() const {
    return defensa;
}

void Enemy::setDefensa(int defensa) {
    Enemy::defensa = defensa;
}

void Enemy::setVidaMaxima(int vidaMaxima) {
    Enemy::vidaMaxima = vidaMaxima;
}

int Enemy::getFrecuenciaAtaque() const {
    return frecuenciaAtaque;
}

void Enemy::setFrecuenciaAtaque(int frecuenciaAtaque) {
    Enemy::frecuenciaAtaque = frecuenciaAtaque;
}

int *Enemy::getFitnessData() {
    return fitnessData;
}
int Enemy::getPosLista() const {
    return posLista;
}

void Enemy::setPosLista(int posLista) {
    Enemy::posLista = posLista;
}


//___________________FIN GETTERS AND SETTERS_________________________________

/**
 * Método complementario de la clase EnemyController para devolver
 * la posición del soldado al cual se está atacando
 * @param matriz matriz actual de posiciones
 * @return
 */
pair<int, int> Enemy::revisaAtaque(int matriz[10][15]) {
    if (this->cont > 30){
        this->cont = 0;
    }
    this->cont ++;
    if(this->cont <= this->frecuenciaAtaque) {
        int posIX = (this->getPosX() / 90) - 1;
        int posIY = (this->getPosY() / 70) - 1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (posIX+j < 15 && matriz[abs(posIY + i)][abs(posIX + j)] == 3) {
                    this->atacando = true;
                    return make_pair(abs(posIY + i), abs(posIX + j));
                }
            }
        }
    }
    if(this->cont > 10) {
        this->atacando = false;
    }
    return make_pair(-1, -1);
}


/**
 * Aumenta el daño hecho por cromosoma
 * @param damage
 */
void Enemy::moreDamage(int damage) {
    fitnessData[1] += damage;
    fitnessData[2]++;

}

/**
 * Aumenta la cantidad de ataque infligido por el cromosoma
 */
void Enemy::moreDefense() {
    fitnessData[0] += this->defensa;
}



