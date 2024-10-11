#include <stdio.h>

// Function to perform ternary search
int ternarySearch(int arr[], int low, int high, int target) {
    if (high >= low) {
        // Calculate mid1 and mid2
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        // Check if target is present at mid1
        if (arr[mid1] == target) {
            return mid1;
        }
        // Check if target is present at mid2
        if (arr[mid2] == target) {
            return mid2;
        }

        // If target is in left one-third
        if (target < arr[mid1]) {
            return ternarySearch(arr, low, mid1 - 1, target);
        }
        // If target is in right one-third
        else if (target > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, high, target);
        }
        // If target is in middle one-third
        else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
        }
    }
    // Target is not present in the array
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int result = ternarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}