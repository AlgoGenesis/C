# Word Search (LeetCode Problem)

## Problem Overview

The **Word Search** problem asks us to determine if a given word exists in a 2D grid of characters. The word can be formed by sequentially adjacent cells, where "adjacent" means horizontally or vertically neighboring. The same letter cell cannot be used more than once.

## Problem Statement

You are given an `m x n` grid of characters called `board` and a string `word`. Return `true` if the word exists in the grid, otherwise return `false`.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

### Example 1:

Input:
board = [
  ["A","B","C","E"],
  ["S","F","C","S"],
  ["A","D","E","E"]
]
word = "ABCCED"
Output: true

### Example 2:
Input:



board = [
  ["A","B","C","E"],
  ["S","F","C","S"],
  ["A","D","E","E"]
]
word = "ABCB"
Output: false

### Approach
This problem can be solved using backtracking. We will first search for the first character of the word in the grid. If we find it, we will recursively search for the next character in all four directions: up, down, left, and right. We will also ensure that we do not visit the same cell twice by marking cells as visited during the search.

### Steps:
Start by searching the first character of the word in the grid.
Use a helper function to recursively check adjacent cells (up, down, left, right) for the next character.
Mark the current cell as visited by changing its value temporarily to a special character (e.g., '!').
If the word is found, return true. If not, backtrack by restoring the previous cell value and continue searching.
### Edge Cases:
Ensure boundaries of the grid are respected.
Ensure cells are not reused in the word.
Stop the search early if the word is found.
### Complexity
Time Complexity:
Worst Case: O(m * n * 4^k) where:
m is the number of rows.
n is the number of columns.
k is the length of the word.
This is because for each cell, we explore up to 4 directions in the worst case.

Space Complexity:
O(k) where k is the length of the word. This is the maximum depth of the recursion stack.
