#include <stdio.h>
#include <stdbool.h>

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
 * Performs Cocktail Shaker sort on an array of integers.
 * 
 * Cocktail Shaker Sort is a variation of Bubble sort. It sorts the array
 * by moving in both directions, comparing adjacent elements and swapping
 * them if they are in the wrong order.
 * 
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    cocktailShakerSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}