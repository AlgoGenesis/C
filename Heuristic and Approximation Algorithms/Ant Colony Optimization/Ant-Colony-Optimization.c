#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define CITIES 5          // Number of cities
#define ANTS 10           // Number of ants
#define ALPHA 1.0         // Importance of pheromone
#define BETA 2.0          // Importance of distance
#define EVAPORATION_RATE 0.5 // Pheromone evaporation rate
#define Q 100             // Pheromone deposit constant
#define MAX_ITERATIONS 100 // Maximum iterations

// Distance matrix between cities
double distance[CITIES][CITIES] = {
    {0, 2, 9, 10, 7},
    {1, 0, 6, 4, 5},
    {15, 7, 0, 8, 6},
    {6, 3, 12, 0, 4},
    {10, 8, 5, 2, 0}
};

// Pheromone matrix
double pheromone[CITIES][CITIES];

// Function to initialize pheromones
void initializePheromone() {
    for (int i = 0; i < CITIES; i++) {
        for (int j = 0; j < CITIES; j++) {
            pheromone[i][j] = 1.0; // Initial pheromone level
        }
    }
}

// Function to choose the next city based on pheromone and distance
int chooseNextCity(int currentCity, int visited[]) {
    double probabilities[CITIES];
    double sum = 0.0;

    for (int i = 0; i < CITIES; i++) {
        if (!visited[i]) {
            probabilities[i] = pow(pheromone[currentCity][i], ALPHA) * pow(1.0 / distance[currentCity][i], BETA);
            sum += probabilities[i];
        } else {
            probabilities[i] = 0;
        }
    }

    double randNum = ((double) rand() / (RAND_MAX)) * sum;
    for (int i = 0; i < CITIES; i++) {
        if (!visited[i]) {
            randNum -= probabilities[i];
            if (randNum <= 0) {
                return i;
            }
        }
    }

    return -1; // Should never reach here
}

// Function to update pheromones
void updatePheromones(double antTours[ANTS][CITIES], double tourLengths[ANTS]) {
    for (int i = 0; i < CITIES; i++) {
        for (int j = 0; j < CITIES; j++) {
            pheromone[i][j] *= (1 - EVAPORATION_RATE); // Evaporate pheromone
        }
    }

    for (int k = 0; k < ANTS; k++) {
        double deposit = Q / tourLengths[k];
        for (int i = 0; i < CITIES - 1; i++) {
            int from = (int) antTours[k][i];
            int to = (int) antTours[k][i + 1];
            pheromone[from][to] += deposit;
            pheromone[to][from] += deposit; // Since TSP is symmetric
        }
    }
}

// Main function
int main() {
    srand(time(NULL));
    initializePheromone();

    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        double antTours[ANTS][CITIES];
        double tourLengths[ANTS];

        for (int ant = 0; ant < ANTS; ant++) {
            int visited[CITIES] = {0};
            int currentCity = rand() % CITIES;
            visited[currentCity] = 1;
            antTours[ant][0] = currentCity;

            for (int step = 1; step < CITIES; step++) {
                currentCity = chooseNextCity(currentCity, visited);
                visited[currentCity] = 1;
                antTours[ant][step] = currentCity;
            }

            // Calculate the length of the tour
            double length = 0.0;
            for (int i = 0; i < CITIES - 1; i++) {
                length += distance[(int) antTours[ant][i]][(int) antTours[ant][i + 1]];
            }
            length += distance[(int) antTours[ant][CITIES - 1]][(int) antTours[ant][0]]; // Return to start
            tourLengths[ant] = length;
        }

        // Update pheromones
        updatePheromones(antTours, tourLengths);
    }

    // Display the final pheromone levels
    printf("Final Pheromone Levels:\n");
    for (int i = 0; i < CITIES; i++) {
        for (int j = 0; j < CITIES; j++) {
            printf("%.2f ", pheromone[i][j]);
        }
        printf("\n");
    }

    return 0;
}
