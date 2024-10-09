# Word Search (LeetCode Problem)

## Problem Overview

The **Word Search** problem asks us to determine if a given word exists in a 2D grid of characters. The word can be formed by sequentially adjacent cells, where "adjacent" means horizontally or vertically neighboring. The same letter cell cannot be used more than once.

## Problem Statement

You are given an `m x n` grid of characters called `board` and a string `word`. Return `true` if the word exists in the grid, otherwise return `false`.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

### Example 1:

**Input:**

```plaintext
board = [
  ["A","B","C","E"],
  ["S","F","C","S"],
  ["A","D","E","E"]
]
word = "ABCCED"
