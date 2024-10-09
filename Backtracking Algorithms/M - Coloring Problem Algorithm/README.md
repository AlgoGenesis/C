# M-Coloring Problem

## Overview

The **M-Coloring Problem** is a well-known problem in graph theory where the goal is to assign colors to the vertices of a graph such that no two adjacent vertices share the same color. The problem is NP-complete, meaning that there is no known polynomial-time solution for it. However, it can be solved using backtracking.

### Key Features
- **Input**: A graph represented as an adjacency matrix and a number `m` which denotes the number of colors.
- **Output**: A color assignment for the vertices such that no two adjacent vertices have the same color.
- **Time Complexity**: O(m^V), where `V` is the number of vertices.

## How It Works

1. **Graph Representation**: The graph is represented using an adjacency matrix.
2. **Backtracking**: The algorithm tries to assign colors to each vertex, checking if the current assignment is valid (i.e., no adjacent vertices share the same color).
3. **Recursive Exploration**: If the current color assignment is valid, the algorithm recursively attempts to color the next vertex. If it fails, it backtracks and tries the next color.

## Example

### Input Graph

Consider the following adjacency matrix representation of a graph:

```plaintext
[
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
]
