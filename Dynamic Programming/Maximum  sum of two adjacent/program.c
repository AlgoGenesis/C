#include <stdio.h>

// Function to find the maximum sum of non-adjacent elements
int maxSumNonAdjacent(int* nums, int n) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // Initialize two variables to store the maximum sum
    int include = nums[0];  // Sum including the current element
    int exclude = 0;        // Sum excluding the current element

    for (int i = 1; i < n; i++) {
        // Update the sums for include and exclude
        int new_exclude = (include > exclude) ? include : exclude;
        include = exclude + nums[i];
        exclude = new_exclude;
    }

    // Return the maximum of the include and exclude sums
    return (include > exclude) ? include : exclude;
}

int main() {
    int nums[] = {3, 2, 7, 10};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("Maximum sum of non-adjacent elements: %d\n", maxSumNonAdjacent(nums, n));
    return 0;
}
