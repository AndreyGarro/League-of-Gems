//
// Created by ortegajosant on 08/11/18.
//

#ifndef ALGORITMOS_ENEMY_H
#define ALGORITMOS_ENEMY_H

/**
 * Cromosoma del Algoritmo genético
 */
class GeneticEnemy {

private:
    int defence;
    int health;
    int damage;
    int atackFreq;
    double fitness = 0;
    int fitnessData[3];

public:
    GeneticEnemy(int defence, int health, int damage, int atackFreq);

    int getDefence() const;

    void setDefence(int range);

    int getHealth() const;

    void setHealth(int health);

    int getDamage() const;

    void setDamage(int damage);

    int getAtackFreq() const;

    void setAtackFreq(int atackFreq);

    double getFitness() const;

    void setFitness(double fitness);

    const int *getFitnessData() const;

    void moreDamage(int);

    void moreAtacks();

    GeneticEnemy();
};


#endif //ALGORITMOS_ENEMY_H
