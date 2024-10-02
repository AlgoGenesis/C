#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int minIndex, temp;

    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        minIndex = i; // Find the minimum element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array : ");
    printArray(arr, n);

    // Perform Selection Sort
    selectionSort(arr, n);
    printf("Sorted array : ");
    printArray(arr, n);

    return 0;
}