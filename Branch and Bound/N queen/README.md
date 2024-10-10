
# N Queen Solver  

## Description  
The N Queen Solver is an algorithm that uses the Branch and Bound technique to place N queens on an N×N chessboard so that no two queens threaten each other. The goal is to find a valid configuration where each queen is placed in such a way that:

- No two queens share the same row.
- No two queens share the same column.
- No two queens share the same diagonal.

## Problem Definition  
**Given:**

- An integer \( N \), which represents the size of the chessboard and the number of queens to place.
  
**Objective:**

- Determine a valid arrangement of N queens on the board, or state that no solution exists.

## Algorithm Overview  
The algorithm employs a recursive backtracking approach combined with Branch and Bound techniques. It explores potential placements of queens column by column and uses a series of checks to ensure that each placement is safe. If a conflict arises, the algorithm backtracks and tries the next possible configuration.

## Steps:
1. Initialize an empty N×N chessboard.
2. Start placing queens column by column.
3. For each column, attempt to place a queen in each row.
4. Check if placing the queen is safe using the `isSafe` function:
   - Ensure no queens are already placed in the same row or diagonals.
5. If the placement is valid, mark the position and recursively attempt to place the next queen.
6. If all queens are placed successfully, print the board configuration.
7. If no valid position is found, backtrack by removing the last placed queen and trying the next row.
8. Repeat until all configurations are explored or a solution is found.

## Functions:
- `isSafe(row, col, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup, N)`: Checks if placing a queen in a specified position is valid based on existing queen placements.
- `solveNQueensUtil(board, col, slashCode, backslashCode, rowLookup, slashCodeLookup, backslashCodeLookup, N)`: Recursively attempts to place queens in valid positions.
- `printSolution(board, N)`: Displays the chessboard with the queen placements.

## Time Complexity  
The time complexity of solving the N Queen problem using backtracking is \( O(N!) \) in the worst case. This arises because, in the worst scenario, each queen can be placed in every row and column, leading to numerous recursive calls. However, the use of Branch and Bound optimizations significantly reduces the search space, allowing the algorithm to find solutions more efficiently.
