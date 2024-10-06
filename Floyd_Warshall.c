#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void shortestPath(int graph[5][5], int dist[5][5], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void main() { 
    int graph[5][5] = {{0, 4, INF, 5, INF},
                       {INF, 0, 1, INF, 6},
                       {2, INF, 0, 3, INF},
                       {INF, INF, 1, 0, 2},
                       {1, INF, INF, 4, 0}};

    int dist[5][5];
    int n = 5;
    shortestPath(graph, dist, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}
