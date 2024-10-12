


# Prim's Algorithm - Minimum Spanning Tree (MST) in C

## Description

This project contains a C implementation of **Prim's Algorithm** to find the **Minimum Spanning Tree (MST)** of a weighted, connected, undirected graph. The algorithm starts from a vertex and grows the MST by selecting the minimum weight edge at each step.

### What is a Minimum Spanning Tree (MST)?
An MST is a subset of edges of a connected graph that connects all the vertices together, without cycles, and with the minimum possible total edge weight.

### How Prim's Algorithm Works
Prim’s Algorithm starts from an arbitrary vertex and iteratively adds the smallest edge that connects the growing MST to a vertex outside the MST. It is a greedy algorithm that ensures each edge added has the least possible weight.

---

## Features

- **Graph Representation**: The graph is represented using an adjacency matrix.
- **Key Array**: Maintains the minimum weight edge for each vertex.
- **Parent Array**: Tracks the structure of the MST.
- **MST Set**: A boolean array to track included vertices.

---

## Requirements

- A C compiler (e.g., `gcc`).
- The program works for small, dense graphs (up to 1000 vertices), but for larger graphs, consider optimizing with a priority queue.

---

## Getting Started

### Compiling the Program

To compile the program, open your terminal and use the following command:

```bash
gcc prims_algorithm.c -o prims
```

### Running the Program

After compiling, you can run the program with the command:

```bash
./prims
```

### Example Graph

The included sample graph is a simple connected, undirected, and weighted graph represented by the following adjacency matrix:

```
       2    3
   (0)--(1)--(2)
    |   / \   |
   6| 8/   \5 |7
    | /     \ |
   (3)-------(4)
         9
```

This graph is represented in the code as:

```c
int graph[V][V] = { 
    { 0, 2, 0, 6, 0 }, 
    { 2, 0, 3, 8, 5 }, 
    { 0, 3, 0, 0, 7 }, 
    { 6, 8, 0, 0, 9 }, 
    { 0, 5, 7, 9, 0 } 
};
```

When the program runs, it will compute the MST for the graph.

### Sample Output

```
Edge    Weight
0 - 1    2 
1 - 2    3 
0 - 3    6 
1 - 4    5 
```

This output indicates the edges included in the MST and their respective weights.

---

## Code Explanation

1. **minKey Function**: 
   Finds the vertex with the minimum key value that is not yet included in the MST.

2. **primMST Function**: 
   Implements Prim's Algorithm to construct the MST by iterating through the vertices and selecting the minimum weight edges.

3. **printMST Function**: 
   Prints the edges that are part of the MST and their corresponding weights.

4. **main Function**: 
   Initializes a sample graph and calls `primMST()` to compute the MST.

---

## Customizing the Program

- **Graph Size**: Change the number of vertices by modifying the `#define V` directive.
- **Graph Input**: Replace the hardcoded adjacency matrix with user input or file input to use your own graph.
- **Starting Vertex**: Modify the `primMST` function to allow a different starting vertex.

---

## Time Complexity

The current implementation has a time complexity of **O(V²)**, where `V` is the number of vertices. For sparse graphs or larger graphs, consider optimizing using an adjacency list and a priority queue to achieve a complexity of **O(E log V)**.



---

## Contributing

If you’d like to contribute to this project, feel free to submit a pull request or open an issue. Any improvements, optimizations, or suggestions are welcome.

---
.