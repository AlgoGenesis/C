# Sudoku Solver

## Description

The **Sudoku Solver** is a backtracking algorithm used to fill a partially completed 9x9 Sudoku grid, where empty cells are denoted by `0`. The goal is to complete the grid by filling in the empty cells according to the rules of Sudoku:

1. Each row must contain digits from `1-9` without repetition.
2. Each column must contain digits from `1-9` without repetition.
3. Each of the nine 3x3 subgrids must contain digits from `1-9` without repetition.

## Problem Definition

Given:
- A 9x9 partially filled Sudoku grid with some cells marked as `0`.

Objective:
- Fill the grid with numbers from `1-9` following the rules of Sudoku.

## Algorithm Overview

The **backtracking** approach is used to solve the Sudoku puzzle. We fill empty cells by trying digits `1` through `9`. For each number, we check whether it satisfies the row, column, and subgrid constraints. If a valid number is found, it is placed in the cell and the algorithm proceeds to the next empty cell. If no valid number can be placed, the algorithm backtracks.

### Steps:
1. Identify the first empty cell.
2. Try placing digits `1-9` in the empty cell.
3. For each digit, check whether placing it is valid (i.e., not already present in the same row, column, or subgrid).
4. If valid, place the digit and move to the next empty cell.
5. If no digit is valid, backtrack by removing the last placed digit and try the next digit.
6. Repeat the process until the entire grid is filled.

### Functions:
1. **isSafe(row, col, num)**: Checks if placing a digit in a given cell is valid based on the Sudoku rules.
2. **solveSudoku()**: Recursively fills in the empty cells using backtracking.
3. **printGrid()**: Displays the filled Sudoku grid.

## Time Complexity

The time complexity of solving Sudoku using backtracking is `O(9^n)`, where `n` is the number of empty cells. This complexity arises because we may try every number from `1` to `9` for each empty cell. However, optimizations like constraint propagation can significantly reduce the number of choices at each step.
