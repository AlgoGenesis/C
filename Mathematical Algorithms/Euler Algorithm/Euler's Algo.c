// Euler's Algorithm for finding Eulerian paths and circuits

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency matrix for the graph
int graph[MAX][MAX];
int degree[MAX];
int n;  // Number of vertices

// Stack to store the Eulerian path
int stack[MAX], top = -1;
int path[MAX], pathIndex = 0;

// Push onto the stack
void push(int v) {
    stack[++top] = v;
}

// Pop from the stack
int pop() {
    return stack[top--];
}

// Check if the graph is Eulerian (returns 0 for Eulerian circuit, 1 for Eulerian path, -1 if none)
int isEulerian() {
    int odd = 0;
    for (int i = 0; i < n; i++) {
        if (degree[i] % 2 != 0) odd++;
    }

    if (odd == 0) return 0;  // Eulerian Circuit
    if (odd == 2) return 1;  // Eulerian Path
    return -1;               // Neither
}

// Find an Eulerian path/circuit using DFS
void findEulerian(int start) {
    push(start);

    while (top != -1) {
        int v = stack[top];
        int i;
        for (i = 0; i < n; i++) {
            if (graph[v][i] > 0) {
                // Remove the edge from the graph and proceed
                graph[v][i]--;
                graph[i][v]--;
                push(i);
                break;
            }
        }

        if (i == n) {
            // Backtrack
            path[pathIndex++] = pop();
        }
    }
}

int main() {
    int edges, u, v;

    // Input: number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize graph and degree arrays
    for (int i = 0; i < n; i++) {
        degree[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input the edges of the graph
    printf("Enter the edges (u v) format:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v]++;
        graph[v][u]++;
        degree[u]++;
        degree[v]++;
    }

    // Check if the graph is Eulerian
    int type = isEulerian();
    if (type == -1) {
        printf("The graph does not have an Eulerian Path or Circuit.\n");
        return 0;
    }

    // Find the starting vertex
    int start = 0;
    if (type == 1) {
        for (int i = 0; i < n; i++) {
            if (degree[i] % 2 != 0) {
                start = i;
                break;
            }
        }
    }

    // Find and print the Eulerian path or circuit
    findEulerian(start);

    printf("Eulerian %s: ", (type == 0) ? "Circuit" : "Path");
    for (int i = pathIndex - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");

    return 0;
}

