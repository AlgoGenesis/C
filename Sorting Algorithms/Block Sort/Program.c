#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to perform Block Sort
void block_sort(int arr[], int n) {
    int block_size = (int)sqrt(n);  // Determine the block size
    int num_blocks = (n + block_size - 1) / block_size;  // Calculate number of blocks

    // Sort each block
    for (int i = 0; i < num_blocks; i++) {
        int start = i * block_size;
        int end = start + block_size < n ? start + block_size : n;

        qsort(arr + start, end - start, sizeof(int), compare);
    }

    // Final sorting of the entire array
    qsort(arr, n, sizeof(int), compare);
}

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {3, 6, 1, 4, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    print_array(arr, n);

    block_sort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
