# Maximum Subarray Problem - Kadane’s Algorithm

## Problem Statement
The **Maximum Subarray Problem** involves finding the contiguous subarray within a one-dimensional array of numbers that has the largest sum. This problem can be efficiently solved using Kadane's Algorithm.

### Example
Given the array `[-2,1,-3,4,-1,2,1,-5,4]`, the maximum subarray is `[4,-1,2,1]`, with a sum of `6`.

## Algorithm Overview
1. **Initialization**: Start with two variables, `maxCurrent` and `maxGlobal`, both initialized to the first element of the array.
2. **Iterate through the array**:
   - For each element, calculate the maximum sum of the subarray that ends at that element using the formula:
     ```
     maxCurrent = max(nums[i], maxCurrent + nums[i])
     ```
   - Update `maxGlobal` if `maxCurrent` exceeds it.
3. **Return** `maxGlobal`, which contains the maximum sum of all contiguous subarrays.

### Pseudocode
```c
function maxSubArray(nums): 
    maxCurrent = nums[0]
    maxGlobal = nums[0]

    for i from 1 to length of nums - 1:
        maxCurrent = max(nums[i], maxCurrent + nums[i])
        if maxCurrent > maxGlobal:
            maxGlobal = maxCurrent

return maxGlobal
```

## Time Complexity
- **Time Complexity**: `O(n)`
  - Where `n` is the number of elements in the array, as we make a single pass through the array.
- **Space Complexity**: `O(1)`
  - We only use a constant amount of space for variables `maxCurrent` and `maxGlobal`.
