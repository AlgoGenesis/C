# Hamiltonian Path Problem

## Description

The **Hamiltonian Path Problem** is a classic problem in graph theory where the goal is to determine whether there exists a path in a graph that visits each vertex exactly once. Unlike the Hamiltonian Cycle, this path does not need to return to the starting vertex.

### Problem Definition

Given:
- A graph `G` with `V` vertices and `E` edges.

Objective:
- Determine if there exists a Hamiltonian path in the graph, i.e., a path that visits every vertex exactly once.

### Example

Consider the graph below:

A - B
|   |
C - D


- A Hamiltonian path in this graph is: `A -> B -> D -> C`.

### Algorithm Overview

The Hamiltonian Path Problem is solved using backtracking:
1. Start at any vertex.
2. Mark the vertex as visited.
3. Recur for all its adjacent vertices that have not been visited yet.
4. If all vertices are visited exactly once, a Hamiltonian path is found.
5. If no valid path is found, backtrack and explore other possibilities.

### Time Complexity

- **Worst-case**: `O(V!)` since all permutations of the vertices may need to be explored.

### Applications

The Hamiltonian Path Problem has applications in:
- Traveling salesman problem (TSP).
- Scheduling problems.
- Network topology design.
