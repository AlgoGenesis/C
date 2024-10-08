#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CITIES 5 // Number of cities

// Distance matrix between cities
double distance[CITIES][CITIES] = {
    {0, 2, 9, 10, 7},
    {1, 0, 6, 4, 5},
    {15, 7, 0, 8, 6},
    {6, 3, 12, 0, 4},
    {10, 8, 5, 2, 0}
};

// Function to calculate the total distance of a tour
double calculateTourLength(int *tour) {
    double totalDistance = 0.0;
    for (int i = 0; i < CITIES - 1; i++) {
        totalDistance += distance[tour[i]][tour[i + 1]];
    }
    totalDistance += distance[tour[CITIES - 1]][tour[0]]; // Return to start
    return totalDistance;
}

// Function to generate a greedy random solution
void generateGreedyRandomSolution(int *tour) {
    int visited[CITIES] = {0};
    int currentCity = rand() % CITIES;
    visited[currentCity] = 1;
    tour[0] = currentCity;

    for (int i = 1; i < CITIES; i++) {
        double minDistance = __DBL_MAX__;
        for (int j = 0; j < CITIES; j++) {
            if (!visited[j] && distance[currentCity][j] < minDistance) {
                minDistance = distance[currentCity][j];
            }
        }
        
        // Randomly choose the next city from candidates with the minimum distance
        int nextCity = -1;
        for (int j = 0; j < CITIES; j++) {
            if (!visited[j] && distance[currentCity][j] == minDistance) {
                if (rand() % (CITIES - i) == 0) {
                    nextCity = j;
                    break;
                }
            }
        }
        
        tour[i] = nextCity;
        visited[nextCity] = 1;
        currentCity = nextCity;
    }
}

// Main function to execute GRASP
int main() {
    srand(time(NULL)); // Seed for random number generation
    int bestTour[CITIES];
    double bestLength = __DBL_MAX__;
    int iterations = 100; // Number of iterations

    for (int i = 0; i < iterations; i++) {
        int currentTour[CITIES];
        generateGreedyRandomSolution(currentTour);
        double currentLength = calculateTourLength(currentTour);

        if (currentLength < bestLength) {
            bestLength = currentLength;
            for (int j = 0; j < CITIES; j++) {
                bestTour[j] = currentTour[j];
            }
        }
    }

    printf("Best tour: ");
    for (int i = 0; i < CITIES; i++) {
        printf("%d ", bestTour[i]);
    }
    printf("\nTour length: %.2f\n", bestLength);

    return 0;
}
