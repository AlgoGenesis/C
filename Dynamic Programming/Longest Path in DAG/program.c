#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices in the graph

typedef struct {
    int v, weight;
} Edge;

// Graph adjacency list representation
Edge adj[V][V];
int edge_count[V];

// A utility function to add an edge to the graph
void addEdge(int u, int v, int weight) {
    adj[u][edge_count[u]].v = v;
    adj[u][edge_count[u]].weight = weight;
    edge_count[u]++;
}

// A utility function to perform DFS-based topological sort
void topologicalSortUtil(int v, int visited[], int stack[], int* stackIndex) {
    visited[v] = 1;

    // Visit all adjacent vertices of v
    for (int i = 0; i < edge_count[v]; i++) {
        int u = adj[v][i].v;
        if (!visited[u]) {
            topologicalSortUtil(u, visited, stack, stackIndex);
        }
    }

    stack[(*stackIndex)++] = v;
}
// Function to find the longest path from a given source in a DAG
void longestPath(int src) {
    int visited[V] = {0};
    int stack[V], stackIndex = 0;
    int dist[V];

    // Step 1: Perform topological sort
    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, stack, &stackIndex);

    // Step 2: Initialize distances to all vertices as minus infinity
    for (int i = 0; i < V; i++)
        dist[i] = INT_MIN;
    dist[src] = 0;

    // Step 3: Process vertices in topological order
    while (stackIndex > 0) {
        int u = stack[--stackIndex];

        // Update distances of all adjacent vertices
        if (dist[u] != INT_MIN) {
            for (int i = 0; i < edge_count[u]; i++) {
                int v = adj[u][i].v;
                int weight = adj[u][i].weight;
                if (dist[v] < dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    printf("Longest distances from source vertex %d:\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MIN) {
            printf("Vertex %d is unreachable from source, Distance: -Infinity\n", i);
        } else {
            printf("Vertex %d - Distance: %d\n", i, dist[i]);
        }
    }
}

int main() {
    for (int i = 0; i < V; i++)
        edge_count[i] = 0;
    // Adding edges to the DAG (u -> v with weight w)
    addEdge(0, 1, 3);
    addEdge(0, 2, 10);
    addEdge(0, 3, 14);
    addEdge(1, 3, 7);
    addEdge(1, 4, 51);
    addEdge(2, 3, 5);
    addEdge(3, 4, 11);
    int source = 0;
    longestPath(source);
    return 0;
}
