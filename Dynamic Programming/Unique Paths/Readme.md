# Unique Paths - Dynamic Programming

### Description
The Unique Paths is a common dynamic programming challenge that asks how many ways one can move from the top-left corner to the bottom-right corner of a grid. The allowed moves are only to the right or downward, making it a problem well-suited for dynamic programming due to its overlapping sub-problems.


### Problem Definition
Given:
A grid of size m x n.
Starting point: (0, 0) (top-left corner).
Ending point: (m-1, n-1) (bottom-right corner).
Allowed moves: You can only move down or right.


### Algorithm Overview
We solve this problem using dynamic programming (DP) to avoid redundant calculations. The idea is to use a 2D DP table, where each cell (i, j) stores the number of ways to reach that cell from the start.

For every cell (i, j), the total ways to reach it is the sum of ways from the cell above (i-1, j) and the cell to the left (i, j-1).
The base case is the first cell (0, 0), which has exactly 1 way to reach it (by starting there).


### Steps
**Initialize a 2D DP table** with dimensions m x n.

**Set the base case:**
dp[0][0] = 1 (one way to start from the top-left corner).

**Fill the DP table:**
For each cell (i, j):
If i > 0, add the value from the cell above: dp[i-1][j].
If j > 0, add the value from the left cell: dp[i][j-1].


### Time Complexity: 
O(m×n), as we fill the entire 2D DP table.
### Space Complexity: 
O(m×n), due to the 2D table used to store intermediate results