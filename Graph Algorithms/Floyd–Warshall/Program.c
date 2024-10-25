#include<stdio.h>

// Function to execute Floyd-Warshall algorithm on adjacency matrix
void floyd(int[10][10], int); 

// Function to return the minimum of two integers
int min(int, int);

void main() {
    int n, a[10][10], i, j;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input the cost adjacency matrix
    printf("\nEnter the cost adjacency matrix\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);  // Read the cost or weight of each edge

    // Call the Floyd-Warshall function with the adjacency matrix
    floyd(a, n);
}

// Function to perform the Floyd-Warshall algorithm
void floyd(int a[10][10], int n) {
    int d[10][10], i, j, k;

    // Initialize the distance matrix d with values from adjacency matrix a
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            d[i][j] = a[i][j];
    }

    // Floyd-Warshall algorithm: consider each node k as an intermediate node
    for(k = 1; k <= n; k++) {
        for(i = 1; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                // Update the shortest distance if a shorter path is found through node k
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // Print the resulting distance matrix after applying Floyd-Warshall algorithm
    printf("\nThe distance matrix is\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }
}

// Function to return the minimum of two integers
int min(int a, int b) {
    if(a < b)
        return a;
    else
        return b;
}
