#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_NODES 10

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's algorithm
void primMST(int graph[MAX_NODES][MAX_NODES], int n) {
    int parent[MAX_NODES]; // Array to store constructed MST
    int key[MAX_NODES];    // Key values to pick minimum weight edge
    bool mstSet[MAX_NODES]; // To track vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start from the first vertex
    key[0] = 0;      // Key value of the first vertex is 0
    parent[0] = -1;  // First node is always the root of the MST

    // The MST will have n vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, n);
        mstSet[u] = true; // Add the picked vertex to the MST

        // Update key value and parent index of the adjacent vertices
        for (int v = 0; v < n; v++) {
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++) {
        printf("%c -- %c \t%d\n", 'A' + parent[i], 'A' + i, graph[i][parent[i]]);
    }
}

int main() {
    int n = 4; // Number of vertices
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 2, 3, 0}, // A
        {2, 0, 0, 5}, // B
        {3, 0, 0, 1}, // C
        {0, 5, 1, 0}  // D
    };

    primMST(graph, n);

    return 0;
}
