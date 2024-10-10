#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Size of the array

// Function to compare elements
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to sort and merge
void cubeSort(int *array, int size) {
    // Sorting each stripe (here, the entire array is a single stripe)
    qsort(array, size, sizeof(int), compare);

    // Merging would be more complex in a true parallel implementation
    // For this example, we assume a single stripe
}

int main() {
    int array[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i;

    printf("Original array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Applying CubeSort
    cubeSort(array, SIZE);

    printf("Sorted array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}