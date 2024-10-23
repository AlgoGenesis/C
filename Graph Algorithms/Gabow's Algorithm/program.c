#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 100  // Maximum number of vertices in the graph

// Global variables
int adj[MAX_V][MAX_V];  // Adjacency matrix of the graph
int discovered[MAX_V], sccId[MAX_V], visited[MAX_V], sccCount, discoveryTime, stackTop;
int stack[MAX_V], root[MAX_V];

// Function to initialize graph
void initializeGraph(int V) {
    memset(adj, 0, sizeof(adj));
    memset(discovered, -1, sizeof(discovered));
    memset(sccId, -1, sizeof(sccId));
    memset(visited, 0, sizeof(visited));
    sccCount = discoveryTime = stackTop = 0;
}

// Gabow's algorithm to find SCCs
void dfs(int u, int V) {
    discovered[u] = root[u] = discoveryTime++;
    stack[stackTop++] = u;
    visited[u] = 1;

    for (int v = 0; v < V; v++) {
        if (adj[u][v]) {
            if (discovered[v] == -1) {
                dfs(v, V);
            }
            if (sccId[v] == -1) {
                root[u] = (root[u] < root[v]) ? root[u] : root[v];
            }
        }
    }

    if (root[u] == discovered[u]) {
        while (1) {
            int v = stack[--stackTop];
            sccId[v] = sccCount;
            if (u == v) break;
        }
        sccCount++;
    }
}

// Function to find SCCs in the graph
void findSCCs(int V) {
    for (int i = 0; i < V; i++) {
        if (discovered[i] == -1) {
            dfs(i, V);
        }
    }
}

// Main function
int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    initializeGraph(V);

    printf("Enter the edges (u v) for each directed edge:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    findSCCs(V);

    printf("Strongly Connected Components:\n");
    for (int i = 0; i < sccCount; i++) {
        printf("SCC %d:", i);
        for (int v = 0; v < V; v++) {
            if (sccId[v] == i) {
                printf(" %d", v);
            }
        }
        printf("\n");
    }

    return 0;
}
