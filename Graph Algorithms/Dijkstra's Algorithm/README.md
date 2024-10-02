# Dijkstra Algorithm

## Description
The Dijkstra Algorithm is a popular algorithm for finding the shortest paths between nodes in a graph. It works for graphs with non-negative weights. The algorithm computes the shortest path from a source vertex to all other vertices in a graph, minimizing the total path weight.

Unlike the Bellman-Ford algorithm, Dijkstra’s algorithm does not handle graphs with negative weights, but it is faster for graphs with only positive weights.

### Problem Definition
Given:

A graph with V vertices and weighted edges.
Each edge is defined by a pair (u, v) where u is the starting vertex, v is the ending vertex, and the associated weight represents the distance between them.
Objective:

Find the shortest path from a source vertex S to all other vertices in the graph.


### Algorithm Overview
The Dijkstra Algorithm follows these steps:

1. Initialize the distance of the source vertex S to 0 and the distance to all other vertices as infinity.

2. Use a priority queue (min-heap) to greedily extract the vertex with the smallest known distance.

3. For each neighboring vertex v of the extracted vertex u, update the shortest path to v if a shorter path through u is found.
4. Repeat the process until all vertices have been processed.

### Time Complexity
Using a priority queue (min-heap), the time complexity of the Dijkstra Algorithm is O((V + E) log V), where:
- V is the number of vertices.
- E is the number of edges. This makes the algorithm efficient even for large graphs, as long as there are no negative edge weights.