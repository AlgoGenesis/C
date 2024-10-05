#include <stdio.h>
#include <stdlib.h>

// This function to perform Kahn's Algorithm for topological sorting
void kahnTopologicalSort(int V, int adj[V][V]) {
    int inDegree[V];          // Initialize in-degree array
    int topoOrder[V];         // Array to store topological order
    int queue[V];             // Queue for vertices with in-degree 0
    int front = 0, rear = 0;  // Queue pointers
    int topoIndex = 0;        // To track the topological order index

    // Calculate in-degree of each vertex
    for (int i = 0; i < V; i++) {
        inDegree[i] = 0; // Initialize in-degree of all vertices to 0
    }
    
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) {
                inDegree[v]++;  // Increment in-degree of vertex v
            }
        }
    }

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;  // Enqueue the vertex
        }
    }

    // Process vertices in the queue
    while (front < rear) {
        int u = queue[front++];   // Dequeue the vertex
        topoOrder[topoIndex++] = u; // Add to the topological order
        
        // For each neighbor of u, reduce their in-degree
        for (int v = 0; v < V; v++) {
            if (adj[u][v] == 1) { // Check if there is an edge u -> v
                inDegree[v]--;     // Decrease in-degree of v
                if (inDegree[v] == 0) {
                    queue[rear++] = v; // Enqueue v if in-degree becomes 0
                }
            }
        }
    }

    // Check if topological sort is possible
    if (topoIndex != V) {
        printf("The graph contains a cycle. Topological sort not possible.\n");
        return;
    }

    // Print the topological order
    printf("Topological Sort: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", topoOrder[i]);
    }
    printf("\n");
}

int main() {
    int V = 6; // Number of vertices
    int adj[6][6] = { // Adjacency matrix representation of the graph
        {0, 1, 1, 0, 0, 0}, // 0 --> 1, 0 --> 2
        {0, 0, 0, 1, 0, 0}, // 1 --> 3
        {0, 0, 0, 1, 0, 0}, // 2 --> 3
        {0, 0, 0, 0, 1, 0}, // 3 --> 4
        {0, 0, 0, 0, 0, 1}, // 4 --> 5
        {0, 0, 0, 0, 0, 0}  // 5 has no outgoing edges
    };

    kahnTopologicalSort(V, adj); // Perform Kahn's Algorithm
    return 0;
}

/*
Expected Output:
Topological Sort: 0 1 2 3 4 5 
*/
