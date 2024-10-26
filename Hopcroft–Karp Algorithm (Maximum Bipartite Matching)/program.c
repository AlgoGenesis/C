#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000  // Maximum number of vertices in each part

int U, V;  // Number of vertices in each part
int adj[MAX][MAX];  // Adjacency list for the bipartite graph
int pairU[MAX], pairV[MAX], dist[MAX];

// BFS function to find all augmenting paths of the shortest length
bool bfs() {
    int queue[MAX], front = 0, rear = 0;

    for (int u = 1; u <= U; u++) {
        if (pairU[u] == 0) {
            dist[u] = 0;
            queue[rear++] = u;
        } else {
            dist[u] = -1;
        }
    }

    dist[0] = -1;

    while (front < rear) {
        int u = queue[front++];

        if (dist[u] < dist[0]) {
            for (int v = 1; v <= V; v++) {
                if (adj[u][v] && dist[pairV[v]] == -1) {
                    dist[pairV[v]] = dist[u] + 1;
                    queue[rear++] = pairV[v];
                }
            }
        }
    }
    return dist[0] != -1;
}

// DFS function to find augmenting paths
bool dfs(int u) {
    if (u != 0) {
        for (int v = 1; v <= V; v++) {
            if (adj[u][v] && dist[pairV[v]] == dist[u] + 1) {
                if (dfs(pairV[v])) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = -1;
        return false;
    }
    return true;
}

// Function to find maximum matching using Hopcroft–Karp algorithm
int hopcroftKarp() {
    memset(pairU, 0, sizeof(pairU));
    memset(pairV, 0, sizeof(pairV));
    memset(dist, 0, sizeof(dist));

    int matching = 0;

    while (bfs()) {
        for (int u = 1; u <= U; u++) {
            if (pairU[u] == 0 && dfs(u)) {
                matching++;
            }
        }
    }
    return matching;
}

int main() {
    // Example input: Number of vertices in each set and edges between them
    U = 4;
    V = 4;
    adj[1][1] = adj[1][2] = 1;
    adj[2][2] = adj[2][3] = 1;
    adj[3][3] = adj[3][4] = 1;
    adj[4][1] = adj[4][4] = 1;

    printf("Maximum matching is %d\n", hopcroftKarp());

    return 0;
}
