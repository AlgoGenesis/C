#include <stdio.h>
// A helper function for binary search in the range [left, right]
int binarySearch(int arr[], int left, int right, int target) {
    // Continue the search as long as the left index is less than or equal to the right index
    while (left <= right) {
        // Calculate the middle index to divide the range into two halves
        int mid = left + (right - left) / 2;

        // If the middle element is the target, return the index
        if (arr[mid] == target)
            return mid;

        // If the target is smaller than the middle element, discard the right half
        if (arr[mid] > target)
            right = mid - 1;

        // Otherwise, discard the left half
        else
            left = mid + 1;
    }
    // If the target is not found, return -1
    return -1;
}

// The main function for exponential search
int exponentialSearch(int arr[], int n, int target) {
    // First, check if the target is the first element
    if (arr[0] == target)
        return 0;

    // Find the range where the target might be present by doubling the index
    int i = 1;
    while (i < n && arr[i] <= target)  // Stop when index exceeds array size or target is smaller than arr[i]
        i = i * 2;

    // Perform binary search within the found range
    // The range is from the previous `i / 2` to `min(i, n-1)`
    return binarySearch(arr, i / 2, (i < n) ? i : n - 1, target);
}

int main() {
    // Example sorted array
    int arr[] = {2, 3, 4, 10, 40, 50, 80, 100};
    int n = sizeof(arr) / sizeof(arr[0]);  // Get the size of the array
    int target = 10;                       // The element we are searching for

    // Perform exponential search for the target
    int result = exponentialSearch(arr, n, target);

    // Print the result
    if (result == -1)
        printf("Element not found in array\n");
    else
        printf("Element found at index %d\n", result);

    return 0;
}
// Target 10 found at the index 3.