# Floyd-Warshall Algorithm

## Description

The **Floyd-Warshall Algorithm** is a dynamic programming algorithm used to find the shortest paths between all pairs of vertices in a weighted graph, even when negative weights are present (as long as there are no negative weight cycles).

### Problem Definition

Given:
- A weighted directed graph with \( V \) vertices.
- Weighted directed graph should be a \( VxV \) 2D Array.

Objective:
- Find the shortest path between every pair of vertices in the graph.

### Algorithm Overview

The Floyd-Warshall algorithm follows these steps:
1. Initialize a distance matrix, where each entry `dist[i][j]` is set to the weight of the edge from vertex \( i \) to vertex \( j \) if there is an edge, or infinity if there is no edge (except for `dist[i][i]`, which is set to 0 for all vertices \( i \)).
2. Iterate over each vertex \( k \) as an intermediate vertex and update the distance matrix. For each pair of vertices \( (i, j) \), if the distance from \( i \) to \( j \) through \( k \) is shorter than the current distance, update `dist[i][j]`.
3. After considering all vertices as intermediates, the distance matrix will contain the shortest paths between every pair of vertices.

### Time Complexity
- The time complexity of the Floyd-Warshall algorithm is \( O(V^3) \), where \( V \) is the number of vertices in the graph. This is due to the three nested loops iterating over all pairs of vertices and the intermediate vertex.