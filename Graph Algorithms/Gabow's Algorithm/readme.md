# Gabow's Algorithm for Finding Strongly Connected Components (SCC) in a Directed Graph

This repository contains a C implementation of **Gabow's Algorithm** for finding **Strongly Connected Components (SCCs)** in a directed graph. Gabow's algorithm is efficient for finding SCCs using depth-first search (DFS) and two stacks to track the components.

## Algorithm Overview

Gabow's algorithm works as follows:

1. **Initialization**: Each vertex is marked as unvisited. Two stacks (`stack` and `root`) are used to track vertices during the depth-first traversal.
2. **DFS Traversal**: The algorithm performs a DFS from each unvisited vertex, pushing vertices onto the stack and updating the root values.
3. **Identifying SCCs**: When a vertex is discovered to be the root of an SCC, all vertices in the current SCC are popped from the stack.
4. **Repeat**: The algorithm repeats for all vertices, ensuring that each vertex is processed and all SCCs are identified.

The result is the division of the graph into **strongly connected components**.

## Graph Representation

The graph is represented using an **adjacency matrix** where `adj[u][v]` is `1` if there is an edge from vertex `u` to vertex `v`, and `0` otherwise.

## How to Run

### Prerequisites

You will need a C compiler such as `gcc` to compile and run the code.

### Steps to Run:

1. **Clone the Repository** or copy the code into a file named `gabow_scc.c`.

2. **Compile** the C program using the following command:

   ```bash
   gcc gabow_scc.c -o gabow_scc
   ```

3. **Run** the compiled program:

   ```bash
   ./gabow_scc
   ```

### Input Format

- First, enter the number of vertices `V` and edges `E`.
- Then, input `E` pairs of integers representing the directed edges `(u, v)` of the graph.

### Example Input

```plaintext
6 7
0 1
1 2
2 0
1 3
3 4
4 5
5 3
```

### Example Output

For the example graph input, the output of the program will be:

```plaintext
Strongly Connected Components:
SCC 0: 3 4 5
SCC 1: 0 2 1
```

This output represents two SCCs:
1. SCC 0 contains vertices {3, 4, 5}.
2. SCC 1 contains vertices {0, 1, 2}.

### Code Explanation

1. **initializeGraph()**: Initializes the adjacency matrix and global variables.
2. **dfs()**: Performs the depth-first search, pushing vertices onto the stack and identifying SCCs.
3. **findSCCs()**: Calls the DFS on all vertices and finds all SCCs.
4. **main()**: Handles input and calls `findSCCs()` to compute and print the SCCs.

### Complexity

- **Time Complexity**: O(V + E), where `V` is the number of vertices and `E` is the number of edges. The algorithm efficiently handles the graph in linear time with respect to the input size.

### Use Cases

Gabow's algorithm can be used in:
- **Graph theory** applications to identify strongly connected components.
- **Program analysis** to detect cycles in control flow graphs.
- **Social network analysis** to identify clusters of users connected by mutual interactions.

### Customizing the Graph

You can modify the graph in the `main()` function by changing the number of vertices and edges and providing new input values for edges.

