#include <stdio.h>
#include <stdbool.h>

#define V 4 // Number of vertices in the graph

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false; // If the adjacent vertex has the same color
        }
    }
    return true;
}

// Recursive function to solve M-coloring problem
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    // Base case: If all vertices are assigned a color then return true
    if (v == V) {
        return true;
    }

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is possible
        if (isSafe(graph, color, v, c)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution then remove it
            color[v] = 0;
        }
    }

    return false; // If no color can be assigned to this vertex
}

// Function to solve the M-coloring problem
bool graphColoring(int graph[V][V], int m) {
    int color[V]; // Color assignment to vertices

    // Initialize all vertices as uncolored
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    // Call the recursive utility function
    if (graphColoringUtil(graph, m, color, 0)) {
        printf("Solution Exists: Following are the assigned colors:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d --> Color %d\n", i, color[i]);
        }
        return true;
    }

    printf("Solution does not exist\n");
    return false;
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors

    graphColoring(graph, m);

    return 0;
}
