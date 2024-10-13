#include <stdio.h>

// Function to compare and swap elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform the Bitonic Merge
void bitonic_merge(int arr[], int low, int cnt, int dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++) {
            if (dir == (arr[i] > arr[i + k])) {
                swap(&arr[i], &arr[i + k]);
            }
        }
        bitonic_merge(arr, low, k, dir);
        bitonic_merge(arr, low + k, k, dir);
    }
}

// Function to create a Bitonic sequence
void bitonic_sort(int arr[], int low, int cnt, int dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        bitonic_sort(arr, low, k, 1); // Sort in ascending order
        bitonic_sort(arr, low + k, k, 0); // Sort in descending order
        bitonic_merge(arr, low, cnt, dir);
    }
}

// Function to initiate Bitonic Sort
void sort(int arr[], int n, int up) {
    bitonic_sort(arr, 0, n, up);
}

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {10, 3, 2, 8, 6, 4, 5, 1, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    sort(arr, n, 1); // 1 for ascending order, 0 for descending order

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}

