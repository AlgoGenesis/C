#include <stdio.h>
#include <stdlib.h>
void moveZeroesToEnd(int arr[], int n) {
    int j = 0;  // Pointer for the next non-zero element

    // Traverse the array
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            // Swap the current element with the element at index j
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;  // Increment j to point to the next position for non-zero element
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    moveZeroesToEnd(arr, n);

    printf("\nArray after moving zeroes: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
