#include <stdio.h>

/**
 * Swaps two integer values.
 * 
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Performs selection sort on an array of integers.
 * 
 * Selection Sort works by repeatedly finding the minimum element
 * from the unsorted part of the array and putting it at the beginning.
 * 
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
    }
}

/**
 * Prints the elements of an array.
 * 
 * @param arr The array to be printed.
 * @param n The number of elements in the array.
 */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}