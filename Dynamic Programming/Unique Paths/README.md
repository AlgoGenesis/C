# Unique Paths

This project implements an algorithm to solve the Unique Paths problem, which calculates the number of unique ways to navigate a grid from the top-left corner to the bottom-right corner using dynamic programming.

## Description

The Unique Paths problem is a classic algorithmic problem that involves finding the number of distinct paths in a grid when only movements to the right and down are allowed. The goal is to determine how many unique paths exist from the starting point (0, 0) to the destination (m-1, n-1) in an m x n grid.

### Problem Definition

Given a grid of size `m x n`, your task is to count the number of unique paths from the top-left corner to the bottom-right corner. The only allowed movements are right and down.

### Algorithm Overview

The algorithm uses dynamic programming to efficiently calculate the number of unique paths. The main idea is to create a 2D array (or table) where each entry represents the number of unique paths to reach that cell.

#### Steps
1. **Initialization**: Create a 2D array `dp` of size `m x n` where each element is initialized to 0.
2. **Base Cases**:
   - The first row and the first column can only be reached in one way, so set all cells in the first row and first column to 1.
3. **Fill the DP Table**:
   - For each cell `(i, j)`, the number of unique paths to that cell is the sum of the unique paths from the cell above it `(i-1, j)` and the cell to the left of it `(i, j-1)`.
4. **Result**: The value at the bottom-right corner of the grid `dp[m-1][n-1]` will give the total number of unique paths from the top-left to the bottom-right corner.

### Time Complexity

The time complexity of the algorithm is O(m * n), where `m` is the number of rows and `n` is the number of columns in the grid. This is because we fill out each cell in the 2D array exactly once. The space complexity is also O(m * n) due to the additional space used for the `dp` array.


