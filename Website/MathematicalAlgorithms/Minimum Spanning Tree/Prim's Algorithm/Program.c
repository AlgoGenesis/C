#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed Minimum Spanning Tree
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Function that implements Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Array to store the MST
    int key[V];     // Key values to pick minimum weight edge
    bool mstSet[V]; // To represent the set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start from the first vertex
    key[0] = 0;
    parent[0] = -1;  // First node is always the root of MST

    // Construct the MST
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // Pick the minimum key vertex not yet included in MST
        mstSet[u] = true;            // Add the vertex to the MST

        // Update the key and parent for adjacent vertices
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than the current key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Call Prim's algorithm to find the MST
    primMST(graph);

    return 0;
}