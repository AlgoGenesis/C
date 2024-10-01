# Bellman-Ford Algorithm in C

## Description

This project implements the **Bellman-Ford algorithm** in C, which is used for finding the shortest paths from a single source vertex to all other vertices in a weighted graph. This algorithm is capable of handling graphs with negative weight edges, making it a versatile choice for many applications in graph theory.

## Features

- **Graph Representation**: The graph is represented as an edge list, allowing flexibility in handling sparse graphs.
- **Shortest Path Calculation**: Computes the shortest paths from a specified source vertex to all other vertices.
- **Negative Weight Support**: Efficiently handles graphs with negative weights, detecting negative weight cycles.
- **Clear Output**: Provides an easy-to-read output of the shortest path distances from the source vertex.

## Algorithm Overview

1. **Graph Representation**: 
   - The graph is represented as an edge list, where each edge is defined by its start vertex, end vertex, and weight.

2. **Algorithm Steps**:
   - Initialize distances from the source vertex to all other vertices as infinity, and the distance to itself as zero.
   - Relax all edges repeatedly for a total of \( V - 1 \) iterations, where \( V \) is the number of vertices. For each edge, update the distance to the destination vertex if the path through the source vertex offers a shorter path.
   - After \( V - 1 \) iterations, check for negative weight cycles by iterating through the edges one more time. If a shorter path is found, it indicates a negative weight cycle.

3. **Time Complexity**: 
   - The algorithm runs with a time complexity of **O(V * E)**, making it suitable for graphs with a moderate number of edges.
     
## Example Output
Assuming a graph with the following edges:
0 -> 1 (4)
0 -> 2 (1)
1 -> 2 (3)
2 -> 1 (-1)
2 -> 3 (2)
3 -> 0 (-2)

The output will be:
Vertex Distance from Source
0      0
1      3
2      1
3      3

## Limitations
Time Complexity: While Bellman-Ford is effective for graphs with negative weights, its time complexity of O(V * E) can be less efficient than other algorithms like Dijkstra's for graphs with non-negative weights.
Negative Weight Cycles: The algorithm can detect negative weight cycles but does not provide a way to handle them in the output distances.

## License
This project is licensed under the MIT License. 

## How to Run

### Compilation
Use a C compiler to compile the source code. For example:
```bash
gcc -o bellman_ford bellman_ford.c
./bellman_ford
