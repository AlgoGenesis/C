#include <stdio.h>

/**
 * Performs Shell sort on an array of integers.
 * 
 * Shell Sort is an optimization over insertion sort. It starts by sorting
 * pairs of elements far apart from each other, then progressively reducing
 * the gap between elements to be compared.
 * 
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void shellSort(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i++) {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
            int j;
            
            // shift earlier gap-sorted elements up until the correct location for a[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    shellSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}