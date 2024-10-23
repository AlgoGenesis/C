#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bead_sort(int *arr, int n) {
    int max = arr[0];
    
    // Find the maximum value in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Create a bead grid with dimensions max (height) x n (width)
    unsigned char beads[n][max];
    memset(beads, 0, sizeof(beads)); // Initialize bead grid with zeros

    // Mark the beads in the grid based on the values of the array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i]; j++) {
            beads[i][j] = 1; // Place beads vertically
        }
    }

    // Perform the bead sort by dropping the beads to the bottom of each column
    for (int j = 0; j < max; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += beads[i][j]; // Count how many beads are in each column
            beads[i][j] = 0;    // Clear the column
        }
        
        // Drop the beads down
        for (int i = n - sum; i < n; i++) {
            beads[i][j] = 1;
        }
    }

    // Update the original array with the sorted values
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < max; j++) {
            if (beads[i][j]) {
                count++;
            }
        }
        arr[i] = count;
    }
}

int main() {
    int arr[] = {5, 3, 1, 7, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bead_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
