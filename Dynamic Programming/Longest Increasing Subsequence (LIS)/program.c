#include <stdio.h>

int length_of_lis(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int dp[numsSize]; // Array to store the length of LIS ending at each index
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1; // Each element is an LIS of length 1
    }

    // Fill the dp array
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1; // Update the length of LIS at i
            }
        }
    }

    // Find the maximum value in dp array
    int maxLength = 0;
    for (int i = 0; i < numsSize; i++) {
        if (maxLength < dp[i]) {
            maxLength = dp[i];
        }
    }

    return maxLength;
}

int main() {
    int nums[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = length_of_lis(nums, size);
    printf("Length of Longest Increasing Subsequence: %d\n", result);
    return 0;
}
