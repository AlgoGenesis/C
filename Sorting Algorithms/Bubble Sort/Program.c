#include <stdio.h>
#include <stdlib.h>

// Function to perform Bubble Sort in ascending order
void bubbleSort(int arr[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        // Flag to detect any swap
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements based on the sorting order
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                // Swap if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set the flag to indicate a swap
            }
        }
        // If no two elements were swapped, the array is sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int *arr;

    // Get the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Ask the user for sorting order
    int ascending;
    printf("Enter 1 for ascending order or 0 for descending order: ");
    scanf("%d", &ascending);

    printf("Original array: \n");
    printArray(arr, n);

    bubbleSort(arr, n, ascending);

    printf("Sorted array: \n");
    printArray(arr, n);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
