#include <stdio.h>

// Function to find the maximum sum of non-adjacent elements in an array
int maxSumNonAdjacent(int* nums, int n) {
    // Base cases
    if (n == 0) return 0;         // No elements, sum is 0
    if (n == 1) return nums[0];   // Only one element, return that element

    // Initialize include and exclude
    int include = nums[0];  // Maximum sum including the first element
    int exclude = 0;        // Maximum sum excluding the first element

    // Iterate through the array from the second element to the end
    for (int i = 1; i < n; i++) {
        // New exclude will be the maximum of include or exclude from the previous iteration
        int new_exclude = (include > exclude) ? include : exclude;
        
        // Update include to the sum of current number and exclude from the previous iteration
        include = exclude + nums[i];
        
        // Update exclude to the new exclude
        exclude = new_exclude;
    }

    // Return the maximum of include or exclude
    return (include > exclude) ? include : exclude;
}

int main() {
    // Example array of numbers
    int nums[] = {3, 2, 7, 10};
    int n = sizeof(nums) / sizeof(nums[0]); // Determine the number of elements in the array

    // Calculate and print the maximum sum of non-adjacent elements
    printf("Maximum sum of non-adjacent elements: %d\n", maxSumNonAdjacent(nums, n));
    
    return 0; // Successful completion of the program
}
