# Partition Equal Subset Sum - Dynamic Programming

## Problem Statement
The **Partition Equal Subset Sum** problem asks whether a given array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

### Example
Given the array: {1, 5, 11, 5}
The array can be partitioned into:
- Subset 1: {1, 5, 5} with sum = 11
- Subset 2: {11} with sum = 11

So, the output is `true`.

If the array is: {1, 2, 3, 5}
It cannot be partitioned into two subsets with equal sum, so the output is `false`.

## Algorithm Overview
1. **Calculate the Total Sum**: Find the sum of all elements in the array. If the sum is odd, it is not possible to partition the array into two subsets with equal sum.
2. **Define the Target Sum**: Set `target = sum/2`. This is the sum that each subset needs to achieve.
3. **Dynamic Programming Approach**:
   - Use a 1D array `dp[]` where `dp[j]` is `true` if a subset with sum `j` can be formed from the elements of the array.
   - Initialize `dp[0] = true` because a sum of 0 can always be achieved.
   - For each element in the array, update the `dp[]` array in reverse to avoid using the same element multiple times.

### Pseudocode
```
function canPartition(nums, numsSize):
 sum = 0 
 for each element in nums:
  sum += element
    if sum is odd:
        return false

target = sum / 2
create an array dp of size (target + 1) and set all values to false
dp[0] = true
 
for each element in nums:
    for j from target down to element:
        dp[j] = dp[j] or dp[j - element]

return dp[target]
```


## Time Complexity
- **Time Complexity**: `O(n * target)`
  - Where `n` is the number of elements in the array and `target` is `sum/2`.
  - The nested loop processes each element and updates the `dp[]` array up to `target`.
- **Space Complexity**: `O(target)`
  - The `dp[]` array requires additional space proportional to the value of `target`.


