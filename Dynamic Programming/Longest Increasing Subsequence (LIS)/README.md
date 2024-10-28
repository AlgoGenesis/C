# Longest Increasing Subsequence (LIS) - Dynamic Programming

## Problem Statement
The **Longest Increasing Subsequence (LIS)** problem is to find the length of the longest subsequence in a given array such that all elements of the subsequence are sorted in increasing order.

A subsequence is a sequence derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

For example, for the array `{10, 22, 9, 33, 21, 50, 41, 60, 80}`, one of the longest increasing subsequences is `{10, 22, 33, 50, 60, 80}`, and its length is 6.

## Algorithm Overview
1. **Initialization**: Create an array `lis[]` of the same size as the input array and initialize all elements to 1. This is because each element is itself an increasing subsequence of length 1.
2. **Dynamic Programming Step**: Use nested loops to find the LIS values for each index `i` in the array:
   - For each index `i` from 1 to `n-1`, check all indices `j` before `i`.
   - If `arr[i] > arr[j]` and `lis[i] < lis[j] + 1`, update `lis[i]` to `lis[j] + 1`.
3. **Finding the Result**: The length of the longest increasing subsequence is the maximum value in the `lis[]` array.


### Example Walkthrough
For the array `{10, 22, 9, 33, 21, 50, 41, 60, 80}`:

1. Initialize `lis[]` to `{1, 1, 1, 1, 1, 1, 1, 1, 1}`.
2. After filling `lis[]` using the dynamic programming formula:
3. The maximum value in `lis[]` is 6, which is the length of the longest increasing subsequence.

## Time Complexity
- **Time Complexity**: `O(n^2)`
- This complexity arises from the nested loops where each index `i` is compared with all indices `j` before it, resulting in `n * (n-1)/2` comparisons.
- **Space Complexity**: `O(n)`
- The `lis[]` array used to store the LIS values requires additional space proportional to the size of the input array.
