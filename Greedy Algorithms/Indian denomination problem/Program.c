#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (for qsort)
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in decreasing order
}

int main() {
    // Array of currency notes
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(arr) / sizeof(arr[0]); // Number of currency notes

    // Amount to be made
    int amt;
    printf("Enter amount: ");
    scanf("%d", &amt);

    // Sort the array in decreasing order
    qsort(arr, n, sizeof(int), compare);

    int sum = 0; // Total number of notes
    int *result = (int *)malloc(amt * sizeof(int)); // Allocate memory for result array
    int result_size = 0; // Size of result array

    // Calculate the number of notes needed
    for (int i = 0; i < n; i++) {
        int k = amt / arr[i]; // Number of notes of this denomination
        sum += k; // Add to total notes
        for (int j = 0; j < k; j++) {
            result[result_size++] = arr[i]; // Store each note
        }
        amt = amt - arr[i] * (amt / arr[i]); // Update the remaining amount
    }

    printf("%d\n", sum); // Print total number of notes
    for (int i = 0; i < result_size; i++) {
        printf("%d ", result[i]); // Print each note used
    }
    printf("\n");

    free(result); // Free allocated memory
    return 0;
}
