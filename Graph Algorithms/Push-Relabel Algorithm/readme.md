# Push-Relabel Algorithm in C

This repository contains a C implementation of **Push-Relabel Algorithm** used to solve the **Maximum Flow** problem in a flow network. The Push-Relabel Algorithm is efficient for dense graphs and uses preflow, push, and relabel operations to find the maximum flow from a source to a sink in the network.

## Algorithm Overview

The Push-Relabel Algorithm works as follows:

1. **Initialization**: Set the preflow by pushing flow from the source to adjacent vertices, and set the source height to the number of vertices.
2. **Push Operation**: Push excess flow from one vertex to an adjacent vertex if there is residual capacity and the vertex's height is greater than its neighbor’s height.
3. **Relabel Operation**: If a vertex cannot push flow, increase its height to allow pushing.
4. **Repeat**: Continue the push and relabel operations until no more flow can be pushed, resulting in the maximum flow.

The resulting flow maximizes the amount of flow from the source to the sink.

## Graph Representation

The flow network is represented as a **capacity matrix**, where `capacity[i][j]` represents the capacity of the edge from vertex `i` to vertex `j`. A value of `0` indicates no edge exists between the vertices.

## How to Run

### Prerequisites

You will need a C compiler such as `gcc` to compile and run the code.

### Steps to Run:

1. *Clone the Repository* or copy the code into a file named `push_relabel.c`.

2. *Compile* the C program using the following command:

   ```bash
   gcc push_relabel.c -o push_relabel
   ```

3. *Run* the compiled program:

   ```bash
   ./push_relabel
   ```

### Example Graph

The provided graph in the code is:

```
    16     13
(0)----->(1)----->(3)
 |      / |       / |
 |    10  |      /  |
 v   /    v     v   v
(2)<--4--(1)--> 20 (4)
      12         4
```

The capacity matrix for this graph is:

```c
int capacity[V][V] = { {0, 16, 13, 0, 0, 0},
                       {0, 0, 10, 12, 0, 0},
                       {0, 4, 0, 0, 14, 0},
                       {0, 0, 9, 0, 0, 20},
                       {0, 0, 0, 7, 0, 4},
                       {0, 0, 0, 0, 0, 0} };
```

### Expected Output

For the given graph, the output of the program will be:

```
Maximum flow is 23
```

This output represents the maximum flow from the source (vertex `0`) to the sink (vertex `5`).

## Code Explanation

1. **initializePreflow()**: Initializes the preflow and sets the source height.
2. **push()**: Pushes excess flow from a vertex to a neighboring vertex if possible.
3. **relabel()**: Increases the height of a vertex to enable further pushes.
4. **discharge()**: Repeatedly applies push and relabel operations to a vertex until it has no excess flow.
5. **pushRelabel()**: Executes the Push-Relabel Algorithm and computes the maximum flow in the network.
6. **main()**: Defines the graph and calls the `pushRelabel()` function to calculate and print the maximum flow.

## Customizing the Graph

You can modify the graph in the `main()` function by changing the `capacity[V][V]` matrix. Ensure that:
- The graph is a directed flow network.
- Use `0` to indicate no edge between two vertices.

### Changing the Number of Vertices

The macro `#define V 6` defines the number of vertices in the graph. If you wish to use a different graph, modify `V` to reflect the correct number of vertices.

## Complexity

- **Time Complexity**: O(V²E), where `V` is the number of vertices and `E` is the number of edges. This is efficient for dense graphs.

## Use Cases

The Push-Relabel Algorithm can be used in:
- **Network routing** to maximize data flow in communication networks.
- **Traffic systems** to optimize flow in transportation.
- **Resource allocation** for project scheduling and optimization problems.


