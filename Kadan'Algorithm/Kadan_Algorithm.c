// C program to implement Kadan's Algorithm
#include <stdio.h>

int kadane(int arr[], int n) {
    int max_current = arr[0];
    int max_global = arr[0];

    for (int i = 1; i < n; i++) {
        max_current = (arr[i] > max_current + arr[i]) ? arr[i] : (max_current + arr[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    return max_global;
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the maximum sum using Kadane's algorithm
    int max_sum = kadane(arr, n);

    // Output the result
    printf("The maximum sum of a contiguous subarray is: %d\n", max_sum);

    return 0;
}
