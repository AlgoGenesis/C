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


// Recursive function to perform binary search
int recursiveBinarySearch(int arr[], int left, int right, int x) {
    // Base case: when the left index exceeds the right index
    if (left > right) {
        return -1; // Element is not present in the array
    }

    // Calculate the middle index
    int mid = left + (right - left) / 2;

    // Check if the target element x is present at mid
    if (arr[mid] == x) {
        return mid; // Return the index where the element is found
    }

    // If x is smaller than mid element, it can only be in the left subarray
    if (arr[mid] > x) {
        return recursiveBinarySearch(arr, left, mid - 1, x); // Recur on the left subarray
    }

    // If x is larger than mid element, it can only be in the right subarray
    return recursiveBinarySearch(arr, mid + 1, right, x); // Recur on the right subarray
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


    // Perform recursive binary search
    int recursiveResult = recursiveBinarySearch(arr, 0, n - 1, x);
    if (recursiveResult != -1) {
        printf("Recursive: Element found at index: %d\n", recursiveResult);
    } else {
        printf("Recursive: Element not found in the array.\n");
    }

    return 0;
}