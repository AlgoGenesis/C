#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to check if it is possible to place cows with at least 'dist' distance apart
int canPlaceCows(int* stalls, int stallsSize, int cows, int dist) {
    int count = 1; // Place the first cow in the first stall
    int lastPosition = stalls[0];

    for (int i = 1; i < stallsSize; i++) {
        if (stalls[i] - lastPosition >= dist) {
            count++; // Place the next cow
            lastPosition = stalls[i]; // Update the last position
            if (count == cows) {
                return 1; // Successfully placed all cows
            }
        }
    }
    return 0; // Not possible to place all cows
}

// Function to find the largest minimum distance
int aggressiveCows(int* stalls, int stallsSize, int cows) {
    // Sort the stalls
    qsort(stalls, stallsSize, sizeof(int), compare);

    int left = 1; // Minimum possible distance
    int rightout = stalls[stallsSize - 1] - stalls[0]; // Maximum possible distance
    int bestDistance = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlaceCows(stalls, stallsSize, cows, mid)) {
            bestDistance = mid; // Update best distance found
            left = mid + 1; // Try for a larger distance
        } else {
            right = mid - 1; // Try for a smaller distance
        }
    }

    return bestDistance; // Return the largest minimum distance found
}

int main() {
    int stalls[] = {1, 2, 8,6,4, 9}; // Example stalls
    int cows = 3; // Number of cows
    int size = sizeof(stalls) / sizeof(stalls[0]);

    int resultout = aggressiveCows(stalls, size, cows);
    printf("The largest minimum distance is: %d\n", result);

    return 0;
}