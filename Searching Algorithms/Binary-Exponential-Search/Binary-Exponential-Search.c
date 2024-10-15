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
