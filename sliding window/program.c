#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int k = 3; // Window size

    int sum = 0;
    // Calculate the sum of the first k elements (initial window)
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    printf("Sum of first window: %d\n", sum);

    // Slide the window and update the sum
    for (int i = k; i < n; i++) {
        // Add the next element to the window
        sum += arr[i];
        // Remove the first element from the window
        sum -= arr[i - k];
        printf("Sum of window ending at %d: %d\n", i, sum);
    }

    return 0;
}