// Stoer-Wagner Algorithm

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_NODES 100  // Define maximum nodes for the graph

// Function to find the minimum cut in the graph
int minCut(int graph[MAX_NODES][MAX_NODES], int n) {
    int minCutValue = INT_MAX; // Initialize the minimum cut value
    int vertices[MAX_NODES];   // Stores the vertices in the graph

    // Initialize vertices list
    for (int i = 0; i < n; i++) {
        vertices[i] = i;
    }

    // Iterate over phases
    for (int phase = n; phase > 1; phase--) {
        int maxWeights[MAX_NODES];
        bool added[MAX_NODES] = {false};
        
        // Start with the first vertex
        added[vertices[0]] = true;
        int lastAdded = vertices[0];

        // Add vertices one by one
        for (int i = 1; i < phase; i++) {
            int maxWeight = -1, maxIndex = -1;

            // Find the vertex with the maximum weight edge
            for (int j = 0; j < phase; j++) {
                if (!added[vertices[j]]) {
                    maxWeights[vertices[j]] += graph[lastAdded][vertices[j]];

                    if (maxWeights[vertices[j]] > maxWeight) {
                        maxWeight = maxWeights[vertices[j]];
                        maxIndex = j;
                    }
                }
            }

            added[vertices[maxIndex]] = true;
            lastAdded = vertices[maxIndex];
        }

        // Calculate the cut value for this phase
        int s = vertices[lastAdded];
        int t = vertices[lastAdded - 1];
        minCutValue = (minCutValue < maxWeights[s]) ? minCutValue : maxWeights[s];

        // Merge vertices s and t
        for (int i = 0; i < phase; i++) {
            graph[vertices[i]][t] += graph[vertices[i]][s];
            graph[t][vertices[i]] = graph[vertices[i]][t];
        }

        vertices[lastAdded - 1] = t;
    }

    return minCutValue;
}

// Driver code to test the algorithm
int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix (weights of edges):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int min_cut = minCut(graph, n);
    printf("The minimum cut of the graph is: %d\n", min_cut);

    return 0;
}
