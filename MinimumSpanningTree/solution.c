#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight, index;
} Edge;

typedef struct {
    int *parent;
    int *rank;
    int n;
} DisjointSet;

// Function to create a disjoint set
DisjointSet* createSet(int n) {
    DisjointSet* ds = (DisjointSet*)malloc(sizeof(DisjointSet));
    ds->parent = (int*)malloc(n * sizeof(int));
    ds->rank = (int*)malloc(n * sizeof(int));
    ds->n = n;
    for (int i = 0; i < n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
    return ds;
}

// Find function with path compression
int find(DisjointSet* ds, int x) {
    if (ds->parent[x] != x) {
        ds->parent[x] = find(ds, ds->parent[x]);
    }
    return ds->parent[x];
}

// Union function by rank
void unionSets(DisjointSet* ds, int x, int y) {
    int rootX = find(ds, x);
    int rootY = find(ds, y);
    if (rootX != rootY) {
        if (ds->rank[rootX] > ds->rank[rootY]) {
            ds->parent[rootY] = rootX;
        } else if (ds->rank[rootX] < ds->rank[rootY]) {
            ds->parent[rootX] = rootY;
        } else {
            ds->parent[rootY] = rootX;
            ds->rank[rootX]++;
        }
    }
}

// Compare function for sorting edges
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Function to calculate the weight of the MST
int kruskal(Edge* edges, int n, int m, int skipIndex, int includeIndex) {
    DisjointSet* ds = createSet(n);
    int weight = 0;
    if (includeIndex != -1) {
        unionSets(ds, edges[includeIndex].u, edges[includeIndex].v);
        weight += edges[includeIndex].weight;
    }
    for (int i = 0; i < m; i++) {
        if (i == skipIndex) continue;
        if (find(ds, edges[i].u) != find(ds, edges[i].v)) {
            unionSets(ds, edges[i].u, edges[i].v);
            weight += edges[i].weight;
        }
    }
    // Check if we formed a valid MST
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (ds->parent[i] == i) components++;
    }
    free(ds->parent);
    free(ds->rank);
    free(ds);
    return components == 1 ? weight : -1; // Return -1 if not all nodes are connected
}

// Main function to find critical and pseudo-critical edges
void findCriticalAndPseudoCriticalEdges(int n, int m, int edges[][3], int* returnSize, int** returnArray) {
    Edge* edgeList = (Edge*)malloc(m * sizeof(Edge));
    for (int i = 0; i < m; i++) {
        edgeList[i].u = edges[i][0];
        edgeList[i].v = edges[i][1];
        edgeList[i].weight = edges[i][2];
        edgeList[i].index = i;
    }

    // Sort edges by weight
    qsort(edgeList, m, sizeof(Edge), compareEdges);

    // Find the weight of the MST without any edges removed
    int mstWeight = kruskal(edgeList, n, m, -1, -1);

    int* criticalEdges = (int*)malloc(m * sizeof(int));
    int* pseudoCriticalEdges = (int*)malloc(m * sizeof(int));
    int criticalCount = 0;
    int pseudoCount = 0;

    for (int i = 0; i < m; i++) {
        // Check for critical edge
        if (kruskal(edgeList, n, m, i, -1) > mstWeight) {
            criticalEdges[criticalCount++] = edgeList[i].index;
        } else if (kruskal(edgeList, n, m, -1, i) == mstWeight) {
            // Check for pseudo-critical edge
            pseudoCriticalEdges[pseudoCount++] = edgeList[i].index;
        }
    }

    // Prepare