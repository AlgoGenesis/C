#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define V 100  // Maximum number of vertices in the graph

// Function to perform Breadth-First Search and find if there is a path from source to sink
bool bfs(int residualGraph[V][V], int source, int sink, int parent[]) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    int queue[V], front = 0, rear = 0;
    queue[rear++] = source;
    visited[source] = true;
    parent[source] = -1;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;

                if (v == sink)
                    return true;
            }
        }
    }

    return false;
}

// Function to implement the Edmonds-Karp algorithm
int edmondsKarp(int graph[V][V], int source, int sink, int n) {
    int u, v;
    int residualGraph[V][V];

    // Initialize residual graph
    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            residualGraph[u][v] = graph[u][v];

    int parent[V];
    int maxFlow = 0;

    while (bfs(residualGraph, source, sink, parent)) {
        int pathFlow = INT_MAX;

        // Find the maximum flow possible in the found path
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            pathFlow = pathFlow < residualGraph[u][v] ? pathFlow : residualGraph[u][v];
        }

        // Update residual capacities
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int n, edges, u, v, capacity;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[V][V] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge in the format 'u v capacity' (0-indexed):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &capacity);
        graph[u][v] = capacity;
    }

    int source, sink;
    printf("Enter source vertex: ");
    scanf("%d", &source);
    printf("Enter sink vertex: ");
    scanf("%d", &sink);

    printf("The maximum possible flow is %d\n", edmondsKarp(graph, source, sink, n));

    return 0;
}
