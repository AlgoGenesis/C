// C program to find maximum Subarray Sum in Circular
// subarray by considering all possible subarrays

#include <stdio.h>

int circularSubarraySum(int arr[], int n) {
    int totalSum = 0;    
    int currMaxSum = 0, currMinSum = 0;
    int maxSum = arr[0], minSum = arr[0];
    
    for(int i = 0; i < n; i++) {
      
        // Kadane's to find maximum sum subarray
        currMaxSum = (currMaxSum + arr[i] > arr[i]) ? 
                              currMaxSum + arr[i] : arr[i];
        maxSum = (maxSum > currMaxSum) ? maxSum : currMaxSum; 
        
        // Kadane's to find minimum sum subarray
        currMinSum = (currMinSum + arr[i] < arr[i]) ? 
                                  currMinSum + arr[i] : arr[i];
        minSum = (minSum < currMinSum) ? minSum : currMinSum;
        
        // Sum of all the elements of input array
        totalSum += arr[i];
    }
    
    int normalSum = maxSum;
    int circularSum = totalSum - minSum;
    
    // If the minimum subarray is equal to total Sum
    // then we just need to return normalSum
    if(minSum == totalSum)
        return normalSum;
    
    return (normalSum > circularSum) ? normalSum : circularSum;
}

int main() {
    int arr[] = {8, -8, 9, -9, 10, -11, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", circularSubarraySum(arr, n));
    return 0;
}
