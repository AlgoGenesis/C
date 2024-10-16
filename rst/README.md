# Randomized Spanning Tree Algorithm (RST)

## Description

The **Randomized Spanning Tree (RST)** algorithm is designed to generate a spanning tree from a connected, undirected graph. The algorithm introduces randomness by shuffling the adjacency list of each vertex before constructing the spanning tree using a breadth-first search (BFS) approach.

## Problem Definition

Given an undirected graph with `n` vertices and `m` edges, the task is to generate a random spanning tree. A spanning tree is a subgraph that connects all the vertices of the graph without forming any cycles and with exactly `n-1` edges.

### Input:

- `V` (number of vertices) and `E` (number of edges).
- List of `E` edges where each edge is represented as a pair of vertices `(u, v)`.

### Output:

- A randomized spanning tree represented by a set of `n-1` edges.

### Example

#### Input:

- Vertices: 5
- Edges: [(0, 1), (0, 2), (1, 2), (1, 3), (2, 4), (3, 4)]

#### Output:

Randomized Spanning Tree:

## Algorithm

1. **Graph Representation**: The graph is represented using an adjacency list.
2. **Randomization**: The adjacency list of each vertex is shuffled before traversing the graph to introduce randomness.
3. **BFS Traversal**: The algorithm starts from a random vertex and performs BFS. Each newly discovered vertex is connected to the current vertex to form an edge in the spanning tree.
4. **Termination**: The BFS terminates when all vertices are visited, forming a spanning tree with exactly `n-1` edges.

## Time Complexity

The time complexity of this algorithm is **O(V + E)**, where:

- `V` is the number of vertices.
- `E` is the number of edges.

This complexity arises because we visit every vertex and edge once during the BFS traversal.

## Compilation and Execution

To compile and run the program:

```bash
gcc rst.c -o rst
./rst
```

---

This provides a complete `C` implementation of the Randomized Spanning Tree algorithm along with its corresponding README file. You can use this structure for your repository.
