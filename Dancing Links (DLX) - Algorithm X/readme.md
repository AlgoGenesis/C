# Dancing Links (DLX) - Algorithm X Implementation in C

Welcome to the **Dancing Links (DLX)** implementation in C. This project provides a solution for solving exact cover problems using **Donald Knuth's Algorithm X**, a powerful backtracking technique enhanced by the **Dancing Links** data structure.

## Overview

**Dancing Links (DLX)** is a technique used to efficiently implement **Algorithm X**, a recursive, nondeterministic, depth-first search algorithm for finding all solutions to the exact cover problem.

This algorithm can solve complex combinatorial problems such as:
- **Sudoku solving**
- **N-Queens problem**
- **Polyomino tiling (e.g., Tetris-like puzzles)**

The **exact cover problem** asks for a subset of rows from a binary matrix such that each column has exactly one `1`.

### Key Features:
- Efficient solution to exact cover problems.
- Optimized for fast backtracking and solving puzzles.
- Implements the **Dancing Links** structure to perform fast node removal and restoration.

## Algorithm Explanation

The Dancing Links technique uses a circular doubly linked list to represent the matrix in Algorithm X. When backtracking, rows and columns can be covered and uncovered efficiently.

**Steps of Algorithm X**:
1. **Choose a column**: Select a column with the fewest `1`s (heuristic).
2. **Cover the column**: Remove the column and its associated rows.
3. **Recursively search**: Choose one row that contains a `1` in that column and cover all other columns containing a `1` in that row.
4. **Backtrack**: If a solution is found, record it; otherwise, backtrack and uncover the columns.

## How It Works

The solution provided in this repository sets up the **Dancing Links** structure and solves exact cover problems via backtracking. The linked list structure allows the algorithm to efficiently cover and uncover rows and columns as it explores potential solutions.

### Data Structures:
- **ColumnNode**: Represents each column of the matrix.
- **Node**: Represents each entry in the matrix, linked in four directions (up, down, left, right).
  
### Operations:
- **Covering**: Temporarily removes columns and associated rows to explore potential solutions.
- **Uncovering**: Restores the covered columns and rows during backtracking.

## Files in this Repository

- `dlx.c`: The main C implementation of the Dancing Links (DLX) algorithm.
- `README.md`: Project documentation (this file).

## Installation and Compilation

To compile and run the program, use the following steps:

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/DancingLinks-DLX.git

   cd DancingLinks-DLX

   gcc dlx.c -o dlx

   ./dlx



This README file is structured to provide a clear understanding of the algorithm, how to run the project, and how others can contribute.

