# Scramble String Problem

## Description

The Scramble String problem is to determine whether one string is a scrambled version of another. Given two strings, `s1` and `s2`, we say that `s2` is a scrambled version of `s1` if it can be formed by recursively dividing `s1` into two non-empty substrings and swapping them.

For example:
- Input: `s1 = "great"`, `s2 = "rgeat"`
- Output: `true` (because "rgeat" is a scrambled version of "great")

## Problem Requirements

We need to:
1. Check if two strings contain the same characters.
2. Recursively verify if substrings can be swapped to form the scrambled string.
3. Optimize using memoization to avoid redundant calculations.

## Solution Approach

This solution uses **Dynamic Programming** with **Recursion and Memoization**:

1. **Recursive Check**:
   - For each possible split of `s1`, we recursively check:
     - If dividing and not swapping substrings forms `s2`, or
     - If dividing and swapping substrings forms `s2`.
   
2. **Memoization Table**:
   - We use a 3D table `memo[i1][i2][len]` to store results of subproblems where:
     - `i1` and `i2` are starting indices in `s1` and `s2`.
     - `len` is the length of the substrings.
   - Each entry in the table can be either `-1` (not calculated), `1` (scramble), or `0` (not a scramble).

3. **Complexity**:
   - **Time Complexity**: `O(N^4)`, where `N` is the length of the string.
   - **Space Complexity**: `O(N^3)` due to the memoization table.
