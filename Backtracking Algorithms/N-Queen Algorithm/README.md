# N-Queens Problem

## Description

The N-Queens problem is a backtracking algorithm where we place `N` queens on an `N x N` chessboard such that no two queens can attack each other. It uses recursion and backtracking to explore all possible placements of queens on the board.

### Problem Definition

Given:
- A chessboard of size `N x N`.

Objective:
- Place `N` queens on the board so that no two queens threaten each other.

### Algorithm Overview

1. Place queens column by column.
2. For each column, check all rows to see if it's safe to place a queen.
3. If a queen can be placed, move to the next column.
4. If no valid position is found, backtrack by removing the last placed queen.
5. Continue until all queens are placed or all options are exhausted.

### Time Complexity

The time complexity of the N-Queens problem is `O(N!)`, as it involves exploring all possible ways to place queens on the chessboard.
