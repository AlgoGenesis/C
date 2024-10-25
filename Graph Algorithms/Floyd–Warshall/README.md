# Floyd-Warshall Algorithm

## Description

The Floyd-Warshall Algorithm is a dynamic programming algorithm used to find the shortest path between all pairs of nodes in a weighted graph. This implementation uses an adjacency matrix to represent the graph, where each element in the matrix represents the cost or weight of the edge between two nodes. If there is no direct edge between two nodes, the weight should be set to a large value, often referred to as infinity (e.g., `9999`).

## Problem Definition

Given a graph with `n` nodes represented as a cost adjacency matrix, the goal is to calculate the shortest path between all pairs of nodes and output a distance matrix where each entry `(i, j)` represents the shortest path from node `i` to node `j`.

### Input:

1. The number of nodes in the graph (`n`).
2. The adjacency matrix for the graph, where:
   - `matrix[i][j]` represents the weight of the edge from node `i` to node `j`.
   - If there is no direct path between nodes `i` and `j`, the value should be set to a high number (e.g., `9999`), representing infinity.

### Output:

- The shortest distance matrix, which provides the minimum distance between each pair of nodes.

## Algorithm Overview

The algorithm iteratively updates the shortest paths by considering each node as an intermediate node and checking if it provides a shorter path between any two nodes. If a shorter path is found, it updates the distance.

### Steps:

1. **Initialize the Distance Matrix**: Copy the adjacency matrix to the distance matrix.
2. **Iterate over All Nodes**: For each node `k` (considered as an intermediate node), update the distance between each pair of nodes `i` and `j` by checking if the path `i -> k -> j` is shorter than the current path `i -> j`.
3. **Update the Distance**: Use the formula:
   ```c
   d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
   ```
where d[i][j] is the distance from node i to node j, d[i][k] is the distance from node i to node k, and d[k][j] is the distance from node k to node j.
4. **Output the Distance Matrix**: Print the resulting shortest distance matrix.

## Time Complexity

The time complexity of the Floyd-Warshall algorithm is **O(n³)**, where `n` is the number of nodes in the graph. This complexity arises from the three nested loops required to iterate over all pairs of nodes for each intermediate node.

- **Worst-case time complexity**: O(n³)
- **Space complexity**: O(n²) (for storing the distance matrix)
