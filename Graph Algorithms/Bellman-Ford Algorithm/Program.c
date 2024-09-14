#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to implement the Bellman-Ford algorithm
void bellmanFord(struct Edge edges[], int edgeCount, int src) {
    int distance[V];
    
    // Step 1: Initialize distances from src to all other vertices as infinite
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;
    distance[src] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (int j = 0; j < edgeCount; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print the distance from source to all vertices
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}

int main() {
    struct Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    bellmanFord(edges, edgeCount, 0);

    return 0;
}