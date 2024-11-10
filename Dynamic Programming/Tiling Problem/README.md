# Tiling Problem (Cover a 2xN Board with 2x1 Tiles)

## Problem Description

The Tiling Problem involves finding the number of ways to cover a \(2 \times N\) board using \(2 \times 1\) tiles. Each tile can either be placed:
- Vertically, which covers a \(1 \times 2\) area on the board.
- Horizontally, which covers a \(2 \times 1\) area on the board.

Given a positive integer `N`, the goal is to determine the number of ways to completely cover the \(2 \times N\) board using these tiles without gaps or overlaps.

## Approach

We can solve this problem using dynamic programming by defining `dp[i]` as the number of ways to tile a \(2 \times i\) board.

### Steps

1. **Base Cases**:
   - For \( N = 1 \), there is only **1 way** to place a single tile vertically.
   - For \( N = 2 \), there are **2 ways**: two vertical tiles or two horizontal tiles.

2. **Recursive Formula**:
   - For each \( i \geq 3 \):
     \[
     dp[i] = dp[i - 1] + dp[i - 2]
     \]
   - This formula is derived from two choices:
     - Place a single vertical tile at the end (leaving a \(2 \times (i-1)\) board).
     - Place two horizontal tiles at the end (leaving a \(2 \times (i-2)\) board).

3. **Final Result**:
   - The number of ways to tile a \(2 \times N\) board is stored in `dp[N]`.