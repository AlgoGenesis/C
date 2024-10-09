### Description

**The Word Search Algorithm** is a popular problem in which the goal is to find a given word in a 2D grid of letters. The word can be constructed by connecting letters sequentially in any of the four directions: up, down, left, or right. The word search algorithm is typically used in puzzles, games, and various computational problems related to searching patterns in grids.

### Problem Definition

Given a 2D grid of characters and a word, determine if the word exists in the grid. The word can be formed by connecting adjacent letters (horizontally or vertically). Each letter cell in the grid can only be used once per word search. The function returns true if the word is found and false otherwise.

### Rules for Word Search

**Movement Constraints**:

- You can move up, down, left, or right from any cell in the grid.

- Diagonal movements are not allowed.

**Character Reusability**:

A letter cell cannot be reused in the same word search. If a cell is visited, it cannot be visited again for the same word.

**Boundaries**:

- The search must stay within the boundaries of the grid.

- The word cannot wrap around the edges of the grid.


### Algorithm Overview


The word search problem is solved using backtracking and recursion. The algorithm explores all possible paths in the grid to find the given word.

1. Start the Search:

- Begin by iterating through each cell of the grid.

- If the first character of the word matches the character at the current cell, initiate a depth-first search (DFS) to explore all possible paths.


2. Depth-First Search (DFS):

- Check if the current cell matches the character of the word at the current index.

- Mark the current cell as visited by temporarily modifying its value.

- Recursively check in all four directions for the next character in the word.

- If a path is found that matches the entire word, return true.

- Backtrack by restoring the cell's value if the path does not lead to a solution.
 
3. Boundary Conditions:

- Stop searching if the current cell is out of bounds.

- Stop searching if the current cell does not match the required character.

4. Result:

If a path that forms the word is found, return true.

If no such path is found after exploring all possible paths, return false.


### Example


**Input**:

Grid:

[['A','B','C','E'],
 ['S','F','C','S'],
 ['A','D','E','E']]

Word: "ABCCED"

**Output**:

- The word "ABCCED" exists in the grid, so the result is true.

### Time Complexity


The time complexity of the word search algorithm is **O(N * M * 4^L)**, where:

- N is the number of rows in the grid.

- M is the number of columns in the grid.

- L is the length of the word.

The algorithm explores up to four directions for each letter of the word, leading to an exponential factor based on the length of the word.