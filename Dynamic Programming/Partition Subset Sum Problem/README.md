# Partition Subset Sum Problem - Dynamic Programming

## Problem Statement
The **Partition Subset Sum Problem** is to determine whether a given array can form a subset whose sum is equal to a specified target value.

## Algorithm Overview
1. **Define the Target Sum**: We need to check if there is a subset in the array whose sum is equal to the given target sum.
2. **Dynamic Programming Approach**:
   - Use a 1D array `dp[]` where `dp[j]` is `true` if a subset with sum `j` can be formed using elements of the array.
   - Initialize `dp[0] = true` because a sum of 0 can always be achieved with no elements.
   - Traverse the `dp[]` array backwards for each element to prevent using the same element multiple times.

### Dynamic Programming Formula
The relationship to update `dp[j]` is: 
dp[j] = dp[j] OR dp[j - nums[i]]
- For every element in the array, if we can achieve a sum `j - nums[i]`, then we can also achieve the sum `j` by adding the current element.

## Time Complexity
- **Time Complexity**: `O(n * targetSum)`
  - Where `n` is the number of elements in the array and `targetSum` is the target sum value.
  - The nested loop processes each element and updates the `dp[]` array up to `targetSum`.
- **Space Complexity**: `O(targetSum)`
  - The `dp[]` array requires additional space proportional to the value of `targetSum`.

## How to Run
1. Save the `partition_subset_sum.c` program file.
2. Open a terminal and navigate to the directory where the file is saved.
3. Compile the program using the following command:
   ```bash
   gcc partition_subset_sum.c -o partition_subset_sum