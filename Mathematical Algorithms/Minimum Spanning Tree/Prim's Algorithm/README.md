# Prim's Algorithm in C

## Description

This project implements **Prim's Algorithm** in C, which is a greedy algorithm for finding the **Minimum Spanning Tree (MST)** of a connected, undirected, weighted graph. The algorithm starts with a single vertex and grows the MST by adding the cheapest possible edge at each step, while ensuring no cycles are formed.

## Features

- **Graph Representation**: The graph is represented using an adjacency matrix, where `graph[i][j]` holds the weight of the edge between vertices `i` and `j`. If no edge exists, the value is `0`.
- **Efficient Edge Selection**: The algorithm efficiently selects the next edge to include in the MST using a greedy approach.
- **Cycle-Free MST**: Ensures that no cycles are formed during the MST construction process.

## Algorithm Overview

1. **Graph Representation**: The graph is represented as an adjacency matrix where the value of `graph[i][j]` represents the weight of the edge between vertex `i` and vertex `j`. A `0` indicates no direct edge between two vertices.

2. **Prim's Algorithm Steps**:
   - Initialize a key array where each vertex starts with a value of `infinity` (except the starting vertex which is `0`).
   - Use a boolean array to track vertices included in the MST.
   - Select the vertex with the minimum key value that hasn't been included in the MST and add it.
   - For each adjacent vertex, if its key value is greater than the weight of the edge connecting it to the current vertex, update the key.
   - Repeat until all vertices are included in the MST.

3. **Time Complexity**: The time complexity of Prim's Algorithm using this adjacency matrix implementation is **O(V²)**, where **V** is the number of vertices in the graph.

## Example Output
Edge    Weight
0 - 1    2
1 - 2    3
0 - 3    6
1 - 4    5

## Limitations
Time Complexity: This implementation has a time complexity of O(V²). Using a min-heap or priority queue can reduce the time complexity to O(E log V), where E is the number of edges and V is the number of vertices.
Graph Representation: This implementation uses an adjacency matrix, which requires O(V²) space. For sparse graphs, an adjacency list would be more efficient.

## License
This project is released under the MIT License.

## How to Run

### Compile the Code:
```bash
gcc -o prim prim.c
./prim

