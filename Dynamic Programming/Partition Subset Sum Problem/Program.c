#include <stdio.h>
#include <stdbool.h>

// Function to determine if a subset with a given sum exists in the array
bool subsetSum(int* nums, int numsSize, int targetSum) {
    // Create a 1D dp array initialized to false
    bool dp[targetSum + 1];
    for (int i = 0; i <= targetSum; i++) {
        dp[i] = false;
    }

    // A sum of 0 can always be achieved by taking no elements
    dp[0] = true;

    // Iterate through each number in the array
    for (int i = 0; i < numsSize; i++) {
        // Traverse the dp array backwards to avoid using the same element multiple times
        for (int j = targetSum; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    // The value dp[targetSum] indicates whether we can achieve the target sum
    return dp[targetSum];
}

int main() {
    int nums[] = {3, 34, 4, 12, 5, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int targetSum = 9;

    if (subsetSum(nums, numsSize, targetSum))
        printf("A subset with sum %d exists in the given array.\n", targetSum);
    else
        printf("No subset with sum %d exists in the given array.\n", targetSum);

    return 0;
}
