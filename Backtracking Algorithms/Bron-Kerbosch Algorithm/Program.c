#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to print a maximal clique
void printClique(int *clique, int size) {
    printf("Maximal Clique: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", clique[i]);
    }
    printf("\n");
}

// Bron-Kerbosch algorithm
void bronKerbosch(int *R, int r_size, int *P, int p_size, int *X, int x_size, int graph[MAX_VERTICES][MAX_VERTICES]) {
    if (p_size == 0 && x_size == 0) {
        printClique(R, r_size);
        return;
    }

    for (int i = 0; i < p_size; i++) {
        int v = P[i];
        
        // Create new sets for R, P, and X
        int newR[MAX_VERTICES];
        int newP[MAX_VERTICES];
        int newX[MAX_VERTICES];
        int new_r_size = r_size + 1;
        int new_p_size = 0, new_x_size = 0;

        // Add v to R
        newR[0] = v;

        // Add vertices adjacent to v to newP and newX
        for (int j = 0; j < MAX_VERTICES; j++) {
            if (graph[v][j]) {
                if (j < p_size) {
                    newP[new_p_size++] = j; // Add to newP
                }
                if (j < x_size) {
                    newX[new_x_size++] = j; // Add to newX
                }
            }
        }

        // Combine R and P and recursively call the algorithm
        for (int j = 0; j < r_size; j++) {
            newR[j + 1] = R[j]; // Combine R
        }

        bronKerbosch(newR, new_r_size, newP, new_p_size, newX, new_x_size, graph);

        // Update P and X
        for (int j = 0; j < p_size; j++) {
            if (P[j] == v) {
                // Remove v from P
                for (int k = j; k < p_size - 1; k++) {
                    P[k] = P[k + 1];
                }
                p_size--;
                break;
            }
        }
        // Add v to X
        X[x_size++] = v;
    }
}

// Main function
int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix
    int n; // Number of vertices

    // Define the graph
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize R, P, and X
    int R[MAX_VERTICES] = {0}; // Current clique
    int P[MAX_VERTICES]; // Potential candidates
    int X[MAX_VERTICES]; // Excluded vertices
    int p_size = 0;

    // Initialize P with all vertices
    for (int i = 0; i < n; i++) {
        P[p_size++] = i;
    }

    // Call the Bron-Kerbosch algorithm
    bronKerbosch(R, 0, P, p_size, X, 0, graph);

    return 0;
}
