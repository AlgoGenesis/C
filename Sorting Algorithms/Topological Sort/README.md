## Topological Sort

## Description
Topological sorting is an important algorithm in computer science used to schedule tasks, manage dependencies, and solve problems involving directed graphs. It produces a linear ordering of vertices such that for every directed edge `uv` from vertex `u` to vertex `v`, `u` comes before `v` in the ordering.

## Algorithm
The algorithm works by performing a depth-first search (DFS) on the graph and maintaining a stack to store the vertices in the order they are finished. The steps are as follows:

1. Mark the current node as visited.
2. Recursively visit all its adjacent unvisited nodes.
3. Push the current node onto a stack after all its adjacent nodes have been visited.
4. Pop vertices from the stack to get the topological order.

## Code Explanation
Graph Structure: The graph is represented using an adjacency list.
Functions:
createGraph(int numVertices): Initializes a graph with the specified number of vertices.
addEdge(Graph* graph, int src, int dest): Adds a directed edge from src to dest.
topologicalSortUtil(Graph* graph, int vertex, int* sortedOrder): Helper function for DFS that fills the sorted order.
topologicalSort(Graph* graph): Main function that initiates the topological sort process and prints the result.

## Complexity Analysis
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges. Each vertex and edge is processed once.
Space Complexity: O(V) for the visited array and the sorted order array.