#include <stdio.h>

// Function to find the maximum subarray sum using Kadane's Algorithm
int maxSubArray(int* nums, int numsSize) {
    int maxCurrent = nums[0];
    int maxGlobal = nums[0];

    for (int i = 1; i < numsSize; i++) {
        maxCurrent = (nums[i] > maxCurrent + nums[i]) ? nums[i] : (maxCurrent + nums[i]);
        if (maxCurrent > maxGlobal) {
            maxGlobal = maxCurrent;
        }
    }

    return maxGlobal;
}

int main() {
    int nums[1000];
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int maxSum = maxSubArray(nums, n);
    printf("Maximum subarray sum: %d\n", maxSum);

    return 0;
}
