#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum key value, from
// the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[]) {
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print MST for a graph represented
// using adjacency matrix representation
void primMST(int graph[V][V]) {
    int parent[V];      // Array to store constructed MST
    int key[V];         // Key values used to pick minimum weight edge in cut
    bool mstSet[V];     // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST.
    key[0] = 0;          // Make key 0 so that this vertex is picked first
    parent[0] = -1;      // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // graph[u][v] is non-zero only for adjacent vertices
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    /* Example Graph:
           2    3
       (0)--(1)--(2)
        |   / \   |
       6| 8/   \5 |7
        | /     \ |
       (3)-------(4)
             9
    */

    int graph[V][V] = { 
        { 0, 2, 0, 6, 0 }, 
        { 2, 0, 3, 8, 5 }, 
        { 0, 3, 0, 0, 7 }, 
        { 6, 8, 0, 0, 9 }, 
        { 0, 5, 7, 9, 0 } 
    };

    // Compute and print the MST
    primMST(graph);

    return 0;
}
