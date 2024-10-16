 ## Kadan's Algorithm

## Description
Kadane's Algorithm is an efficient technique used to find the maximum sum of a contiguous subarray within a one-dimensional array of integers. It is particularly useful in scenarios where the input array may contain both positive and negative numbers. By leveraging a dynamic programming approach, Kadane's Algorithm can identify the maximum sum in linear time, making it optimal for large datasets.

### Problem Definition
Given an array of integers arr[], the objective is to determine the contiguous subarray (a subarray that consists of consecutive elements) that has the largest sum. The algorithm should return this maximum sum.

Input: An array of integers, which may contain both positive and negative values.
Output: A single integer representing the maximum sum of any contiguous subarray within the input array.


### Algorithm Overview
1) Initialization:
>Start by initializing two variables:
    .max_current to the first element of the array. This variable keeps track of the maximum sum of the subarray ending at the current index.
    .max_global to the same value. This variable records the overall maximum sum found so far.

2) Iterate Through the Array:
>For each element in the array (starting from the second element), update max_current:
    .Set max_current to the maximum of the current element and the sum of max_current plus the current element. This checks whether to include the current element in the existing subarray or start a new subarray.
>If max_current exceeds max_global, update max_global to the value of max_current.

3) Result:
>After processing all elements, max_global contains the maximum sum of any contiguous subarray.


### Time Complexity
>Best Case: 
O(n) – The algorithm will still iterate through the entire array regardless of the values.
>Average Case: 
O(n) – The linear traversal applies as it evaluates each element once.
>Worst Case: 
O(n) – Even in the worst-case scenario (e.g., all negative numbers), the algorithm completes in linear time.