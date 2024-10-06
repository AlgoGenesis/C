# Floyd-Warshall Algorithm

This is a C program that implements the **Floyd-Warshall Algorithm**, a popular algorithm used to find the shortest paths between all pairs of vertices in a given weighted graph.

## Description

The Floyd-Warshall Algorithm is an efficient way to compute shortest paths in a weighted graph with **V** vertices. It works by repeatedly updating the distances between all pairs of vertices based on the idea of dynamic programming.

- The graph is represented as a 2D matrix, where the cell value `graph[i][j]` holds the weight of the edge between vertex `i` and vertex `j`.
- If two vertices are not directly connected, the value is set to a large constant, **INF** (infinity), representing no path.
- The algorithm iteratively considers all possible intermediate vertices to find the shortest path between all pairs.

## Time Complexity

The time complexity of the Floyd-Warshall Algorithm is **O(V³)**, where **V** is the number of vertices in the graph. This is because there are three nested loops in the algorithm:

- The outermost loop runs for each vertex `k` (intermediate vertex).
- The middle loop iterates over each vertex `i` (source vertex).
- The innermost loop iterates over each vertex `j` (destination vertex) and updates the shortest distance between `i` and `j` using vertex `k` as an intermediate point.

Thus, the total number of operations is proportional to **V × V × V**, which results in **O(V³)** time complexity.

## Graph Structure

The input graph for this implementation has **V = 4** vertices. The edges and weights are defined as:

