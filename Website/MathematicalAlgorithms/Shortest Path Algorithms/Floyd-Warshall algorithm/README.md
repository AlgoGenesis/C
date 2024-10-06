# Floyd-Warshall Algorithm in C

## Description

This project implements the **Floyd-Warshall algorithm** in C, which is used to find the shortest paths between all pairs of vertices in a weighted graph. It can handle graphs with positive or negative edge weights (but no negative weight cycles) and computes the shortest distances efficiently using a dynamic programming approach.

## Features

- **All-Pairs Shortest Path**: Computes shortest paths between all pairs of vertices in a single run.
- **Graph Representation**: The graph is represented as an adjacency matrix.
- **Negative Weight Support**: Capable of handling negative weights, as long as there are no negative weight cycles.
- **Clear Output**: Displays the shortest distance matrix in a readable format.

## Algorithm Overview

1. **Graph Representation**: 
   - The graph is represented as an adjacency matrix where the element `graph[i][j]` is the weight of the edge from vertex `i` to vertex `j`. If there is no edge, the value is `INT_MAX` (infinity).

2. **Algorithm Steps**:
   - Initialize the distance matrix to the input graph's matrix.
   - For each vertex `k`, update the distance from vertex `i` to vertex `j` if a shorter path is found through `k`.
   - Repeat this for every possible intermediate vertex.
   
3. **Time Complexity**: 
   - The algorithm runs with a time complexity of **O(V³)**, making it suitable for dense graphs.

## Example Output
For the given graph:
0 -> 1 (3)
0 -> 3 (7)
1 -> 0 (8)
1 -> 2 (2)
2 -> 0 (5)
2 -> 3 (1)
3 -> 0 (2)

The output will be like:
The following matrix shows the shortest distances between every pair of vertices:
      0      3      5      4
      8      0      2      3
      5      8      0      1
      2      5      7      0

## Limitations
Time Complexity: The O(V³) time complexity makes it less efficient for very large graphs compared to algorithms like Dijkstra's or Bellman-Ford for specific cases.
Negative Weight Cycles: The algorithm does not handle negative weight cycles; if they are present, the algorithm may produce incorrect results.

## License
This project is licensed under the MIT License.

## How to Run

### Compilation
Use a C compiler to compile the source code. For example:
```bash
gcc -o floyd_warshall floyd_warshall.c
./floyd_warshall

