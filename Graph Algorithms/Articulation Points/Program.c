#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int time = 0; // Global timer

// Structure to represent a graph
typedef struct {
    int vertices;          // Number of vertices
    int adj[MAX][MAX];     // Adjacency matrix
} Graph;

// Function prototypes
Graph* createGraph(int vertices);
void addEdge(Graph* g, int u, int v);
void articulationPointsUtil(Graph* g, int u, int visited[], int parent[], int low[], int disc[], int ap[]);
void findArticulationPoints(Graph* g);

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* g = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (u v) format:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(g, u, v);
    }

    findArticulationPoints(g);

    return 0;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->vertices = vertices;

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            g->adj[i][j] = 0;

    return g;
}

// Function to add an edge to the graph
void addEdge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1; // Undirected graph
}

// A recursive function that finds articulation points using DFS
void articulationPointsUtil(Graph* g, int u, int visited[], int parent[], int low[], int disc[], int ap[]) {
    int children = 0;
    visited[u] = 1; // Mark the current node as visited
    disc[u] = low[u] = ++time; // Initialize discovery time and low value

    for (int v = 0; v < g->vertices; v++) {
        if (g->adj[u][v]) { // If u-v is an edge
            if (!visited[v]) { // If v is not visited
                parent[v] = u;
                children++;
                articulationPointsUtil(g, v, visited, parent, low, disc, ap);

                // Check if the subtree rooted at v has a connection back to one of the ancestors of u
                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                // u is an articulation point in following cases:
                // 1. u is root of DFS tree and has two or more children.
                if (parent[u] == -1 && children > 1)
                    ap[u] = 1;

                // 2. If u is not root and low value of one of its child is more than discovery value of u.
                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = 1;
            } else if (v != parent[u]) { // Update low value of u for back edge
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }
}

// Function to find and print articulation points
void findArticulationPoints(Graph* g) {
    int visited[MAX], parent[MAX], low[MAX], disc[MAX], ap[MAX];

    // Initialize all arrays
    for (int i = 0; i < g->vertices; i++) {
        visited[i] = 0;
        parent[i] = -1;
        low[i] = -1;
        disc[i] = -1;
        ap[i] = 0; // Initialize articulation point
    }

    // Call the recursive function to find articulation points
    for (int i = 0; i < g->vertices; i++) {
        if (!visited[i])
            articulationPointsUtil(g, i, visited, parent, low, disc, ap);
    }

    printf("Articulation points in the graph are: ");
    for (int i = 0; i < g->vertices; i++) {
        if (ap[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
