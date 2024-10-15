# Binary-Exponential Search in C

## Overview

This repository contains an implementation of the **Exponential Search** algorithm in C. Exponential Search is a combination of **exponential range finding** and **binary search**. It is well-suited for searching in sorted arrays where the target element is expected to be closer to the beginning of the array.

The algorithm works as follows:
1. It starts with checking if the element is present at the first position.
2. If not, it exponentially increases the index (by powers of 2) to find the range in which the element might exist.
3. Once the range is identified, it uses binary search to locate the target element.

## Algorithm

1. **Exponential Search**:
   - Begin by checking the element at index 0.
   - Increase the index exponentially until the value at the index exceeds or matches the target or until the end of the array is reached.
   
2. **Binary Search**:
   - Once the exponential range is found, a binary search is performed within that range to find the exact position of the target.

## Code

The algorithm is implemented in `C`. Here's the code:

```c
#include <stdio.h>

// Function for binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Function for exponential search
int exponentialSearch(int arr[], int n, int target) {
    // If the target is at the first position
    if (arr[0] == target)
        return 0;

    // Find the range for binary search by repeated doubling
    int i = 1;
    while (i < n && arr[i] <= target)
        i = i * 2;

    // Perform binary search on the found range
    return binarySearch(arr, i / 2, (i < n) ? i : n - 1, target);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 45, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = exponentialSearch(arr, n, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
