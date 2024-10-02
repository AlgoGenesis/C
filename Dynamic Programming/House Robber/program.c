#include <stdio.h>

// Function to find the maximum sum we can rob without robbing two adjacent houses
int houseRobber(int* nums, int n) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // Array to store the maximum money we can rob up to each house
    int dp[n];
    
    // Base cases
    dp[0] = nums[0];
    dp[1] = (nums[0] > nums[1]) ? nums[0] : nums[1];
    
    // Fill the dp array
    for (int i = 2; i < n; i++) {
        dp[i] = (dp[i-1] > dp[i-2] + nums[i]) ? dp[i-1] : dp[i-2] + nums[i];
    }

    // The last element in dp holds the maximum money we can rob
    return dp[n-1];
}

int main() {
    int nums[] = {2, 7, 9, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    printf("Maximum amount of money robbed: %d\n", houseRobber(nums, n));
    return 0;
}