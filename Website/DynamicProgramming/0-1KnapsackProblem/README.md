# 0-1 Knapsack Problem

## Description

The 0-1 Knapsack Problem is a classic optimization problem that involves selecting a subset of items to maximize total value while staying within a specified weight limit. In this problem, each item can either be included in the knapsack (1) or not included (0). 

### Problem Statement

Given:
- `n`: Number of items
- `weights[]`: An array of weights of the items
- `values[]`: An array of values of the items
- `W`: Maximum weight capacity of the knapsack

The goal is to determine the maximum value that can be obtained by selecting a subset of the items without exceeding the weight capacity `W`.

### Example

Suppose we have the following items:

| Item | Weight | Value |
|------|--------|-------|
| 1    | 1      | 1     |
| 2    | 3      | 4     |
| 3    | 4      | 5     |
| 4    | 5      | 7     |

And the maximum weight capacity of the knapsack is `7`. The optimal selection of items would yield a maximum value of `9`.

## Dynamic Programming Solution

We can solve the 0-1 Knapsack Problem using dynamic programming by building a table to store the maximum value that can be obtained for each weight limit up to `W`.

### Steps:
1. Create a 2D array `dp[n+1][W+1]` where `dp[i][w]` represents the maximum value that can be obtained using the first `i` items and a weight limit of `w`.
2. Fill the table using the following rules:
   - If the weight of the current item is greater than `w`, do not include it: `dp[i][w] = dp[i-1][w]`
   - If the weight of the current item is less than or equal to `w`, choose the maximum value between including or excluding the item:  
     `dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w-weights[i-1]])`

### Example C Code

Here is a C implementation of the 0-1 Knapsack Problem using dynamic programming:
