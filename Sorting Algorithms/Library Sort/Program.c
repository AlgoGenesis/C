#include <stdio.h>
#include <stdlib.h>

// Function to insert an element into the sorted array with gaps
void insert(int arr[], int *size, int element) {
    int i = *size - 1;
    while (i >= 0 && arr[i] > element) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = element;
    (*size)++;
}

// Function to perform library sort
void library_sort(int arr[], int n) {
    int *sorted = (int *)malloc(2 * n * sizeof(int));
    int size = 0;

    for (int i = 0; i < n; i++) {
        insert(sorted, &size, arr[i]);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }

    free(sorted);
}

// Function to print array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {78, 650, 100, 21, 23, 12, 90, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    print_array(arr, n);

    library_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}