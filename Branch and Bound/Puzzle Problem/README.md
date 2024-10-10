
# 8-Puzzle Solver

## Description
The 8-Puzzle Solver is an implementation of the Branch and Bound algorithm used to solve the classic 8-puzzle problem, where the objective is to arrange tiles numbered from 1 to 8 in a 3x3 grid with one blank tile (represented as 0). The goal is to move the tiles into the correct configuration by sliding them into the blank space, following these rules:

- Tiles can only be moved into the adjacent blank space (up, down, left, or right).
- The final configuration must have the tiles arranged in sequential order from 1 to 8, with the blank tile in the last position.

## Problem Definition
Given:

- An initial state of a 3x3 grid representing the puzzle, where some tiles may be out of order.
- A goal state representing the desired arrangement of the tiles.

Objective:

- Transform the initial puzzle configuration into the goal configuration by sliding tiles into the blank space.

## Algorithm Overview
The Branch and Bound algorithm is utilized to systematically explore all possible configurations of the puzzle. The algorithm evaluates each state based on the number of misplaced tiles (cost) and the level of moves made to reach that state. The algorithm prioritizes exploring states with the lowest total cost until it finds a solution or determines that no solution exists.

### Steps:
1. **Read the initial puzzle configuration from the user.**
2. **Determine the position of the blank tile (0).**
3. **Read the goal configuration from the user.**
4. **Initialize the root node with the initial configuration and calculate its cost.**
5. **Generate all possible moves from the current configuration.**
6. **For each valid move, create a new node representing the resulting state.**
7. **Calculate the cost of the new state and add it to a priority queue.**
8. **Repeat the process until the goal state is reached or all configurations are explored.**

## Functions:
- **printPuzzle(int puzzle[N][N])**: Displays the current state of the puzzle in a readable format.
- **isWithinBounds(int x, int y)**: Checks if the given coordinates are within the puzzle's boundaries.
- **calculateCost(int puzzle[N][N], int goal[N][N])**: Computes the number of misplaced tiles in the current configuration compared to the goal configuration.
- **createNode(int puzzle[N][N], Position blank, int level, Node* parent)**: Creates a new node representing a state of the puzzle.
- **solvePuzzle(int initial[N][N], Position blank, int goal[N][N])**: Main function to solve the puzzle using the Branch and Bound algorithm.
- **readPuzzle(int puzzle[N][N])**: Reads the puzzle configuration from user input.

## Time Complexity
The time complexity of the 8-Puzzle Solver using the Branch and Bound algorithm can vary significantly based on the initial configuration and the number of misplaced tiles. In the worst case, the complexity can approach O(n!), where n is the number of tiles, due to the factorial growth of possible configurations. However, the algorithm can be more efficient with optimizations, such as using a priority queue to explore states with lower costs first, effectively reducing the search space. 
