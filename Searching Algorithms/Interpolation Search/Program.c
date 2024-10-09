#include <stdio.h>

int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        // Estimate the position
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        // Check if the target is found
        if (arr[pos] == target) {
            return pos;
        }

        // If target is larger, target is in the upper part
        if (arr[pos] < target) {
            low = pos + 1;
        }
        // If target is smaller, target is in the lower part
        else {
            high = pos - 1;
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 18;
    int index = interpolationSearch(arr, n, target);

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}