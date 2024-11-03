#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

int graph[MAX_NODES][MAX_NODES];   // Adjacency matrix
int distance[MAX_NODES];           // Stores shortest distance from start node
int visited[MAX_NODES];            // Tracks visited nodes
int previous[MAX_NODES];           // To reconstruct the path
int n;                             // Number of nodes in the graph

// Simple function to dynamically increase weight when an edge is visited
void update_weights_dynamically(int node) {
    for (int i = 0; i < n; i++) {
        if (graph[node][i] != INF) {
            graph[node][i] += 2;   // Increase the weight slightly each time
        }
    }
}

// Function to find the node with the minimum distance that hasn't been visited
int find_min_distance() {
    int min = INF, min_index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dynamic weighted search algorithm (Dijkstra-based)
void dynamic_weighted_search(int start, int goal) {
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = 0;
        previous[i] = -1;
    }
    distance[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int current = find_min_distance();
        if (current == -1) break;   // If no reachable node remains

        visited[current] = 1;
        update_weights_dynamically(current);

        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[current][i] != INF && 
                distance[current] + graph[current][i] < distance[i]) {
                distance[i] = distance[current] + graph[current][i];
                previous[i] = current;
            }
        }
    }

    // Display the shortest path if reachable
    if (distance[goal] == INF) {
        printf("No path from %d to %d\n", start, goal);
    } else {
        printf("Shortest path cost from %d to %d: %d\n", start, goal, distance[goal]);
        printf("Path: ");
        int path[MAX_NODES], index = 0;
        for (int v = goal; v != -1; v = previous[v]) {
            path[index++] = v;
        }
        for (int i = index - 1; i >= 0; i--) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
}

int main() {
    int start, goal;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Initialize graph with "infinite" weights
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    // Input the edges and weights
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (u v weight) format:\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;  // For undirected graph; remove for directed
    }

    // Input start and goal nodes
    printf("Enter the start node: ");
    scanf("%d", &start);
    printf("Enter the goal node: ");
    scanf("%d", &goal);

    dynamic_weighted_search(start, goal);

    return 0;
}
