# Dijkstra's Algorithm in C

## Description

This project demonstrates the implementation of **Dijkstra's Algorithm** in C, used to find the shortest path from a source vertex to all other vertices in a graph. The graph is represented as an adjacency matrix where each vertex is connected with weighted edges. Dijkstra’s algorithm works for graphs with non-negative weights and efficiently computes the shortest paths by iterating through the vertices.

## Features

- **Graph Representation**: The graph is represented as an adjacency matrix.
- **Shortest Path Calculation**: Finds the shortest path from a source vertex to all other vertices.
- **Efficiency**: Although not the most optimized (O(V²) complexity), this version demonstrates a basic and understandable implementation of Dijkstra's algorithm.

## Algorithm Overview

1. **Graph Representation**: 
   - A weighted graph is represented as an adjacency matrix where the weight of the edge between vertex `i` and vertex `j` is stored at `graph[i][j]`. If no edge exists, the value is `0`.
   
2. **Algorithm Steps**:
   - Initialize the distance of the source vertex to itself as `0` and all other vertices to `INT_MAX` (infinity).
   - Use a boolean array to keep track of vertices that have been processed.
   - For each vertex, find the one with the smallest known distance that hasn't been processed yet.
   - Update the distances of all adjacent vertices of the selected vertex, only if a shorter path is found.
   - Repeat until all vertices have been processed.
   
3. **Time Complexity**: 
   - This implementation runs with a time complexity of O(V²), where `V` is the number of vertices in the graph.

## Example Output
Vertex   Distance from Source
0        0
1        4
2        12
3        19
4        21
5        11
6        9
7        8
8        14

## Limitations
Time Complexity: This implementation uses a basic O(V²) approach. It can be optimized using a priority queue (min-heap) to achieve a time complexity of O((V + E) log V), where V is the number of vertices and E is the number of edges.
Graph Size: The adjacency matrix representation used here becomes inefficient for large, sparse graphs due to its O(V²) space complexity.

## License
This project is licensed under the MIT License.

## How to Run

### Compile the Code:
Use a C compiler to compile the source code. For example:

```bash
gcc -o dijkstra dijkstra.c

### Run the compiled code:
./dijkstra



