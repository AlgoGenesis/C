# Island Counting Algorithm (DFS/BFS)

## Description

The Island Counting Algorithm is a graph traversal technique used to count the number of distinct islands in a 2D grid. An island is defined as a group of connected `1`s (land) surrounded by `0`s (water). This algorithm utilizes Depth-First Search (DFS) and Breadth-First Search (BFS) methods to explore and count these islands efficiently.

## Key Features
- **Grid Representation**: The input is represented as a 2D grid where each cell is either `0` (water) or `1` (land).
- **DFS and BFS Implementations**: The algorithm can be implemented using both Depth-First Search and Breadth-First Search.
- **Connected Components**: Identifies connected components in the grid, counting distinct islands.

## Problem Definition

Given a 2D grid of `0`s and `1`s, the goal is to count the number of distinct islands. Each island is formed by adjacent `1`s connected horizontally or vertically.

- **Input**: A 2D grid of `0`s and `1`s.
- **Output**: The number of distinct islands in the grid.

## Algorithm Review

### 1. Initialization
- Create a visited matrix to track cells that have already been checked.
- Iterate through each cell in the grid.

### 2. Traversal
- For each unvisited `1`, initiate a DFS or BFS to mark all connected `1`s as visited.
- Increment the island count for each unvisited `1` found.

### 3. Depth-First Search (DFS)
- Recursively visit all connected `1`s by checking the four possible directions (up, down, left, right).
- Mark each visited cell to avoid counting it multiple times.

### 4. Breadth-First Search (BFS)
- Use a queue to explore all connected `1`s iteratively.
- Enqueue all adjacent `1`s and mark them as visited.

## Time Complexity

- **Traversal**: O(n * m), where `n` is the number of rows and `m` is the number of columns in the grid. Each cell is processed once.
  
## Applications

The Island Counting Algorithm is widely applicable in:
- **Geographical Mapping**: Identifying land masses in satellite imagery.
- **Image Processing**: Analyzing connected regions in binary images.
- **Network Connectivity**: Understanding connected components in graph data structures.

## Conclusion

The Island Counting Algorithm effectively counts distinct islands in a grid using DFS or BFS traversal methods. It is essential for solving connectivity problems in various fields, including geography, computer graphics, and network analysis.
