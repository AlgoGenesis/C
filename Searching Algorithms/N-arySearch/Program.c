#include <stdio.h>

// Function to perform n-ary search
int nArySearch(int arr[], int size, int target, int n) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        // Divide the range [low, high] into n parts
        int step = (high - low + 1) / n;

        // Track the points for the n divisions
        int points[n+1];
        points[0] = low;
        for (int i = 1; i < n; i++) {
            points[i] = low + i * step;
        }
        points[n] = high + 1; // to handle last part

        // Compare target with the elements at division points
        for (int i = 0; i < n; i++) {
            if (arr[points[i]] == target) {
                return points[i]; // Target found
            } else if (arr[points[i]] > target) {
                high = points[i] - 1; // Focus on left portion
                break;
            } else if (i == n - 1) {
                low = points[i] + 1; // Focus on the last right portion
            }
        }
    }

    return -1; // Target not found
}

int main() {
    // Example array (sorted)
    int arr[] = {1, 5, 9, 14, 20, 25, 30, 35, 40, 45, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 25;
    int n = 4; // Dividing the search space into 3 parts

    int result = nArySearch(arr, size, target, n);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}