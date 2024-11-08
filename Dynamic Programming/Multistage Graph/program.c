#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define INF 99

void shortestDist(int **graph, int n, int source, int target) {
    int dist[n + 1], path[n + 1];
     // Distance to the target node from itself is 0
    dist[target] = 0;
    path[target] = target;
	// Calculate shortest distance for other nodes in reverse order
    for (int i = target - 1; i >= 1; i--) {
        dist[i] = INF;
        path[i] = -1;
	 // Update the shortest distance by considering all possible paths
        for (int j = i + 1; j <= n; j++) {
            if (graph[i][j] != INF && dist[i] > graph[i][j] + dist[j]) {
                dist[i] = graph[i][j] + dist[j];
                path[i] = j; // Store the next node in the path
            }
        }
    }
    if (dist[source] == INF) {
        printf("There is no path from node %d to node %d\n", source, target);
        return;
    }
    printf("The shortest path distance from node %d to node %d is: %d\n", source, target, dist[source]);
    printf("Path: %d", source);
    int current = source;
    while (current != target) {
        current = path[current];
        printf(" -> %d", current);
    }
    printf("\n");
}

int main() {
    int n, source, target;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    int **graph = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 1; i <= n; i++) {
        graph[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source node: ");
    scanf("%d", &source);
    printf("Enter the target node: ");
    scanf("%d", &target);
    shortestDist(graph, n, source, target);
    for (int i = 1; i <= n; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}
