#include <stdio.h>

// Function to determine the maximum amount of money that can be robbed
int houseRobber(int* nums, int n) {
    // Base cases
    if (n == 0) return 0;           // No houses, no money
    if (n == 1) return nums[0];     // Only one house, rob it

    // Dynamic programming array to store the maximum money that can be robbed up to each house
    int dp[n];
    
    // Initialize the first two houses
    dp[0] = nums[0]; // Maximum money from the first house
    dp[1] = (nums[0] > nums[1]) ? nums[0] : nums[1]; // Maximum from the first two houses
 
    // Fill the dp array for houses from index 2 to n-1
    for (int i = 2; i < n; i++) {
        // Max of not robbing this house (dp[i-1]) vs. robbing this house (dp[i-2] + nums[i])
        dp[i] = (dp[i-1] > dp[i-2] + nums[i]) ? dp[i-1] : dp[i-2] + nums[i];
    }

    // The last element in dp array contains the result for all houses
    return dp[n-1];
}

int main() {
    // Example array representing the amount of money in each house
    int nums[] = {2, 7, 9, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]); // Determine the number of houses
    
    // Calculate and print the maximum amount of money that can be robbed
    printf("Maximum amount of money robbed: %d\n", houseRobber(nums, n));
    
    return 0; // Successful completion of the program
}
