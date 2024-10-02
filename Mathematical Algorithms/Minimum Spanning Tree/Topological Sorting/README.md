# Topological Sorting in C

## Description

This project implements **Topological Sorting** in C using Depth-First Search (DFS). Topological Sorting is used to order the vertices of a Directed Acyclic Graph (DAG) such that for every directed edge `(u, v)`, vertex `u` comes before vertex `v` in the ordering.

## Features

- **Graph Representation**: The graph is represented using an adjacency list for efficient storage of directed edges.
- **Topological Sorting**: The program performs topological sorting on a Directed Acyclic Graph (DAG).
- **DFS-Based Approach**: The sorting is done using a Depth-First Search (DFS) based algorithm where vertices are pushed onto a stack after all their adjacent vertices are visited.

## Algorithm Overview

1. **Graph Representation**: The graph is represented as an adjacency list where `graph[i]` holds a linked list of vertices adjacent to vertex `i`.
2. **DFS and Stack**: For each vertex, a DFS is performed, visiting all adjacent vertices. After visiting all neighbors, the vertex is pushed onto a stack. This ensures that vertices are processed in a topological order.
3. **Topological Order**: After the DFS completes, vertices are popped from the stack to obtain the topological sorting order.
4. **Time Complexity**: The time complexity of the algorithm is **O(V + E)**, where **V** is the number of vertices and **E** is the number of edges.

## Example Output
Performing Topological Sort on the graph:
Topological Sort: 5 4 2 3 1 0 

## Limitations
Directed Acyclic Graph (DAG): Topological sorting can only be performed on a Directed Acyclic Graph (DAG). If the graph contains cycles, the algorithm will not work properly.
Unique Order: If multiple valid topological orders exist, this algorithm will return one of them based on the order of DFS traversal.

## License 
This project is released under the MIT License.

## How to Run

### Compile the Code:
```bash
gcc -o topologicalsortting topologicalsortting.c
./topologicalsortting

