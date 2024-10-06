# Coin Change Problem

## Description

The Coin Change Problem is a classic problem in combinatorial optimization. The objective is to determine the number of ways to make a specific amount of money using a given set of coin denominations. The problem can be solved using various approaches, including dynamic programming and recursion.

### Problem Definition

Given:
- An array of coin denominations `coins[]`.
- A total amount `amount`.

Objective:
- Find the number of different ways to make up the `amount` using the provided coin denominations.

### Algorithm Overview

1. **Dynamic Programming Table**: Create an array `dp` where `dp[i]` represents the number of ways to make change for the amount `i`.
2. **Initialization**: Set `dp[0] = 1`, as there is one way to make the amount zero (using no coins).
3. **Fill the DP Table**:
   - For each coin in the `coins` array, update the `dp` array for all amounts from the value of the coin to the target amount.
   - For each `i` from `coin` to `amount`, update `dp[i]` as `dp[i] + dp[i - coin]`.
4. **Result**: The final answer will be stored in `dp[amount]`.

### Time Complexity

The time complexity of the dynamic programming solution is `O(n * m)`, where `n` is the number of coins and `m` is the target amount. The space complexity is `O(m)` for the `dp` array.


