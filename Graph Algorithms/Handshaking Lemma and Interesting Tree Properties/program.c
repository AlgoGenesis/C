#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Structure for Graph using Adjacency Matrix
typedef struct {
    int adjMatrix[MAX_NODES][MAX_NODES];
    int nodes;
    int edges;
} Graph;

// Initialize the graph with zero edges
void initGraph(Graph* g, int nodes) {
    g->nodes = nodes;
    g->edges = 0;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Add an undirected edge between two nodes
void addEdge(Graph* g, int u, int v) {
    if (u >= g->nodes || v >= g->nodes) {
        printf("Invalid nodes\n");
        return;
    }
    g->adjMatrix[u][v] = 1;
    g->adjMatrix[v][u] = 1;
    g->edges++;
}

// Calculate the sum of degrees to verify Handshaking Lemma
bool verifyHandshakingLemma(Graph* g) {
    int degreeSum = 0;
    for (int i = 0; i < g->nodes; i++) {
        int degree = 0;
        for (int j = 0; j < g->nodes; j++) {
            if (g->adjMatrix[i][j] == 1)
                degree++;
        }
        degreeSum += degree;
    }
    return degreeSum == 2 * g->edges;
}

// Check if the structure is a tree
bool isTree(Graph* g) {
    // A tree with n nodes has n-1 edges
    if (g->edges != g->nodes - 1)
        return false;

    // A connected and acyclic graph with n-1 edges is a tree
    // This is a simple approach, assuming a connected graph without cycles
    return true;
}

int main() {
    int nodes = 4;
    Graph g;
    initGraph(&g, nodes);

    // Add edges
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 0, 3);

    printf("Total nodes: %d\n", g.nodes);
    printf("Total edges: %d\n", g.edges);

    // Check Handshaking Lemma
    if (verifyHandshakingLemma(&g)) {
        printf("Handshaking Lemma holds: Sum of degrees = 2 * Number of edges\n");
    } else {
        printf("Handshaking Lemma does not hold.\n");
    }

    // Check if the graph is a tree
    if (isTree(&g)) {
        printf("The graph is a tree.\n");
    } else {
        printf("The graph is not a tree.\n");
    }

    return 0;
}
