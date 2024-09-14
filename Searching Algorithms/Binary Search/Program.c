#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate middle index

        // Check if x is present at mid
        if (arr[mid] == x) {
            return mid; // Return the index of the target
        }

        // If x is greater, ignore the left half
        if (arr[mid] < x) {
            left = mid + 1;
        }
        // If x is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 40}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Enter a number to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, n, x);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}