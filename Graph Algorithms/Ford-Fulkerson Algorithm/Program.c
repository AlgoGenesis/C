#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 6

// A function to perform a BFS search to find if there is a path
// from source `s` to sink `t` in the residual graph.
// Returns true if there is a path, otherwise false.
bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    
    // Create a queue, enqueue the source vertex, and mark it as visited
    int queue[V], front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1; // No parent for source
    
    // Standard BFS loop
    while (front < rear) {
        int u = queue[front++]; // Dequeue

        // Visit all adjacent vertices of `u`
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                // If vertex `v` is not yet visited and the capacity
                // from `u` to `v` is greater than zero, enqueue it
                queue[rear++] = v;
                parent[v] = u; // Save the parent of `v`
                visited[v] = true;
                
                // If we found a path to the sink, return true
                if (v == t) return true;
            }
        }
    }

    // No path found
    return false;
}

// Function to implement the Ford-Fulkerson Algorithm to find
// the maximum flow in the given graph.
int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;

    // Create a residual graph and initialize it with the original graph
    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];  // Array to store the path found by BFS
    int maxFlow = 0;  // Initial flow is 0

    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, s, t, parent)) {
        // Find the maximum flow through the path found by BFS
        int pathFlow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            pathFlow = pathFlow < rGraph[u][v] ? pathFlow : rGraph[u][v];
        }

        // Update the residual capacities of the edges and reverse edges
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        // Add the path flow to the overall flow
        maxFlow += pathFlow;
    }

    // Return the overall flow
    return maxFlow;
}

int main() {
    // Example graph with 6 vertices and edges with capacities
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0, sink = 5;
    
    printf("The maximum possible flow is %d\n", fordFulkerson(graph, source, sink));

    return 0;
}
