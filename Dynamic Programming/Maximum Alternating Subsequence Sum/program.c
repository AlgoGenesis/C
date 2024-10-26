//This program finds the maximum alternating subsequence sum for a given input array
//Alternating susequence sum is difference btw sum of elements at even indices and sum of elements at odd indices
//within the subsequence

#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum alternating subsequence sum
int doSomething(int* nums, int n) {
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        dp[i] = (int*)malloc(2 * sizeof(int));
    }

    dp[0][0] = nums[0];  
    dp[0][1] = 0;        

    for (int i = 1; i < n; ++i) {
        dp[i][0] = (nums[i] + dp[i - 1][1] > dp[i - 1][0]) ? nums[i] + dp[i - 1][1] : dp[i - 1][0];
        dp[i][1] = (-nums[i] + dp[i - 1][0] > dp[i - 1][1]) ? -nums[i] + dp[i - 1][0] : dp[i - 1][1];
    }

    int result = (dp[n - 1][0] > dp[n - 1][1]) ? dp[n - 1][0] : dp[n - 1][1];

    for (int i = 0; i < n; ++i) {
        free(dp[i]);
    }
    free(dp);

    return result;
}
//Taking input array from user 
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements of the array: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int output = doSomething(arr, n);
    printf("The maximum alternating subsequence sum is: %d\n", output);

    free(arr);
    return 0;
}
