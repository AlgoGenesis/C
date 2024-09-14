# Bellman-Ford Algorithm

## Description

The Bellman-Ford algorithm is a single-source shortest path algorithm that computes the shortest path from a source vertex to all other vertices in a weighted graph. Unlike Dijkstra's algorithm, the Bellman-Ford algorithm can handle graphs with negative weight edges.

### Problem Definition

Given:
- A directed graph with `V` vertices and `E` edges.
- Each edge is defined by a tuple `(u, v, w)` where `u` is the starting vertex, `v` is the ending vertex, and `w` is the weight of the edge.

Objective:
- Find the shortest path from a source vertex `S` to all other vertices in the graph.

### Algorithm Overview

The Bellman-Ford algorithm follows these steps:
1. Initialize the distance to the source vertex `S` to `0` and the distances to all other vertices to infinity.
2. Relax all edges `V-1` times. For each edge `(u, v, w)`, if the distance to `u` plus the weight `w` is less than the distance to `v`, update the distance to `v`.
3. Check for negative weight cycles. If you can still relax any edge, it indicates the presence of a negative weight cycle.

### Time Complexity

The time complexity of the Bellman-Ford algorithm is `O(V * E)`, where `V` is the number of vertices and `E` is the number of edges.
