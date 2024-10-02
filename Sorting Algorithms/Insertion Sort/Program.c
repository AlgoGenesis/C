#include <stdio.h>

// Basic Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Optimized Insertion Sort (using binary search)
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

void optimizedInsertionSort(int arr[], int n) {
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = arr[i];

        loc = binarySearch(arr, selected, 0, j);

        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    // Reset array for optimized version
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};

    printf("Original array (for optimized version): \n");
    printArray(arr2, n);

    optimizedInsertionSort(arr2, n);

    printf("Sorted array (optimized version): \n");
    printArray(arr2, n);

    return 0;
}