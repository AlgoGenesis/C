#include <stdio.h>
#include <limits.h>

void bellman_ford(int graph[][3], int V, int E, int start) {
    int distances[V];
    int predecessors[V];

    for (int i = 0; i < V; i++) {
        distances[i] = INT_MAX;
        predecessors[i] = -1;
    }

    distances[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];

            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                predecessors[v] = u;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        printf("%c:%d ", i + 'A', distances[i]);
    }
}

void main() {
    int V = 5;
    int E = 8;

    int graph[][3] = {
        {0, 1, 4},
        {0, 2, 1},
        {1, 2, -2},
        {1, 3, 5},
        {2, 3, 2},
        {2, 4, 4},
        {3, 4, -3},
        {4, 0, 0}
    };

    int start = 0;

    bellman_ford(graph, V, E, start);
}
