#include <stdio.h>

// Helper function to check if Koko can finish all bananas at a given speed in the available time
int canEatAllBananas(int bananaPiles[], int numPiles, int speed, int availableHours) {
    int totalHours = 0;
    for (int i = 0; i < numPiles; i++) {
        totalHours += (bananaPiles[i] + speed - 1) / speed;  // Ceiling of (bananaPiles[i] / speed)
    }
    return totalHours <= availableHours;
}

// Function to find the minimum speed at which Koko can eat all bananas within the available time
int findMinimumSpeed(int bananaPiles[], int numPiles, int availableHours) {
    int minSpeed = 1;
    int maxSpeed = 0;
    
    // Find the maximum value in the bananaPiles array to set the upper limit of the speed
    for (int i = 0; i < numPiles; i++) {
        if (bananaPiles[i] > maxSpeed) {
            maxSpeed = bananaPiles[i];
        }
    }
    
    // Perform binary search to find the minimum speed
    while (minSpeed < maxSpeed) {
        int currentSpeed = (minSpeed + maxSpeed) / 2;
        if (canEatAllBananas(bananaPiles, numPiles, currentSpeed, availableHours)) {
            maxSpeed = currentSpeed;  // Try a smaller speed
        } else {
            minSpeed = currentSpeed + 1;  // Try a larger speed
        }
    }
    
    return minSpeed;  // This will be the minimum speed
}

int main() {
    int bananaPiles[] = {40, 15, 35, 8, 25};  // Example: updated pile sizes
    int numPiles = sizeof(bananaPiles) / sizeof(bananaPiles[0]);
    int availableHours = 7;  // Example: updated available time in hours

    int result = findMinimumSpeed(bananaPiles, numPiles, availableHours);
    printf("Minimum speed to eat all bananas: %d bananas per hour\n", result);
    
    return 0;
}
