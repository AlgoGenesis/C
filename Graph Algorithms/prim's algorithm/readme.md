

---

# Prim's Algorithm in C

This repository contains a C implementation of **Prim's Algorithm**, which is used to find the **Minimum Spanning Tree (MST)** of a connected, undirected, and weighted graph. Prim's Algorithm is a greedy algorithm that builds the MST by progressively choosing the minimum weight edge that connects a vertex in the MST to a vertex outside the MST.

## Algorithm Overview

Prim's algorithm works as follows:
1. Start with an arbitrary vertex.
2. Find the smallest edge connecting the current MST to a vertex outside the MST.
3. Add the new vertex and edge to the MST.
4. Repeat the process until all vertices are included in the MST.

The resulting MST minimizes the total weight of the edges included.

## Graph Representation

The graph is represented as an **adjacency matrix**, where the value at `graph[i][j]` is the weight of the edge between vertices `i` and `j`. A value of `0` indicates no edge exists between those vertices.

## How to Run

### Prerequisites

You will need a C compiler such as `gcc` to compile and run the code.

### Steps to Run:

1. *Clone the Repository* or copy the code into a file named `prim.c`.

2. *Compile* the C program using the following command:

   ```bash
   gcc prim.c -o prim
   ```

3. *Run* the compiled program:

   ```bash
   ./prim
   ```

### Example Graph

The provided graph in the code is:

```
    2    3
(0)---(1)---(2)
 |    / \    |
 6   8   5   7
 |  /     \  |
(3)-------(4)
      9
```

The adjacency matrix for this graph is:

```c
int graph[V][V] = { {0, 2, 0, 6, 0},
                    {2, 0, 3, 8, 5},
                    {0, 3, 0, 0, 7},
                    {6, 8, 0, 0, 9},
                    {0, 5, 7, 9, 0} };
```

### Expected Output

For the given graph, the output of the program will be:

```
Edge    Weight
0 - 1    2 
1 - 2    3 
0 - 3    6 
1 - 4    5
```

This output represents the edges included in the MST and their corresponding weights.

## Code Explanation

1. minKey(): Finds the vertex with the minimum key value that is not yet included in the MST.
   
2. primMST(): Constructs the MST using Prim's algorithm and prints the edges and their weights.

3. printMST(): Prints the edges included in the MST and their weights.

4. main(): Defines the graph and calls the `primMST()` function to calculate and display the MST.

## Customizing the Graph

You can modify the graph in the `main()` function by changing the `graph[V][V]` matrix. Ensure that:
- The graph is undirected (`graph[i][j]` should equal `graph[j][i]`).
- Use `0` to indicate no edge between two vertices.

### Changing the Number of Vertices

The macro `#define V 5` defines the number of vertices. If you wish to use a different graph, modify `V` to reflect the correct number of vertices.

## Complexity

- **Time Complexity**: O(V²), where `V` is the number of vertices. This is suitable for dense graphs.
- For large, sparse graphs, you may want to use a more optimized version of Prim's algorithm using a min-heap to achieve a time complexity of O(E log V), where `E` is the number of edges.



