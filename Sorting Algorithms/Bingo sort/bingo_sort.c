#include <stdio.h>

// Function to perform Bingo Sort
void bingoSort(int arr[], int n) {
    int largest, next_largest, last_index;

    // Find the largest element in the array
    largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];
    }

    // Start sorting the array
    next_largest = largest;
    last_index = n - 1;

    while (last_index > 0) {
        int new_largest = -1;

        // Traverse the array and place the largest elements at their correct position
        for (int i = 0; i <= last_index; i++) {
            if (arr[i] == next_largest) {
                int temp = arr[i];
                arr[i] = arr[last_index];
                arr[last_index] = temp;
                last_index--;
            } else if (arr[i] > new_largest) {
                new_largest = arr[i];
            }
        }

        next_largest = new_largest;  // Update the next largest element
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
    int arr[] = {35, 20, 15, 50, 45, 30, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bingoSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
