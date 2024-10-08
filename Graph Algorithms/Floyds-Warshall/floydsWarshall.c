#include <stdio.h>

#define INF 99999  // A large value to represent infinity
#define V 4        // Number of vertices in the graph

// Function to print the shortest distance matrix
void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Function to implement Floyd-Warshall algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V];  // dist will be the output matrix that will have the shortest distances

    // Initialize the solution matrix same as the input graph matrix.
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Add all vertices one by one to the set of intermediate vertices.
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination for the above-picked source
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the final shortest distance matrix
    printSolution(dist);
}

int main() {
    // Create a graph represented as an adjacency matrix.
    // Let INF represent the absence of an edge
    int graph[V][V] = {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    // Apply Floyd-Warshall algorithm
    floydWarshall(graph);
    return 0;
}
