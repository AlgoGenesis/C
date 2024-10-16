// Sorting of array list using Comb sort
#include <stdio.h>
#include <stdlib.h>

void combSort(int arr[], int n) {
    float shrinkFactor = 1.3;
    int gap = n;
    int swapped = 1;

    while (gap > 1 || swapped) {
        if (gap > 1) {
            gap /= shrinkFactor; // Shrink the gap
        }
        swapped = 0;

        for (int i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                // Swap elements
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = 1;
            }
        }
    }
}

// function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Handle edge case for negative or zero size
    if (n <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: \n");
    printArray(arr, n);

    // Sort the array using Comb Sort
    combSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
