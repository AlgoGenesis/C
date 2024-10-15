#include <stdio.h>
#include <stdlib.h> // Include for dynamic memory functions

// Function to perform binary search
int binarySearch(int arr[], int item, int low, int high) {
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);

    return binarySearch(arr, item, low, mid - 1);
}

// Function to perform binary insertion sort
void binaryInsertionSort(int arr[], int n) {
    int i, loc, j, selected;

    for (i = 1; i < n; ++i) {
        selected = arr[i];

        // Find the location where the element should be inserted
        loc = binarySearch(arr, selected, 0, i - 1);

        // Move all elements after location to one position ahead
        for (j = i - 1; j >= loc; --j)
            arr[j + 1] = arr[j];

        arr[loc] = selected;
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

    // Ask user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Input the elements of the array
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);

    binaryInsertionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    // Free the allocated memory
    free(arr);

    return 0;
}
