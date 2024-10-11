#include <stdio.h>
#include <stdbool.h>

// Function to check if a given array can be partitioned into two subsets with equal sum
bool canPartition(int* nums, int numsSize) {
    int sum = 0;

    // Calculate the sum of all elements in the array
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    // If the total sum is odd, it can't be divided into two equal subsets
    if (sum % 2 != 0)
        return false;

    int target = sum / 2;
    bool dp[target + 1];
    
    // Initialize dp array: dp[0] = true, as a sum of 0 can always be formed
    for (int i = 0; i <= target; i++)
        dp[i] = false;
    dp[0] = true;

    // Process each number in the array
    for (int i = 0; i < numsSize; i++) {
        // Traverse the dp array from the back to the front to avoid reuse of the same element
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    // The value dp[target] will indicate if we can partition the array into two equal subsets
    return dp[target];
}

int main() {
    int nums[] = {1, 5, 11, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (canPartition(nums, numsSize))
        printf("The array can be partitioned into two subsets with equal sum.\n");
    else
        printf("The array cannot be partitioned into two subsets with equal sum.\n");

    return 0;
}
