#include <stdio.h>
#include <limits.h>
#define V 5  // Number of vertices

// Function to find the vertex with minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the shortest distances from the source
void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Function that implements Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];   // dist[i] will hold the shortest distance from src to i
    int visited[V]; // visited[i] will be true if vertex i is included in the shortest path

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, visited);

        // Mark the picked vertex as processed
        visited[u] = 1;

        // Update dist[] of adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if not visited, there is an edge from u to v, 
            // and the total weight of the path from src to v through u is less than dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

int main() {
    // Example graph as adjacency matrix
    int graph[V][V] = {
        {0, 1, 4, 0, 0},
        {1, 0, 2, 0, 6},
        {4, 2, 0, 3, 0},
        {0, 0, 3, 0, 2},
        {0, 6, 0, 2, 0}
    };

    dijkstra(graph, 0);  // Find shortest paths from vertex 0
    return 0;
}
