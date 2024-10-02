
# Longest Increasing Subsequence (LIS)

This project implements an algorithm to solve the Longest Increasing Subsequence (LIS) problem, which involves finding the longest subsequence in a given sequence of numbers where the elements of the subsequence are in strictly increasing order.

## Description

### Problem Definition
Given an array of integers, the task is to find the length of the longest subsequence such that all elements of the subsequence are sorted in increasing order. A subsequence is defined as a sequence derived from another sequence by deleting some elements without changing the order of the remaining elements.

### Example
For the input array `[10, 9, 2, 5, 3, 7, 101, 18]`, the longest increasing subsequence is `[2, 3, 7, 101]` with a length of `4`.

### Algorithm Overview
The algorithm uses dynamic programming to solve the LIS problem with a time complexity of O(n²). The main idea is to maintain an array `dp` where `dp[i]` represents the length of the longest increasing subsequence that ends with the element at index `i`. 

#### Steps
1. Initialize a `dp` array with all values set to `1` since the minimum length of LIS for any element is `1` (the element itself).
2. For each element in the array, check all previous elements to find the maximum length of the increasing subsequence that can be formed by including the current element.
3. Update the `dp` array based on the maximum lengths found.
4. The result is the maximum value in the `dp` array, which represents the length of the longest increasing subsequence.

### Time Complexity
The time complexity of the dynamic programming approach for finding the Longest Increasing Subsequence is O(n²), where `n` is the number of elements in the input array. This is due to the nested loops used to compare each pair of elements in the array.





