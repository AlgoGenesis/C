# Kruskal's Algorithm in C

## Description
This project implements **Kruskal's Algorithm** in C, which is a greedy algorithm to find the **Minimum Spanning Tree (MST)** of a connected, undirected, and weighted graph. The graph is represented using an edge list, where each edge has a source, destination, and weight. The algorithm builds the MST by picking edges with the smallest weights and ensuring no cycles are formed.

## Features
- **Efficient Cycle Detection**: Uses the Union-Find data structure to efficiently detect cycles in the graph.
- **Edge List Representation**: The graph is represented as a list of edges, sorted by their weights.
- **Greedy Algorithm**: Constructs the MST by greedily selecting the smallest available edge.
- **Flexible Graph**: Supports any undirected, connected graph with weighted edges.

## Algorithm Overview
1. **Sort Edges**: Sort all edges in non-decreasing order based on their weight.
2. **Union-Find for Cycle Detection**: 
   - Use Union-Find to detect and avoid cycles. 
   - A union is performed if adding the edge does not form a cycle.
3. **Build MST**: Add edges to the MST until it contains **V-1** edges, where **V** is the number of vertices in the graph.

## Time Complexity
- **Sorting** the edges takes **O(E log E)**, where **E** is the number of edges.
- Union-Find operations take approximately **O(E log V)**, making the total time complexity **O(E log E)** or **O(E log V)** since **E > V**.

## Example Output
Following are the edges in the constructed MST:
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10

## Limitations
Sparse Graphs: Works well for sparse graphs, but for dense graphs, Prim's Algorithm may perform better.
Edge Sorting: The algorithm's efficiency heavily depends on sorting the edges.
Union-Find: The Union-Find data structure can be optimized using path compression and union by rank.

## License
This project is released under the MIT License.

## How to Run

### Compile the Code:
```bash
gcc -o kruskal kruskal.c
./kruskal

