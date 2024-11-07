#include <stdio.h>
#include <limits.h>

int maxSubArraySum(int arr[], int n) {
    int max_sum = INT_MIN;  // Initialize max_sum to the smallest integer
    int current_sum = 0;

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];
        
        // Update max_sum if current_sum is greater than max_sum
        if (current_sum > max_sum)
            max_sum = current_sum;

        // Reset current_sum to zero if it drops below zero
        if (current_sum < 0)
            current_sum = 0;
    }

    return max_sum;
}

int main() {
    int n;
    
    // Taking input for array size
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    
    // Taking input for each array element
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = maxSubArraySum(arr, n);

    printf("Maximum subarray sum is %d\n", max_sum);
    return 0;
}

/*
Example Inputs and Expected Outputs:

1. Input:
   Enter the number of elements in the array: 9
   Enter the elements of the array:
   -2 1 -3 4 -1 2 1 -5 4
   Output:
   Maximum subarray sum is 6
   Explanation: The subarray [4, -1, 2, 1] has the maximum sum of 6.

2. Input:
   Enter the number of elements in the array: 5
   Enter the elements of the array:
   1 2 3 4 -10
   Output:
   Maximum subarray sum is 10
   Explanation: The subarray [1, 2, 3, 4] has the maximum sum of 10.

3. Input:
   Enter the number of elements in the array: 6
   Enter the elements of the array:
   -1 -2 -3 -4 -5 -6
   Output:
   Maximum subarray sum is -1
   Explanation: Since all numbers are negative, the maximum subarray sum is the highest individual element, which is -1.
*/
