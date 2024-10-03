# Binary Search Algorithm in C (Divide and Conquer)

## Overview

Binary search is an efficient algorithm for finding an element in a sorted array. It works by repeatedly dividing the search interval in half. If the target value is less than the middle element, it searches the left half; otherwise, it searches the right half.

## How it Works

1. **Input**: A sorted array of integers and a target value to search for.
2. **Output**: The index of the target element in the array, or `-1` if the element is not present.
3. **Algorithm**:
   - Divide the array into two halves.
   - Compare the middle element with the target.
   - If they match, return the index.
   - If the target is smaller, repeat the process for the left half.
   - If the target is larger, repeat the process for the right half.

## Code

Here’s the implementation of Binary Search in C:

```c
#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is smaller than mid, it must be in the left subarray
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        // Else the target must be in the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }

    // Target is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in the array\n");
    return 0;
}
