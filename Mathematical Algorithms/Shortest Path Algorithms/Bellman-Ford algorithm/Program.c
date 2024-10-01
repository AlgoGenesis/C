#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices in the graph
#define E 8  // Number of edges in the graph

// Structure to represent a weighted edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to implement the Bellman-Ford algorithm
void bellmanFord(struct Edge edges[], int src) {
    int dist[V];

    // Step 1: Initialize distances from the source to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    // Distance from the source to itself is always 0
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times.
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles.
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print the calculated shortest distances
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    // Array of edges in the graph
    struct Edge edges[E] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    bellmanFord(edges, 0);  // Call Bellman-Ford algorithm with 0 as the source vertex

    return 0;
}

