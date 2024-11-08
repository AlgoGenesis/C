# Domino and Tromino Tiling

## Problem Description

You are given a 2 x n board and two types of tiles:
- A **domino** tile that covers two squares (2 x 1).
- A **tromino** tile that covers three squares (L-shaped).

You can rotate these shapes, and your task is to find the number of ways to tile the entire 2 x n board using these tiles. 

### Constraints
- The integer `n` (the length of the board) is non-negative.
- The result should be returned modulo \(10^9 + 7\) due to potentially large numbers.

### Tiling Definition
In a tiling, every square must be covered by a tile. Two tilings are considered different if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

## Approach

To solve the problem, we can use **Dynamic Programming**. The idea is to define a recurrence relation based on how we can place the tiles.

### Recurrence Relation
1. **Base Cases**:
   - `dp[0] = 1`: There is 1 way to tile a 2 x 0 board (do nothing).
   - `dp[1] = 1`: There is 1 way to tile a 2 x 1 board (using one vertical domino).
   - `dp[2] = 2`: There are 2 ways to tile a 2 x 2 board (either two vertical dominoes or two horizontal dominoes).

2. **For n >= 3**:
   The relation can be expressed as:
   \[
   dp[n] = dp[n-1] + dp[n-2] + 2 \times dp[n-3]
   \]
   - `dp[n-1]`: Place a vertical domino.
   - `dp[n-2]`: Place two horizontal dominoes.
   - `2 * dp[n-3]`: Place a tromino in two different configurations.
