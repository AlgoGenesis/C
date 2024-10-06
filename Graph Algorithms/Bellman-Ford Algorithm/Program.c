#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

struct Edge {
    int u, v, weight;
};

const int INF = INT_MAX;

bool bellmanFord(int n, int source, struct Edge* edges, int m, int* dist) {
    // Initialize distance array
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    // Relaxation step: iterate n-1 times
    for (int step = 1; step < n; ++step) {
        bool updated = false;
        for (int i = 0; i < m; ++i) {
            int u = edges[i].u;
            int v = edges[i].v;
            int weight = edges[i].weight;
            if (dist[u] != INF && dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                updated = true;
            }
        }
        // Early stopping if no updates in this step
        if (!updated) break;
    }

    // Check for negative weight cycle in the nth step
    for (int i = 0; i < m; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        if (dist[u] != INF && dist[v] > dist[u] + weight) {
            return true; // Negative cycle found
        }
    }

    return false; // No negative cycle
}

int main() {
    int n, m;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Edge* edges = (struct Edge*)malloc(m * sizeof(struct Edge));
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    int* dist = (int*)malloc(n * sizeof(int));
    if (bellmanFord(n, source, edges, m, dist)) {
        printf("Negative cycle found\n");
    } else {
        printf("Shortest distances from source vertex %d are:\n", source);
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INF) {
                printf("INF ");
            } else {
                printf("%d ", dist[i]);
            }
        }
        printf("\n");
    }

    free(edges);
    free(dist);
    return 0;
}
