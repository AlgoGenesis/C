#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxCoins(int* nums, int numsSize) {
    // Create a new array with virtual balloons
    int newSize = numsSize + 2;
    int* balloons = (int*)malloc(newSize * sizeof(int));
    
    // Initialize the new array
    balloons[0] = 1; // Virtual balloon
    balloons[newSize - 1] = 1; // Virtual balloon
    for (int i = 0; i < numsSize; i++) {
        balloons[i + 1] = nums[i];
    }

    // Create the dp array
    int** dp = (int**)malloc(newSize * sizeof(int*));
    for (int i = 0; i < newSize; i++) {
        dp[i] = (int*)malloc(newSize * sizeof(int));
    }

    // Fill the dp array
    for (int length = 1; length <= numsSize; length++) {
        for (int left = 1; left <= numsSize - length + 1; left++) {
            int right = left + length - 1;
            for (int i = left; i <= right; i++) {
                int coins = balloons[left - 1] * balloons[i] * balloons[right + 1] + 
                            dp[left][i - 1] + dp[i + 1][right];
                dp[left][right] = max(dp[left][right], coins);
            }
        }
    }

    int result = dp[1][numsSize];
    
    // Free allocated memory
    for (int i = 0; i < newSize; i++) {
        free(dp[i]);
    }
    free(dp);
    free(balloons);

    return result;
}

int main() {
    int nums[] = {3, 1, 5, 8};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = maxCoins(nums, size);
    printf("Maximum coins collected: %d\n", result);
    return 0;
}
