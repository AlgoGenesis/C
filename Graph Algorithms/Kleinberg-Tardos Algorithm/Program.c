#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
    int edges[MAX_NODES][MAX_NODES];
    int nodeCount;
} Graph;

// Function to initialize the graph
void initializeGraph(Graph* g, int nodeCount) {
    g->nodeCount = nodeCount;
    memset(g->edges, 0, sizeof(g->edges));
}

// Function to add an edge
void addEdge(Graph* g, int src, int dest) {
    g->edges[src][dest] = 1; // Directed edge from src to dest
}

// Function to print the adjacency matrix
void printGraph(Graph* g) {
    for (int i = 0; i < g->nodeCount; i++) {
        for (int j = 0; j < g->nodeCount; j++) {
            printf("%d ", g->edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Graph g;
    int nodeCount, edges;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodeCount);
    initializeGraph(&g, nodeCount);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }

    printf("Adjacency Matrix:\n");
    printGraph(&g);

    return 0;
}
