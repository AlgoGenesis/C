# Floyd-Warshall Algorithm

## Overview

The **Floyd-Warshall Algorithm** is a dynamic programming algorithm used to find the shortest paths between all pairs of vertices in a weighted graph. It can handle graphs with both positive and negative weights, but it does not work for graphs containing negative weight cycles.

### Key Features
- **Input**: A graph represented as an adjacency matrix.
- **Output**: A matrix where each entry `dist[i][j]` represents the shortest distance between vertex `i` and vertex `j`.
- **Time Complexity**: O(V³), where `V` is the number of vertices.

## How It Works

1. **Initialization**: The distance matrix is initialized to be the same as the adjacency matrix of the graph.
2. **Iteration**: For each vertex `k`, the algorithm checks if a path from vertex `i` to vertex `j` through `k` is shorter than the currently known shortest path. If so, it updates the shortest path.

dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
3. **Result**: After completing the iterations for all vertices, the shortest paths between all pairs of vertices are available in the distance matrix.

## Example

### Input Graph

This graph can be represented by the following adjacency matrix:

```plaintext
[
 {  0,   3, INF,   5 },
 {  2,   0, INF,   4 },
 { INF,   1,   0, INF },
 { INF, INF,   2,   0 }
]
Output
After running the Floyd-Warshall algorithm, the output matrix will be:

plaintext
Copy code
[
    {  0,   3,   7,   5 },
    {  2,   0,   6,   4 },
    {  3,   1,   0,   5 },
    {  5,   3,   2,   0 }
]
Explanation of the Output
The shortest distance from vertex 0 to vertex 2 is 7.
The shortest distance from vertex 1 to vertex 3 is 4, and so forth.
