
# Memory function-Knapsack Problem

The Memory Function (Top-down Memoization) is a dynamic programming approach where the problem is solved recursively and results are cached to avoid redundant calculations.


## Problem Statement
Given:

    n: Number of items
    weights[]: An array of weights of the items
    values[]: An array of values of the items
    W: Maximum weight capacity of the knapsack

The goal is to determine the maximum value that can be obtained by selecting a subset of the items without exceeding the weight capacity W.
## Dynamic Programming Solution
Steps:
 1. user's input the number of items, their respective weights and values, and the sack’s capacity.
 2. The program fills the memoization table to compute the maximum value achievable.
 3. It then backtracks to print the items that contribute to this maximum value.
 
## Initial memorization table


| i/j | 0   | 1  | 2  | 3   | 4  |
| :-------- | :------- | :------- | :------| :-------| :-------|
| `0` | `0` |  `0` | `0` | `0` | `0` | 
| `1` | `0` |  `-1` | `-1` | `-1` | `-1` | 
| `2` | `0` |  `-1` | `-1` | `-1` | `-1` | 



## Example C Code
Here is a C implementation of the MF-Knapsack Problem using dynamic programming