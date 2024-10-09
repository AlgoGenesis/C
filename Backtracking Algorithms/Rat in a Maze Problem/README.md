# Rat in a Maze Problem

## Description

The **Rat in a Maze** problem is a classic backtracking problem where the goal is to find a path from the start to the end of a maze. The rat can move in only four possible directions: up, down, left, and right. The maze is represented as a 2D grid, and the rat can move through cells that are not blocked.

### Problem Definition

Given:
- A maze represented as an `N x N` matrix.
- The rat starts at position `(0, 0)` and needs to reach the bottom-right corner `(N-1, N-1)`.

Objective:
- Find a path from the start to the destination that the rat can follow without stepping on blocked cells.

### Example

Consider the maze below, where `1` represents open cells, and `0` represents blocked cells:

1 0 0 0 1 1 0 1 0 1 0 0 1 1 1 1


- The rat can move from the top-left corner to the bottom-right corner following the path: `(0,0) -> (1,0) -> (1,1) -> (2,1) -> (3,1) -> (3,2) -> (3,3)`.

### Algorithm Overview

The solution is based on the backtracking approach:
1. Start from the top-left corner of the maze.
2. Check if the current cell is valid (within bounds and not blocked).
3. If it is the destination, return the path.
4. Explore all four possible directions (up, down, left, right) from the current cell.
5. Mark the current cell as part of the path and recur for the next cell.
6. If no valid path is found from the current cell, backtrack by marking the cell as unvisited.

### Time Complexity

- **Worst-case**: `O(4^(N^2))` due to exploring all possible paths in the maze.

### Applications

The Rat in a Maze problem has applications in robotics, pathfinding algorithms in AI, and game development.
