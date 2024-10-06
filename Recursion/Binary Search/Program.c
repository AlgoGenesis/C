#include <stdio.h>

// Recursive function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    // Base case: if the left index exceeds the right index
    if (left > right) {
        return -1; // Target not found
    }

    // Calculate the mid index
    int mid = left + (right - left) / 2;

    // Check if the target is present at mid
    if (arr[mid] == target) {
        return mid; // Target found
    }
    // If target is smaller than mid, search the left half
    else if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    }
    // If target is larger than mid, search the right half
    else {
        return binarySearch(arr, mid + 1, right, target);
    }
}

int main() {
    int arr[] = {2, 3, 4, 10, 40}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10; // Target value to search for

    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}