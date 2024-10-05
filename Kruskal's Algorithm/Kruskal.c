#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_NODES 10

// Edge structure
typedef struct {
    int src, dest, weight;
} Edge;

// Union-Find structure
typedef struct {
    int parent[MAX_NODES];
    int rank[MAX_NODES];
} UnionFind;

// Function to initialize Union-Find structure
void initUnionFind(UnionFind* uf, int n) {
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
}

// Find function with path compression
int find(UnionFind* uf, int i) {
    if (uf->parent[i] != i) {
        uf->parent[i] = find(uf, uf->parent[i]);
    }
    return uf->parent[i];
}

// Union function by rank
void unionByRank(UnionFind* uf, int x, int y) {
    int xroot = find(uf, x);
    int yroot = find(uf, y);

    if (xroot != yroot) {
        if (uf->rank[xroot] < uf->rank[yroot]) {
            uf->parent[xroot] = yroot;
        } else if (uf->rank[xroot] > uf->rank[yroot]) {
            uf->parent[yroot] = xroot;
        } else {
            uf->parent[yroot] = xroot;
            uf->rank[xroot]++;
        }
    }
}

// Compare function for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal's algorithm implementation
void kruskal(Edge edges[], int numEdges, int numNodes) {
    UnionFind uf;
    initUnionFind(&uf, numNodes);

    qsort(edges, numEdges, sizeof(edges[0]), compareEdges);

    printf("Edges in the Minimum Spanning Tree:\n");
    int totalWeight = 0;

    for (int i = 0; i < numEdges; i++) {
        Edge currentEdge = edges[i];
        int x = find(&uf, currentEdge.src);
        int y = find(&uf, currentEdge.dest);

        if (x != y) {
            printf("%c -- %c = %d\n", 'A' + currentEdge.src, 'A' + currentEdge.dest, currentEdge.weight);
            unionByRank(&uf, x, y);
            totalWeight += currentEdge.weight;
        }
    }

    printf("Total weight of Minimum Spanning Tree: %d\n", totalWeight);
}

int main() {
    Edge edges[MAX_EDGES] = {
        {0, 1, 4}, // A-B
        {0, 2, 3}, // A-C
        {1, 2, 2}, // B-D
        {2, 3, 1}, // C-D
        {1, 3, 5}  // B-D
    };

    int numEdges = 5;
    int numNodes = 4; // A, B, C, D

    kruskal(edges, numEdges, numNodes);

    return 0;
}
