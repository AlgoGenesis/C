#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define POP_SIZE 50         // Total number of solutions
#define MAX_ITER 1000       // Maximum number of iterations
#define DIM 2               // Dimension of the problem (2D optimization)
#define NEIGHBORS 5         // Number of neighbors per elite solution
#define ELITE_SITES 2       // Number of elite sites
#define OTHER_SITES 3       // Number of other sites
#define LOWER_BOUND -10.0   // Lower bound of the search space
#define UPPER_BOUND 10.0    // Upper bound of the search space

// Objective function to minimize (example: sphere function)
double objective_function(double solution[DIM]) {
    double result = 0.0;
    for (int i = 0; i < DIM; i++) {
        result += solution[i] * solution[i];
    }
    return result;
}

// Generate random solutions within the bounds
void initialize_solution(double solution[DIM]) {
    for (int i = 0; i < DIM; i++) {
        solution[i] = LOWER_BOUND + ((double)rand() / RAND_MAX) * (UPPER_BOUND - LOWER_BOUND);
    }
}

// Generate neighbor solutions
void generate_neighbor(double base[DIM], double neighbor[DIM]) {
    for (int i = 0; i < DIM; i++) {
        double perturb = ((double)rand() / RAND_MAX - 0.5) * 2.0; // Random perturbation
        neighbor[i] = base[i] + perturb;
        if (neighbor[i] < LOWER_BOUND) neighbor[i] = LOWER_BOUND;
        if (neighbor[i] > UPPER_BOUND) neighbor[i] = UPPER_BOUND;
    }
}

// Main Bee Algorithm
void bee_algorithm() {
    double population[POP_SIZE][DIM];
    double best_solution[DIM];
    double best_fitness = INFINITY;

    // Initialize population
    for (int i = 0; i < POP_SIZE; i++) {
        initialize_solution(population[i]);
    }

    // Main loop
    for (int iter = 0; iter < MAX_ITER; iter++) {
        // Evaluate all solutions
        for (int i = 0; i < POP_SIZE; i++) {
            double fitness = objective_function(population[i]);
            if (fitness < best_fitness) {
                best_fitness = fitness;
                for (int d = 0; d < DIM; d++) {
                    best_solution[d] = population[i][d];
                }
            }
        }

        // Elite sites neighborhood search
        for (int e = 0; e < ELITE_SITES; e++) {
            for (int n = 0; n < NEIGHBORS; n++) {
                double neighbor[DIM];
                generate_neighbor(population[e], neighbor);
                double fitness = objective_function(neighbor);
                if (fitness < objective_function(population[e])) {
                    for (int d = 0; d < DIM; d++) {
                        population[e][d] = neighbor[d];
                    }
                }
            }
        }

        // Other sites neighborhood search
        for (int o = ELITE_SITES; o < ELITE_SITES + OTHER_SITES; o++) {
            for (int n = 0; n < NEIGHBORS; n++) {
                double neighbor[DIM];
                generate_neighbor(population[o], neighbor);
                double fitness = objective_function(neighbor);
                if (fitness < objective_function(population[o])) {
                    for (int d = 0; d < DIM; d++) {
                        population[o][d] = neighbor[d];
                    }
                }
            }
        }

        // Scout bees - replace non-elite solutions with new random solutions
        for (int i = ELITE_SITES + OTHER_SITES; i < POP_SIZE; i++) {
            initialize_solution(population[i]);
        }

        // Print the best solution for each iteration
        printf("Iteration %d: Best Fitness = %f\n", iter + 1, best_fitness);
    }

    // Print final best solution
    printf("Best solution found:\n");
    for (int d = 0; d < DIM; d++) {
        printf("x[%d] = %f\n", d, best_solution[d]);
    }
    printf("Best fitness = %f\n", best_fitness);
}

int main() {
    srand(time(0)); // Seed random number generator
    bee_algorithm();
    return 0;
}
