#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to perform the Monte Carlo simulation
double estimatePi(int totalPoints) {
    int pointsInsideCircle = 0;
    double x, y;

    for (int i = 0; i < totalPoints; i++) {
        x = (double)rand() / RAND_MAX; // Random x-coordinate between 0 and 1
        y = (double)rand() / RAND_MAX; // Random y-coordinate between 0 and 1

        // Check if the point lie inside the quarter circle
        if (x * x + y * y <= 1.0) {
            pointsInsideCircle++;
        }
    }

    // Estimate Pi using the ratio of points inside the circle to total points
    return 4.0 * pointsInsideCircle / totalPoints;
}

int main() {
    int totalPoints = 1000000;  // Total number of random points

    srand(time(NULL));  // Seed the random number generator

    double piEstimate = estimatePi(totalPoints);  

    printf("Estimated value of Pi: %f\n", piEstimate);  

    return 0;
}
