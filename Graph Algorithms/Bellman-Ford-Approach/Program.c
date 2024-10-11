#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int src, dest, weight;
};

// Function to implement the Bellman-Ford algorithm
void bellmanFord(struct Edge* edges, int edgeCount, int vertexCount, int src) {
    int* distance = (int*)malloc(vertexCount * sizeof(int));
    
    // Initialize distances from src to all other vertices as infinite
    for (int i = 0; i < vertexCount; i++)
        distance[i] = INT_MAX;
    distance[src] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i < vertexCount; i++) {
        for (int j = 0; j < edgeCount; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < edgeCount; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("Graph contains negative weight cycle\n");
            free(distance);
            return;
        }
    }

    // Print the distance from source to all vertices
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < vertexCount; i++) {
        printf("%d \t\t %d\n", i, distance[i]);
    }

    free(distance);
}

int main() {
    struct Edge* edges = (struct Edge*)malloc(8 * sizeof(struct Edge));
    
    edges[0] = (struct Edge){0, 1, -1};
    edges[1] = (struct Edge){0, 2, 4};
    edges[2] = (struct Edge){1, 2, 3};
    edges[3] = (struct Edge){1, 3, 2};
    edges[4] = (struct Edge){1, 4, 2};
    edges[5] = (struct Edge){3, 2, 5};
    edges[6] = (struct Edge){3, 1, 1};
    edges[7] = (struct Edge){4, 3, -3};

    int edgeCount = 8;
    int vertexCount = 5;

    bellmanFord(edges, edgeCount, vertexCount, 0);

    free(edges);
    return 0;
}
