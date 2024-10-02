# Partition Equal Subset Sum

## Description

This project implements an algorithm to solve the Partition Equal Subset Sum problem, which determines whether a given set of integers can be partitioned into two subsets such that the sum of the elements in both subsets is equal.

### Problem Definition

Given an array of integers, the task is to decide whether it is possible to partition the array into two subsets with equal sum. If the total sum of the array is odd, it is impossible to split it into two equal subsets, as you cannot have two equal integers that sum to an odd number. Therefore, the problem can be restated as finding whether there exists a subset of the array that sums up to half of the total sum.

### Algorithm Overview

The algorithm uses dynamic programming to solve the problem efficiently. It defines a boolean array `dp` where `dp[j]` indicates whether a subset with sum `j` can be formed from the given set of integers.

#### Steps
1. Calculate the total sum of the array. If it's odd, return false.
2. Define the target sum as `target = total_sum / 2`.
3. Create a boolean array `dp` of size `target + 1`, initialized to false, with `dp[0]` set to true.
4. For each number in the array, update the `dp` array from right to left to ensure that each number is only considered once.
5. The result will be in `dp[target]`, indicating whether the subset sum can be achieved.

### Time Complexity

The time complexity of the algorithm is O(n * sum), where `n` is the number of elements in the array and `sum` is the total sum of the array. The space complexity is O(sum) for the `dp` array.




