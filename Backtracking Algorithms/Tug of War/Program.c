#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to calculate the total sum of the array
int calculateTotalSum(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to print the subset
void printSubset(int* arr, int* subset, int size) {
    for (int i = 0; i < size; i++) {
        if (subset[i] == 1) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

// Utility function to solve the Tug of War problem using backtracking
void tugOfWarUtil(int* arr, int* curr_set, int curr_size, int* best_set, int* min_diff, int total_sum, int curr_sum, int pos, int n) {
    // Base case: If we've selected half the elements
    if (curr_size == n / 2) {
        int diff = abs((total_sum - curr_sum) - curr_sum);
        if (diff < *min_diff) {
            *min_diff = diff;
            for (int i = 0; i < n; i++) {
                best_set[i] = curr_set[i];
            }
        }
        return;
    }

    // If no more elements are left to process
    if (pos == n) {
        return;
    }

    // Include the current element in the current subset and recurse
    curr_set[pos] = 1;
    tugOfWarUtil(arr, curr_set, curr_size + 1, best_set, min_diff, total_sum, curr_sum + arr[pos], pos + 1, n);

    // Exclude the current element and recurse
    curr_set[pos] = 0;
    tugOfWarUtil(arr, curr_set, curr_size, best_set, min_diff, total_sum, curr_sum, pos + 1, n);
}

// Main function to solve the Tug of War problem
void tugOfWar(int* arr, int n) {
    // Array to store the current subset being explored
    int* curr_set = (int*)malloc(n * sizeof(int));

    // Array to store the best subset found
    int* best_set = (int*)malloc(n * sizeof(int));

    // Initialize both arrays
    for (int i = 0; i < n; i++) {
        curr_set[i] = best_set[i] = 0;
    }

    // Calculate the total sum of the elements
    int total_sum = calculateTotalSum(arr, n);

    // Variable to track the minimum difference
    int min_diff = INT_MAX;

    // Call the utility function to solve the problem using backtracking
    tugOfWarUtil(arr, curr_set, 0, best_set, &min_diff, total_sum, 0, 0, n);

    // Print the first subset (the one selected as best)
    printf("Subset 1: ");
    printSubset(arr, best_set, n);

    // Print the second subset (complement of the first subset)
    printf("Subset 2: ");
    for (int i = 0; i < n; i++) {
        if (best_set[i] == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    // Free dynamically allocated memory
    free(curr_set);
    free(best_set);
}

int main() {
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    tugOfWar(arr, n);

    return 0;
}