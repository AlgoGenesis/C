#include <stdio.h>
#include <stdbool.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Cocktail Shaker Sort
void cocktailShakerSort(int arr[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        // Reset the swapped flag on entering the loop,
        // because it might be true from a previous iteration.
        swapped = false;

        // Move from left to right
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }

        // If nothing moved, then array is sorted.
        if (!swapped)
            break;

        // Otherwise, reset the swapped flag so that it
        // can be used in the next stage
        swapped = false;

        // Move from right to left
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }

        // Increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
        ++start;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test Cocktail Shaker Sort
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    cocktailShakerSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}