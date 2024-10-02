#include <stdio.h>
#include <stdlib.h>

int canPartition(int* nums, int numsSize) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    // If the total sum is odd, cannot partition into equal subsets
    if (totalSum % 2 != 0) {
        return 0; // false
    }

    int target = totalSum / 2;
    int* dp = (int*)malloc((target + 1) * sizeof(int));
    
    // Initialize dp array
    for (int j = 0; j <= target; j++) {
        dp[j] = 0;
    }
    dp[0] = 1; // There is always a subset with sum 0

    // Fill the dp array
    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    int result = dp[target];

    // Free allocated memory
    free(dp);
    
    return result; // Returns 1 if partition is possible, 0 otherwise
}

int main() {
    int nums[] = {1, 5, 11, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = canPartition(nums, size);
    if (result) {
        printf("The array can be partitioned into two subsets with equal sum.\n");
    } else {
        printf("The array cannot be partitioned into two subsets with equal sum.\n");
    }
    return 0;
}
