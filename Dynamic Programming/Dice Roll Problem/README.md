# Dice Roll Sum Problem

## Description

The **Dice Roll Sum** problem is a dynamic programming challenge that asks how many ways you can achieve a given target sum by rolling a certain number of dice. Each die has a fixed number of faces (e.g., 6), and each face has an equal probability of appearing. The objective is to calculate the number of distinct ways to reach the target sum using the given dice.

### Problem Statement
Given:
- `n`: the number of dice,
- `target`: the target sum,
- `faces`: the number of faces on each die (default is 6).

Find the number of ways to achieve exactly the target sum by rolling the dice.

### Example

**Input:**
- Number of dice: `2`
- Target sum: `7`

**Output:**
- Number of ways to reach target sum: `6`

**Explanation:**
With 2 dice, there are six ways to achieve a sum of 7:
- (1,6), (2,5), (3,4), (4,3), (5,2), (6,1)

## Solution Approach

We use **dynamic programming** to build up the solution by breaking down the problem into smaller subproblems:
1. Define a 2D DP array `dp[i][j]` where `i` is the number of dice and `j` is the target sum.
2. Initialize `dp[0][0] = 1`, representing one way to achieve a sum of 0 with 0 dice.
3. For each dice count `i`, calculate the possible ways to reach each target sum `j` by considering all face values from 1 up to `faces`.
4. The answer will be stored in `dp[n][target]`, representing the number of ways to reach the target sum with `n` dice.