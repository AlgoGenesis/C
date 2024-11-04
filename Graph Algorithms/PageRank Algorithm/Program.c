#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100
#define DAMPING_FACTOR 0.85
#define CONVERGENCE_THRESHOLD 0.0001

// Structure to store graph edges
typedef struct {
    int src;
    int dest;
} Edge;

// Initialize adjacency matrix and out-degree array
void initializeGraph(int adjMatrix[MAX_NODES][MAX_NODES], int outDegree[MAX_NODES], int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            adjMatrix[i][j] = 0;
        }
        outDegree[i] = 0;
    }
}

// Add an edge to the graph
void addEdge(int adjMatrix[MAX_NODES][MAX_NODES], int outDegree[MAX_NODES], Edge edge) {
    adjMatrix[edge.src][edge.dest] = 1;
    outDegree[edge.src]++;
}

// PageRank calculation
void calculatePageRank(int adjMatrix[MAX_NODES][MAX_NODES], int outDegree[MAX_NODES], int numNodes, double pageRank[MAX_NODES]) {
    double tempRank[MAX_NODES];
    int converged;

    // Initialize PageRank values
    for (int i = 0; i < numNodes; i++) {
        pageRank[i] = 1.0 / numNodes;
    }

    do {
        converged = 1;

        // Copy current page ranks to temporary array
        for (int i = 0; i < numNodes; i++) {
            tempRank[i] = pageRank[i];
        }

        // Update page ranks for each node
        for (int i = 0; i < numNodes; i++) {
            double incomingRankSum = 0.0;

            for (int j = 0; j < numNodes; j++) {
                if (adjMatrix[j][i] == 1) {
                    incomingRankSum += tempRank[j] / outDegree[j];
                }
            }

            pageRank[i] = (1 - DAMPING_FACTOR) / numNodes + DAMPING_FACTOR * incomingRankSum;

            if (fabs(pageRank[i] - tempRank[i]) > CONVERGENCE_THRESHOLD) {
                converged = 0;
            }
        }
    } while (!converged);
}

int main() {
    int numNodes = 4; // Example number of nodes
    int numEdges = 4; // Example number of edges
    Edge edges[] = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 0}
    };

    int adjMatrix[MAX_NODES][MAX_NODES];
    int outDegree[MAX_NODES];
    double pageRank[MAX_NODES];

    // Initialize graph and add edges
    initializeGraph(adjMatrix, outDegree, numNodes);
    for (int i = 0; i < numEdges; i++) {
        addEdge(adjMatrix, outDegree, edges[i]);
    }

    // Calculate PageRank
    calculatePageRank(adjMatrix, outDegree, numNodes, pageRank);

    // Print PageRank values
    printf("PageRank values:\n");
    for (int i = 0; i < numNodes; i++) {
        printf("Node %d: %.6f\n", i, pageRank[i]);
    }

    return 0;
}
