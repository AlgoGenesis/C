#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to check if the array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// Function to shuffle the array randomly
void shuffle(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int randomIndex = rand() % n;
        // Swap arr[i] with arr[randomIndex]
        int temp = arr[i];
        arr[i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }
}

// Function implementing Bogo Sort
void bogoSort(int arr[], int n) {
    // Keep shuffling the array until it is sorted
    while (!isSorted(arr, n)) {
        shuffle(arr, n);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Seed for random number generator
    srand(time(NULL));
    
    int arr[] = {3, 2, 5, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bogoSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
