#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

// Function to perform DFS
void DFS(int graph[MAX_NODES][MAX_NODES], int visited[], int node, int n) {
    // Mark the current node as visited
    visited[node] = 1;
    printf("%c ", 'A' + node); // Assuming A=0, B=1, C=2, etc.

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            DFS(graph, visited, i, n);
        }
    }
}

int main() {
    int n = 7; // Number of vertices
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 1, 0, 0, 0}, // A
        {1, 0, 0, 0, 1, 1, 0}, // B
        {1, 0, 0, 0, 0, 0, 0}, // C
        {1, 0, 0, 0, 0, 0, 1}, // D
        {0, 1, 0, 0, 0, 0, 0}, // E
        {0, 1, 0, 0, 0, 0, 0}, // F
        {0, 0, 0, 1, 0, 0, 0}  // G
    };

    int visited[MAX_NODES] = {0}; // Initialize visited array

    printf("Depth First Search starting from vertex A:\n");
    DFS(graph, visited, 0, n); // Start DFS from vertex A (0)

    return 0;
}
