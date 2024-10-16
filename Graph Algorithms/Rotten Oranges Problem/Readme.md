# Rotten Oranges Problem (BFS)

## Description

The **Rotten Oranges Problem** involves determining the minimum time required for all fresh oranges to rot in a grid. Given a 2D grid where:
- `0`: Represents an empty cell.
- `1`: Represents a fresh orange.
- `2`: Represents a rotten orange.

## Example:
  ![image](https://github.com/user-attachments/assets/a22d7d5f-efe4-4f88-a0bd-d258be2679ed)
   - Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
  -  Output: 4

The goal is to find the minimum number of minutes that must elapse until no fresh oranges remain. If it's impossible for all fresh oranges to rot, return `-1`. Rotten oranges can rot adjacent fresh oranges (up, down, left, and right) in one minute.

## Key Features

- **Grid Representation**: Input is a 2D grid with values `0`, `1`, and `2`.
- **BFS Implementation**: Uses Breadth-First Search (BFS) to simulate the spread of rot to adjacent cells.
- **Multi-source BFS**: Multiple rotten oranges (sources) spread rot simultaneously.
- **Early Exit Condition**: Detects when not all fresh oranges can be rotted.

## Problem Definition

Given a 2D grid of `0`s, `1`s, and `2`s, find the minimum time required to rot all fresh oranges.

- **Input**: A 2D grid representing the initial state of the oranges.
- **Output**: The minimum number of minutes required to rot all fresh oranges, or `-1` if it is impossible.

## Algorithm Review

### 1. Initialization
- Traverse the grid to identify all rotten oranges and enqueue their positions. Track the number of fresh oranges.

### 2. BFS Traversal
- Perform BFS from all initially rotten oranges simultaneously, spreading rot to adjacent fresh oranges.
- For each minute, enqueue newly rotten oranges and decrement the fresh orange count.

### 3. Time Calculation
- Continue the process until no fresh oranges remain or no more rotten oranges can spread.

## Time Complexity

- **Traversal**: O(n * m), where `n` is the number of rows and `m` is the number of columns. Each cell is processed once.

## Applications

The Rotten Oranges Problem has applications in:
- **Contagion Modeling**: Simulates the spread of disease or fire in a confined area.
- **Breadth-First Search**: Demonstrates multi-source BFS in grid-based problems.
- **Supply Chain Simulation**: Models decay processes or spoilage over time.

## Conclusion

The **Rotten Oranges Problem** is a classic graph traversal problem that applies BFS to simulate the spread of rot across a grid. The algorithm efficiently determines the minimum time required for complete rot spread or identifies when it's impossible for all oranges to rot.

