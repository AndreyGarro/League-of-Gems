//
// Created by ortegajosant on 08/11/18.
//

#include <ctime>
#include <iostream>
#include "GeneticAlgorithm.h"

/**
 * Función que retorna una nueva generación de enémigos
 * @param start true si es el nivel 1
 * @return Enemies
 */
SimpleList<GeneticEnemy> GeneticAlgorithm::makeNewEnemies(bool start) {
    if (start) {
        makeFirstGeneration();
    } else {

        fitnessFunction();
        crossParents();
        mutateEnemies();

        return enemies;
    }
    return this->enemies;
}

/**
 * Realiza el cruzamiento de los padres
 */
void GeneticAlgorithm::crossParents() {
    SimpleList<EnemyToAnalyze> survivors = deleteWorseParents();
    srand(time(NULL));

    int parameter1 = 0;
    int parameter2 = 0;
    SimpleList<GeneticEnemy> enemies;
    for (int i = 0; i < MAXENEMIES; i += 2) {
        while (parameter1 == parameter2) {
            parameter1 = rand() % 6;
            parameter2 = rand() % 6;
        }
        EnemyToAnalyze firstParent = *survivors.getData(parameter1);
        EnemyToAnalyze secondParent = *survivors.getData(parameter2);

        parameter1 = rand() % 4;
        parameter2 = rand() % 4;

        while (parameter1 == parameter2) {
            parameter1 = rand() % 4;
            parameter2 = rand() % 4;
        }

        int noParameters[2] = {0, 0};
        int cont = 0;

        for (int j = 0; j < 4; j++) {
            if (j != parameter1 && j != parameter2) {
                noParameters[cont] = j;
                cont++;
            }
        }

        GeneticEnemy firstSon = makeSon(parameter1, parameter2, noParameters[0], noParameters[1], firstParent, secondParent);
        GeneticEnemy secondSon = makeSon(noParameters[0], noParameters[1], parameter1, parameter2, firstParent, secondParent);

        enemies.add(firstSon);
        population.setData(i, EnemyToAnalyze(firstSon.getDefence(), firstSon.getDamage(), firstSon.getAtackFreq(),
                                             firstSon.getHealth()));
        enemies.add(secondSon);
        population.setData(i + 1,
                           EnemyToAnalyze(secondSon.getDefence(), secondSon.getDamage(), secondSon.getAtackFreq(),
                                          secondSon.getHealth()));

    }
    this->enemies = enemies;
}
/**
 * Genera un nuevo hijo emparejando a dos padres
 * @param parameter1
 * @param parameter2
 * @param parameter3
 * @param parameter4
 * @param firstParent
 * @param secondParent
 * @return
 */
GeneticEnemy
GeneticAlgorithm::makeSon(int parameter1, int parameter2, int parameter3, int parameter4, EnemyToAnalyze firstParent,
                          EnemyToAnalyze secondParent) {
    GeneticEnemy enemy;
    int cont = 0;
    int parameter;
    bool parent = true;
    int parameterArray[4] = {parameter1, parameter2, parameter3, parameter4};
    while (cont < 4) {

        parameter = parameterArray[cont];

        if (parameter == parameter1) {
            parent = true;
        } else if (parameter == parameter2) {
            parent = true;
        } else if (parameter == parameter3) {
            parent = false;
        } else if (parameter == parameter4){
            parent = false;
        }

        switch (parameter) {
            case 0:
                if (parent) {
                    enemy.setDefence(firstParent.defence);
                    break;
                }
                enemy.setDefence(secondParent.defence);
                break;
            case 1:
                if (parent) {
                    enemy.setHealth(firstParent.health);
                    break;
                }
                enemy.setHealth(secondParent.health);
                break;
            case 2:
                if (parent) {
                    enemy.setDamage(firstParent.damage);
                    break;
                }
                enemy.setDamage(secondParent.damage);
                break;
            default:
                if (parent) {
                    enemy.setAtackFreq(firstParent.attackFreq);
                    break;
                }
                enemy.setAtackFreq(secondParent.attackFreq);
                break;
        }
        cont++;
    }
    return enemy;
}

/**
 * Genera la primera generación de enemigos, totalmente aleatoria
 */
void GeneticAlgorithm::makeFirstGeneration() {
    srand(time(NULL));
    int defence, damage, atackFreq, health;
    for (int i = 0; i < MAXENEMIES; i++) {
        defence = rand() % 30;
        damage = rand() % 20 + 10;
        atackFreq = rand() % 3 + 1;
        health = rand() % 100 + 400;
        enemies.add(GeneticEnemy(defence, health, damage, atackFreq));
        population.add(EnemyToAnalyze(defence, damage, atackFreq, health));
    }
}

/**
 * Se hace el análisis estadístico para el fitness de cada individuo
 */
void GeneticAlgorithm::fitnessFunction() {
    EnemyToAnalyze temp;
    for (int i = 0; i < population.getLength(); i++) {
        temp = *population.getData(i);
        temp.fitness = (temp.fitnessData[0] / 60.0) + (temp.fitnessData[1] / 60.0) +
                       (temp.fitnessData[2] / 60.0) + (temp.health / (temp.defence + 0.0) / temp.health);
        population.setData(i, temp);
    }
    sortByFitness();

}

/**
 * Imprime la generación de enemigos actual
 */
void GeneticAlgorithm::printEnemiesData() {
    GeneticEnemy temp;
    for (int i = 0; i < enemies.getLength(); i++) {
        std::cout << "---Enemigo " << i + 1 << "---" << std::endl;
        temp = *enemies.getData(i);
        std::cout << "Defensa: " << temp.getDefence() << std::endl;
        std::cout << "Vida: " << temp.getHealth() << std::endl;
        std::cout << "Daño: " << temp.getDamage() << std::endl;
        std::cout << "Frecuencia de ataque: " << temp.getAtackFreq() << std::endl;
        std::cout << std::endl;
    }
}

/**
 * Ordena los enemigos según su fitness
 */
void GeneticAlgorithm::sortByFitness() {
    int i, j;
    EnemyToAnalyze enemyTemp;
    for (i = 1; i < population.getLength(); i++) {
        enemyTemp = *population.getData(i);
        j = i - 1;

        while (j >= 0 && population.getData(j)->fitness < enemyTemp.fitness) {
            population.setData(j + 1, *population.getData(j));
            j = j - 1;
        }
        population.setData(j + 1, enemyTemp);
    }
}

/**
 * Añade el fitnessData proveniete de un enemigo caido
 * @param fitnessData
 * @param index
 */
void GeneticAlgorithm::addFitnessData(int fitnessData[3], int index) {
    EnemyToAnalyze temp = *population.getData(index);

    temp.fitnessData[0] = fitnessData[0];
    temp.fitnessData[1] = fitnessData[1];
    temp.fitnessData[2] = fitnessData[2];

    population.setData(index, temp);
}

/**
 * Elimina los peores individuos de la generación
 * @return
 */
SimpleList<EnemyToAnalyze> GeneticAlgorithm::deleteWorseParents() {

    SimpleList<EnemyToAnalyze> temp;

    for (int i = 0; i < 6; i++) {
        temp.add(*population.getData(i));
    }

    return temp;
}

/**
 * Elimina la lista de enemigos
 */
void GeneticAlgorithm::eraseEnemies() {
    for (int i = 0; i < MAXENEMIES; i++) {
        enemies.deleteNode(0);
    }
}

/**
 * Realiza la mutación de los individuos de la generación
 */
void GeneticAlgorithm::mutateEnemies() {
    srand(time(NULL));
    int probability, gen;
    for (int i = 0; i < enemies.getLength(); i++) {
        probability = rand() % 100;
        if (probability > 50) {
            gen = rand() % 4;
            switch (gen) {
                case 0:
                    enemies.getData(i)->setDefence(rand() % 30);
                    break;
                case 1:
                    enemies.getData(i)->setHealth(rand() % 100 + 400);
                    break;
                case 2:
                    enemies.getData(i)->setDamage(rand() % 20 + 10);
                    break;
                default:
                    enemies.getData(i)->setAtackFreq(rand() % 3 + 1);
                    break;
            }
        }
    }
}
