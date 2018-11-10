//
// Created by ortegajosant on 08/11/18.
//

#ifndef ALGORITMOS_GENETICALGHORITHM_H
#define ALGORITMOS_GENETICALGHORITHM_H


#include "../Estructuras/SimpleList.h"
#include "GeneticEnemy.h"

#define MAXENEMIES 8
/**
 * Almacena datos necesario para el análisis estadístico del fitness
 */
struct EnemyToAnalyze {

    EnemyToAnalyze() {
        this->defence = 0;
        this->damage = 0;
        this->attackFreq = 0;
        this->health = 0;
    }

    EnemyToAnalyze(int defence, int damage, int atackFreq, int health) {
        this->defence = defence;
        this->damage = damage;
        this->attackFreq = atackFreq;
        this->health = health;
    }

    int defence;
    int damage;
    int attackFreq;
    int health;
    double fitness;
    int fitnessData[3];
};

/**
 * Clase encargada de realizar el algoritmo genético
 */
class GeneticAlgorithm {
private:
    SimpleList<GeneticEnemy> enemies;
    SimpleList<EnemyToAnalyze> population;

    void makeFirstGeneration();

    void fitnessFunction();

    SimpleList<EnemyToAnalyze> deleteWorseParents();

    void eraseEnemies();

    void crossParents();

    GeneticEnemy makeSon(int parameter1, int parameter2, int parameter3, int parameter4, EnemyToAnalyze firstParent, EnemyToAnalyze secondParent);

public:
    SimpleList<GeneticEnemy> makeNewEnemies(bool start);

    void printEnemiesData();

    void sortByFitness();

    void addFitnessData(int fitnessData[3], int index);


    void mutateEnemies();
};


#endif //ALGORITMOS_GENETICALGHORITHM_H
