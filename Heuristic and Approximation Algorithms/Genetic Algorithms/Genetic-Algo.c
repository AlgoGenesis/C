#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POP_SIZE 10        // Population size
#define CHROMO_LENGTH 5    // Length of each chromosome (solution)
#define MAX_GENERATIONS 20 // Number of generations

// Function to evaluate fitness (higher is better, example: sum of bits)
int fitness(int chromosome[]) {
    int sum = 0;
    for (int i = 0; i < CHROMO_LENGTH; i++) {
        sum += chromosome[i];
    }
    return sum;
}

// Function to initialize population randomly
void initializePopulation(int population[POP_SIZE][CHROMO_LENGTH]) {
    for (int i = 0; i < POP_SIZE; i++) {
        for (int j = 0; j < CHROMO_LENGTH; j++) {
            population[i][j] = rand() % 2;  // Randomly assign 0 or 1
        }
    }
}

// Function to select parents using tournament selection
int selectParent(int population[POP_SIZE][CHROMO_LENGTH], int fitnessScores[]) {
    int parent1 = rand() % POP_SIZE;
    int parent2 = rand() % POP_SIZE;
    return (fitnessScores[parent1] > fitnessScores[parent2]) ? parent1 : parent2;
}

// Function to perform crossover between two parents
void crossover(int parent1[], int parent2[], int offspring1[], int offspring2[]) {
    int crossoverPoint = rand() % CHROMO_LENGTH;
    for (int i = 0; i < CHROMO_LENGTH; i++) {
        if (i < crossoverPoint) {
            offspring1[i] = parent1[i];
            offspring2[i] = parent2[i];
        } else {
            offspring1[i] = parent2[i];
            offspring2[i] = parent1[i];
        }
    }
}

// Function to mutate offspring with a small probability
void mutate(int chromosome[]) {
    for (int i = 0; i < CHROMO_LENGTH; i++) {
        if (rand() % 100 < 5) {  // 5% mutation rate
            chromosome[i] = 1 - chromosome[i];  // Flip bit
        }
    }
}

int main() {
    srand(time(NULL));
    
    // Initialize population
    int population[POP_SIZE][CHROMO_LENGTH];
    int fitnessScores[POP_SIZE];
    initializePopulation(population);

    // Genetic Algorithm loop
    for (int generation = 0; generation < MAX_GENERATIONS; generation++) {
        // Evaluate fitness of population
        for (int i = 0; i < POP_SIZE; i++) {
            fitnessScores[i] = fitness(population[i]);
        }

        // Generate new population
        int newPopulation[POP_SIZE][CHROMO_LENGTH];
        for (int i = 0; i < POP_SIZE; i += 2) {
            // Select two parents
            int parent1Index = selectParent(population, fitnessScores);
            int parent2Index = selectParent(population, fitnessScores);

            // Perform crossover and create two offspring
            int offspring1[CHROMO_LENGTH], offspring2[CHROMO_LENGTH];
            crossover(population[parent1Index], population[parent2Index], offspring1, offspring2);

            // Mutate offspring
            mutate(offspring1);
            mutate(offspring2);

            // Add offspring to new population
            for (int j = 0; j < CHROMO_LENGTH; j++) {
                newPopulation[i][j] = offspring1[j];
                newPopulation[i + 1][j] = offspring2[j];
            }
        }

        // Replace old population with new population
        for (int i = 0; i < POP_SIZE; i++) {
            for (int j = 0; j < CHROMO_LENGTH; j++) {
                population[i][j] = newPopulation[i][j];
            }
        }

        // Display generation info
        printf("Generation %d: ", generation + 1);
        for (int i = 0; i < POP_SIZE; i++) {
            printf("[ ");
            for (int j = 0; j < CHROMO_LENGTH; j++) {
                printf("%d ", population[i][j]);
            }
            printf("] Fitness: %d  ", fitnessScores[i]);
        }
        printf("\n");
    }

    return 0;
}
