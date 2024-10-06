# Depth-First Search (DFS) Algorithm

## Description

Depth-First Search (DFS) is a graph traversal algorithm used to explore the vertices and edges of a graph. It starts from a root node and explores as deep as possible along each branch before backtracking. DFS can be used for both connected and disconnected graphs.

### Problem Definition

Given:
- A graph represented as an adjacency list.
- A starting vertex `v`.

Objective:
- Traverse the graph using DFS and print all the visited vertices.

### Algorithm Overview

1. Start at the root node or a starting node.
2. Mark the node as visited.
3. Recursively visit all unvisited neighbors.
4. Continue until all reachable nodes are visited.

### Time Complexity

The time complexity of DFS is `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges.
