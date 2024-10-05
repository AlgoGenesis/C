# Kahn's Algorithm

## Description

Kahn's Algorithm is a method for topological sorting of a directed acyclic graph (DAG). It works by repeatedly removing vertices with no incoming edges (in-degree 0) and reducing the in-degrees of their neighboring vertices. The algorithm helps to sort tasks or processes in a sequence where certain tasks must be performed before others.

### Problem Definition

Given:

- A directed graph with `V` vertices and `E` edges.
- Each edge is defined by a pair `(u, v)` where `u` is the starting vertex, and `v` is the ending vertex.

Objective:

- Perform a `topological sort` of the vertices, where for any edge `(u, v)`, vertex `u` appears before vertex `v` in the sorted order.
- If the graph contains a `cycle`, topological sorting is not possible.

### Algorithm Overview

The Kahn's Algorithm follows these steps:

1. Calculate In-degree:

- For each vertex, compute the number of incoming edges (in-degree).

2. Initialize Queue:

- Enqueue all vertices with in-degree 0 (vertices with no incoming edges).

3. Process Queue:

- Repeatedly dequeue vertices with in-degree 0 and append them to the topological order.
- For each dequeued vertex, reduce the in-degree of its neighbors by 1.
- If any neighbor's in-degree becomes 0, enqueue it.

4. Cycle Detection:

- If all vertices are processed, the graph has no cycle, and a topological sort is possible.
- If some vertices are left unprocessed, the graph contains a cycle, and topological sorting is not possible.

### Time Complexity

The time complexity of Kahn's Algorithm is:

`O(V + E)` where `V` is the number of vertices and `E` is the number of edges, using an adjacency list representation.