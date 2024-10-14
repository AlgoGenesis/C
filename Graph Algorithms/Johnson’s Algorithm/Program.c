#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 100 // Maximum number of vertices

typedef struct {
    int u, v, weight;
} Edge;

int dist[MAX_V][MAX_V]; // Distance matrix
int h[MAX_V]; // Array to hold the potential values

// Function to add an edge to the graph
void addEdge(Edge edges[], int *edgeCount, int u, int v, int weight) {
    edges[*edgeCount].u = u;
    edges[*edgeCount].v = v;
    edges[*edgeCount].weight = weight;
    (*edgeCount)++;
}

// Function to perform Bellman-Ford algorithm to find shortest paths from source
int bellmanFord(Edge edges[], int edgeCount, int V, int src) {
    for (int i = 0; i < V; i++) {
        dist[src][i] = INT_MAX; // Initialize distances
    }
    dist[src][src] = 0; // Distance to self is 0

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (dist[src][u] != INT_MAX && dist[src][u] + weight < dist[src][v]) {
                dist[src][v] = dist[src][u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < edgeCount; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;

        if (dist[src][u] != INT_MAX && dist[src][u] + weight < dist[src][v]) {
            return 0; // Negative weight cycle detected
        }
    }
    return 1; // No negative weight cycle
}

// Function to compute shortest paths between all pairs of vertices
void johnsonsAlgorithm(int V, Edge edges[], int edgeCount) {
    // Step 1: Add a new vertex and connect it to all other vertices with zero-weight edges
    for (int i = 0; i < V; i++) {
        addEdge(edges, &edgeCount, V, i, 0);
    }

    // Step 2: Run Bellman-Ford from the new vertex
    if (!bellmanFord(edges, edgeCount, V + 1, V)) {
        printf("Negative weight cycle detected!\n");
        return;
    }

    // Step 3: Re-weight edges
    for (int i = 0; i < V; i++) {
        h[i] = dist[V][i]; // Store potential values
    }

    // Step 4: Re-run Dijkstra's algorithm for each vertex
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = INT_MAX; // Initialize distances
        }
        dist[i][i] = 0; // Distance to self is 0

        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            // Re-weight the edges
            edges[j].weight += h[u] - h[v];
        }

        // Dijkstra's algorithm (simple version)
        for (int count = 0; count < V - 1; count++) {
            for (int j = 0; j < edgeCount; j++) {
                int u = edges[j].u;
                int v = edges[j].v;
                int weight = edges[j].weight;

                if (dist[i][u] != INT_MAX && dist[i][u] + weight < dist[i][v]) {
                    dist[i][v] = dist[i][u] + weight;
                }
            }
        }
    }

    // Step 5: Adjust the distances to original weights
    printf("Shortest path distances between all pairs of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j] + h[j] - h[i]); // Adjust back
            }
        }
        printf("\n");
    }
}

int main() {
    Edge edges[MAX_V * MAX_V];
    int edgeCount = 0;
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter the edges (u v weight), enter -1 -1 -1 to stop:\n");
    
    while (1) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        if (u == -1 && v == -1 && weight == -1) break; // Stop condition
        addEdge(edges, &edgeCount, u, v, weight);
    }

    johnsonsAlgorithm(V, edges, edgeCount);

    return 0;
}
