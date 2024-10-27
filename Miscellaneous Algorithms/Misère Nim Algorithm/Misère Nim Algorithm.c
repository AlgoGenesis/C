#include <stdio.h>

// Function to determine the winner
int misereNim(int piles[], int n) {
    int xorSum = 0;
    int allOnes = 1;

    // Calculate the xor of all pile sizes
    for (int i = 0; i < n; i++) {
        xorSum ^= piles[i];
        if (piles[i] > 1) {
            allOnes = 0; // Not all piles have only one stone
        }
    }

    // Determine the winning condition
    if ((allOnes && xorSum == 0) || (!allOnes && xorSum != 0)) {
        return 1; // First player wins
    } else {
        return 0; // Second player wins
    }
}

int main() {
    int piles[] = {1, 2, 3}; // Example pile configuration
    int n = sizeof(piles) / sizeof(piles[0]);

    if (misereNim(piles, n)) {
        printf("First player wins.\n");
    } else {
        printf("Second player wins.\n");
    }

    return 0;
}
