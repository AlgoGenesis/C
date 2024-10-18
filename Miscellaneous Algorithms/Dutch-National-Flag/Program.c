#include <stdio.h>

// Function to perform the Dutch National Flag algorithm
void dutchNationalFlag(int arr[], int size) {
    int low = 0;      // Pointer for the first category (e.g., red)
    int mid = 0;      // Pointer for the second category (e.g., white)
    int high = size - 1; // Pointer for the third category (e.g., blue)

    while (mid <= high) {
        switch (arr[mid]) {
            case 0: // The first category (e.g., red)
                // Swap low and mid elements
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
                break;
            case 1: // The second category (e.g., white)
                mid++;
                break;
            case 2: // The third category (e.g., blue)
                // Swap mid and high elements
                temp = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp;
                high--;
                break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {2, 0, 2, 1, 1, 0}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, size);

    dutchNationalFlag(arr, size);

    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}