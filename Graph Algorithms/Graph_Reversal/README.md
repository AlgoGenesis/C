# Reverse a Directed Graph

### Problem Statement:
Suppose we have a directed graph, we have to find its reverse so if an edge goes from i to j, it now goes from j to i. Here input will be an adjacency list, and if there are n nodes, the nodes will be (0, 1, ..., n-1).

### Approach:
The approach to transposing a directed graph involves creating a new structure to hold reversed edges. For each vertex, the algorithm iterates through its outgoing edges and appends the vertex to the list of the target vertex in the new structure. This efficiently constructs the transposed graph in linear time relative to the number of vertices and edges.

### Algorithm Steps:
1. **Define Structures**:
   - Define an `AdjList` structure, a dynamic array to hold adjacent nodes for each node.
   - Define a `Graph` structure containing an array of `AdjList`s to represent the adjacency lists for all nodes.

2. **Initialize the Graph**:
   - Create a function `initGraph` that initializes a `Graph` with a given number of nodes.
   - For each node, initialize an empty `AdjList` with a small initial capacity.

3. **Add an Edge**:
   - Create a function `pushBack` for adding an edge to a node's `AdjList`.
   - If the current capacity of the `AdjList` is full, double the capacity and reallocate memory.

4. **Transpose the Graph**:
   - Create a function `solve` to transpose the graph:
     - Initialize a new `Graph` (the transposed graph) with the same number of nodes as the original.
     - For each node in the original graph:
       - For each node it points to, add the original node as an adjacent node in the transposed graph.
     - Return the transposed graph.

5. **Print the Graph**:
   - Define a function `printGraph` to display the adjacency lists of the graph:
     - For each node, print the list of nodes it points to.

6. **Example Usage**:
   - Initialize a graph with a specified number of nodes.
   - Populate the graph by adding edges.
   - Call the `solve` function to transpose the graph.
   - Print the adjacency lists of the transposed graph.
  
### Time Complexity:
- The time complexity of the program is `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges, as it processes each vertex and edge once.

### Sample Input:

```
    {{1, 2}, {4}, {4}, {1, 2}, {3}}
```
### Sample Output:

```
    [[], [0, 3], [0, 3], [4], [1, 2]]
```

### Explanation of Sample:

- The input `graph = [[1,2],[4],[4],[1,2],[3]]` represents a directed graph as an adjacency list where:

    - Node 0 points to nodes 1 and 2.
    - Node 1 points to node 4.
    - Node 2 points to node 4.
    - Node 3 points to nodes 1 and 2.
    - Node 4 points to node 3.

- The reversed graph representation is `ans = [[], [0, 3], [0, 3], [4], [1, 2]]`, which means:

    - Node 0 has no outgoing edges.
    - Nodes 1 and 2 have outgoing edges to nodes 0 and 3.
    - Node 3 has an outgoing edge to node 4.
    - Node 4 has outgoing edges to nodes 1 and 2.

### Diagrammatic Representation of the input:
![directed_graph](https://github.com/user-attachments/assets/b3a8fc46-e508-45a0-bf97-458c2054f085)

### Diagrammatic Representation of the output:
![directed_graph1](https://github.com/user-attachments/assets/7cb03236-3f1a-49cc-b2ce-6ef73aac7fa4)
