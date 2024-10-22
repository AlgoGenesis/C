
---

# 8-Puzzle Problem

The **8-puzzle problem** is a classic AI challenge and a sliding puzzle that consists of a 3x3 grid containing 8 numbered tiles and one blank space. The goal is to rearrange the tiles to reach a specified goal state using the minimum number of moves. The problem is commonly used to demonstrate state-space search techniques such as Breadth-First Search (BFS), Depth-First Search (DFS), and the A* algorithm.

## Problem Description

The puzzle contains the numbers from 1 to 8 and a blank space represented as `0`. The player can move the blank space up, down, left, or right to rearrange the tiles. The objective is to reach the following **goal state**:

```
1 2 3
4 5 6
7 8 0
```

### Example Initial State

```
1 2 3
4 0 6
7 5 8
```

### Operations

The blank tile (0) can move in four directions:
- **Up**: Moves the blank tile one row up.
- **Down**: Moves the blank tile one row down.
- **Left**: Moves the blank tile one column left.
- **Right**: Moves the blank tile one column right.

The puzzle is solved when the tiles are arranged in the goal state as shown above.

## Solution Approach

This project implements the 8-puzzle problem using **Breadth-First Search (BFS)**, an algorithm that explores all nodes level by level to find the shortest path to the solution. Here’s how it works:

1. **Initialization**: The initial state of the puzzle is loaded, and the position of the blank tile is identified.
2. **State Exploration**: The algorithm explores all possible moves of the blank tile (up, down, left, right) to generate new states.
3. **Queue Management**: The BFS queue is used to keep track of nodes (states) that need to be explored. The algorithm dequeues the next node, checks if it matches the goal state, and enqueues any valid new states created by moving the blank tile.
4. **Goal Check**: If a node matches the goal state, the solution is printed, showing the steps needed to solve the puzzle. If the queue is exhausted and no solution is found, it concludes that the puzzle is unsolvable.

## How to Run the Program

To run the program:

1. Compile the C code using a C compiler (e.g., `gcc`):
   ```
   gcc 8_puzzle.c -o 8_puzzle
   ```

2. Run the executable:
   ```
   ./8_puzzle
   ```

3. The program will output the initial state and the solution if it exists.

## Future Enhancements

- **Implement Additional Algorithms**: Add support for algorithms like DFS and A* for better performance and comparison.
- **Interactive Mode**: Allow users to input their own initial puzzle configuration and see the solution steps.
- **Graphical Interface**: Develop a simple GUI to visualize the puzzle movements and solution path.

