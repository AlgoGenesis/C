#include <stdio.h>

void dutchFlagSort(int arr[], int size) {
    int low = 0;       // Pointer for the next position of 0
    int mid = 0;       // Pointer for the current element
    int high = size - 1; // Pointer for the next position of 2

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                // Swap arr[low] and arr[mid]
                int temp0 = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp0;
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                // Swap arr[mid] and arr[high]
                int temp1 = arr[mid];
                arr[mid] = arr[high];
                arr[high] = temp1;
                high--;
                break;
        }
    }
}

int main() {
    int arr[] = {2, 0, 2, 1, 1, 0}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]); // Get the size of the array

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    dutchFlagSort(arr, size); // Sorting the array using the Dutch Flag algorithm

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}