#include <stdio.h>

// Function to perform ternary search on a sorted array
int ternarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        // Calculate the two mid points
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Check if the target is present at any of the midpoints
        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }

        // Check in which region the target may lie and recursively search
        if (target < arr[mid1]) {
            // Target lies in the left part
            return ternarySearch(arr, left, mid1 - 1, target);
        } else if (target > arr[mid2]) {
            // Target lies in the right part
            return ternarySearch(arr, mid2 + 1, right, target);
        } else {
            // Target lies in the middle part
            return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
        }
    }

    // If the target is not present in the array
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 1;
    
    int result = ternarySearch(arr, 0, n - 1, target);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}
