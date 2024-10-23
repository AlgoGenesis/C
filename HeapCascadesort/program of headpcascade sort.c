#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain max-heap property by cascading down the heap
void heapify(int arr[], int n, int i) {
    int largest = i;         // Initialize largest as the root
    int left = 2 * i + 1;    // Left child index
    int right = 2 * i + 2;   // Right child index

    // If left child is larger than the root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest element is not the root, swap and cascade down
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);  // Recursively heapify the affected subtree
    }
}

// Function to perform Heap Cascade Sort
void heapSort(int arr[], int n) {
    // Build a max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (largest) to the end
        swap(&arr[0], &arr[i]);

        // Call heapify on the reduced heap to maintain max-heap property
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test Heap Cascade Sort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
