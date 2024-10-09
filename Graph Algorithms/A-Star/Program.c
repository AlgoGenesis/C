#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum f-cost
int minFCost(int f[], bool openSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (openSet[v] && f[v] < min) {
            min = f[v], min_index = v;
        }
    }

    return min_index;
}

// Heuristic function for estimating distance to the goal
int heuristic(int src, int dest) {
    // Example heuristic: Euclidean distance approximation (for a grid-like graph)
    int h[V] = {7, 6, 2, 1, 0};  // Hardcoded heuristic values for demo (node 4 is the goal)
    return h[src];
}

// Function to print the path
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

// Function to implement the A* algorithm for a graph represented by an adjacency matrix
void aStar(int graph[V][V], int src, int dest) {
    int g[V];  // g[i] is the cost from the source node to i
    int f[V];  // f[i] = g[i] + heuristic(i, dest), i.e., the estimated cost from src to dest via i
    bool openSet[V];  // Nodes to be evaluated
    bool closedSet[V];  // Nodes that have already been evaluated
    int parent[V];  // Array to store the path

    // Initialize all g and f values as INFINITE and openSet[] as true for all nodes
    for (int i = 0; i < V; i++) {
        g[i] = INT_MAX;
        f[i] = INT_MAX;
        openSet[i] = true;
        closedSet[i] = false;
        parent[i] = -1;
    }

    // Distance of the source node from itself is 0
    g[src] = 0;
    f[src] = heuristic(src, dest);

    // Loop until the destination is reached or openSet is empty
    while (true) {
        int current = minFCost(f, openSet);

        // If we've reached the destination, print the path
        if (current == dest) {
            printf("Path: %d", src);
            printPath(parent, dest);
            printf("\nTotal cost: %d\n", g[dest]);
            return;
        }

        // Mark the current node as evaluated
        openSet[current] = false;
        closedSet[current] = true;

        // Update neighbors of the current node
        for (int v = 0; v < V; v++) {
            // Only consider valid neighbors and nodes not already evaluated
            if (graph[current][v] && !closedSet[v]) {
                int tentative_g = g[current] + graph[current][v];

                if (tentative_g < g[v]) {
                    parent[v] = current;
                    g[v] = tentative_g;
                    f[v] = g[v] + heuristic(v, dest);
                    openSet[v] = true;
                }
            }
        }

        // If no valid nodes are left to process, return
        bool empty = true;
        for (int i = 0; i < V; i++) {
            if (openSet[i]) {
                empty = false;
                break;
            }
        }
        if (empty) {
            printf("No path found!\n");
            return;
        }
    }
}

int main() {
    // Example graph represented by an adjacency matrix (undirected, weighted graph)
    int graph[V][V] = {
        {0, 10, 0, 0, 0},
        {10, 0, 20, 0, 0},
        {0, 20, 0, 30, 10},
        {0, 0, 30, 0, 10},
        {0, 0, 10, 10, 0}
    };

    int src = 0;  // Start node
    int dest = 4; // Goal node

    printf("A* Algorithm:\n");
    aStar(graph, src, dest);

    return 0;
}
