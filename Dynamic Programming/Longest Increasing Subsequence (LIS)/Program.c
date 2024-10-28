#include <stdio.h>
#include <stdlib.h>

// lis() returns the length of the longest
// increasing subsequence in arr of size n
int lis(const int arr[], int n)
{
    int lis[n];
    for (int i = 0; i < n; i++) {
        lis[i] = 1;
    }

    // Compute optimized LIS values in
    // bottom-up manner
    for (int i = 1; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (arr[i] > arr[prev] && lis[i] < lis[prev] + 1) {
                lis[i] = lis[prev] + 1;
            }
        }
    }

    // Find the maximum value in lis
    int max = lis[0];
    for (int i = 1; i < n; i++) {
        if (lis[i] > max) {
            max = lis[i];
        }
    }

    return max;
}

// Driver program to test the above function
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    printf("Length of lis is %d\n", lis(arr, n));
    return 0;
}