#include <stdio.h>

// Function to find the maximum sum of subarray of size k
int maxSum(int arr[], int n, int k) {
    // Initialize window sum with the first k elements
    int max_sum = 0, window_sum = 0;
    
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }
    
    max_sum = window_sum;

    // Slide the window from left to right over the array
    for (int i = k; i < n; i++) {
        // Update the window sum by sliding it one element to the right
        window_sum += arr[i] - arr[i - k];
        // Update max_sum if the current window's sum is greater
        if (window_sum > max_sum) {
            max_sum = window_sum;
        }
    }

    return max_sum;
}

int main() {
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the size of the window (k): ");
    scanf("%d", &k);

    if (k > n) {
        printf("Window size k should be less than or equal to array size n.\n");
        return 1;
    }

    int max_sum = maxSum(arr, n, k);
    printf("The maximum sum of a subarray of size %d is: %d\n", k, max_sum);

    return 0;
}
