#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function implementing Dutch National Flag Algorithm
void dutchFlagSort(int arr[], int n) {
    int low = 0;      // Starting index of the array
    int mid = 0;      // Current element being checked
    int high = n - 1; // Ending index of the array

    // Traverse the array and arrange the elements
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else if (arr[mid] == 2) {
            swap(&arr[high], &arr[mid]);
            high--;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    dutchFlagSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
