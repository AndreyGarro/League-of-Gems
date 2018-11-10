//
// Created by ortegajosant on 08/11/18.
//

#include "GeneticEnemy.h"

/**
 * Aumenta el daño hecho por cromosoma
 * @param damage
 */
void GeneticEnemy::moreDamage(int damage) {
    fitnessData[1] += damage;
    fitnessData[0] += this->defence;
}

/**
 * Aumenta la cantidad de ataque infligida por el cromosoma
 */
void GeneticEnemy::moreAtacks() {
    fitnessData[2]++;
}


int GeneticEnemy::getDefence() const {
    return defence;
}

void GeneticEnemy::setDefence(int range) {
    GeneticEnemy::defence = range;
}

int GeneticEnemy::getHealth() const {
    return health;
}

void GeneticEnemy::setHealth(int health) {
    GeneticEnemy::health = health;
}

int GeneticEnemy::getDamage() const {
    return damage;
}

void GeneticEnemy::setDamage(int damage) {
    GeneticEnemy::damage = damage;
}

int GeneticEnemy::getAtackFreq() const {
    return atackFreq;
}

void GeneticEnemy::setAtackFreq(int atackFreq) {
    GeneticEnemy::atackFreq = atackFreq;
}

double GeneticEnemy::getFitness() const {
    return fitness;
}

void GeneticEnemy::setFitness(double fitness) {
    GeneticEnemy::fitness = fitness;
}

const int *GeneticEnemy::getFitnessData() const {
    return fitnessData;
}

/**
 * Constructor
 */
GeneticEnemy::GeneticEnemy() {
    this->atackFreq = 0;
    this->damage = 0;
    this->health = 0;
    this->defence = 0;
    fitnessData[0] = 0;
    fitnessData[1] = 0;
    fitnessData[2] = 0;
}

/**
 * Constructor
 * @param defence Defensa
 * @param health Vida
 * @param damage Daño
 * @param atackFreq Frecuencia de ataque
 */
GeneticEnemy::GeneticEnemy(int defence, int health, int damage, int atackFreq) {
    this->atackFreq = atackFreq;
    this->damage = damage;
    this->health = health;
    this->defence = defence;
    fitnessData[0] = 0;
    fitnessData[1] = 0;
    fitnessData[2] = 0;
}
