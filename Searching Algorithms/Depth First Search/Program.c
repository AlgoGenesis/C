#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency matrix representation of the graph
int graph[MAX][MAX];
int visited[MAX];

// Function to perform DFS
void DFS(int vertex, int n) {
    visited[vertex] = 1; // Mark the current vertex as visited
    printf("Visited vertex: %d\n", vertex);

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, n); // Visit the unvisited neighboring vertex
        }
    }
}

int main() {
    int n, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the graph and visited array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input edges for the graph
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Perform DFS starting from the specified vertex
    DFS(startVertex, n);

    return 0;
}
