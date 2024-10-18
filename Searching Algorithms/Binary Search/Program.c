#include <stdio.h>

// Function to perform iterative binary search
int binarySearch(const int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Calculate middle index

        if (arr[mid] == x) {
            return mid;  // Return the index of the target
        }

        if (arr[mid] < x) {
            left = mid + 1;  // Ignore the left half
        } else {
            right = mid - 1;  // Ignore the right half
        }
    }

    return -1;  // Target not found
}

// Recursive function to perform binary search
int recursiveBinarySearch(const int arr[], int left, int right, int x) {
    if (left > right) {
        return -1;  // Base case: Element not found
    }

    int mid = left + (right - left) / 2;  // Calculate middle index

    if (arr[mid] == x) {
        return mid;  // Return the index if the element is found
    }

    if (arr[mid] > x) {
        return recursiveBinarySearch(arr, left, mid - 1, x);  // Search in the left subarray
    } else {
        return recursiveBinarySearch(arr, mid + 1, right, x);  // Search in the right subarray
    }
}

int main() {
    const int arr[] = {2, 3, 4, 10, 40};  // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    // Prompt for user input with error checking
    printf("Enter a number to search: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;  // Exit if input is invalid
    }

    // Perform iterative binary search
    int result = binarySearch(arr, n, x);
    if (result != -1) {
        printf("Element found at index: %d (Iterative)\n", result);
    } else {
        printf("Element not found in the array (Iterative).\n");
    }

    // Perform recursive binary search (optional if needed)
    int recursiveResult = recursiveBinarySearch(arr, 0, n - 1, x);
    if (recursiveResult != -1) {
        printf("Element found at index: %d (Recursive)\n", recursiveResult);
    } else {
        printf("Element not found in the array (Recursive).\n");
    }

    return 0;
}
