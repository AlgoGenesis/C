#include <stdio.h>

// Function to perform Cocktail Shaking Sort
void cocktailShakingSort(int arr[], int n) {
    int swapped = 1;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = 0;

        // Traverse the array from left to right
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                // Swap the elements
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        // If no elements were swapped, the array is sorted
        if (!swapped)
            break;

        swapped = 0;
        end--;

        // Traverse the array from right to left
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                // Swap the elements
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        start++;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {5, 1, 4, 2, 8, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    cocktailShakingSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
