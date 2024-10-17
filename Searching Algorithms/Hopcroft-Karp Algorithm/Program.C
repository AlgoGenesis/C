// hopcroft_karp.c
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NIL 0
#define INF (1<<28)

int n, m;  // Number of nodes on left and right side
int pairU[100], pairV[100], dist[100];
int adj[100][100];  // Adjacency matrix

// BFS function to check if there is an augmenting path
bool bfs() {
    int queue[100], front = 0, back = 0;

    for (int u = 1; u <= n; u++) {
        if (pairU[u] == NIL) {
            dist[u] = 0;
            queue[back++] = u;
        } else {
            dist[u] = INF;
        }
    }
    dist[NIL] = INF;

    while (front < back) {
        int u = queue[front++];
        if (dist[u] < dist[NIL]) {
            for (int v = 1; v <= m; v++) {
                if (adj[u][v] && dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    queue[back++] = pairV[v];
                }
            }
        }
    }
    return dist[NIL] != INF;
}

// DFS function to find augmenting path
bool dfs(int u) {
    if (u != NIL) {
        for (int v = 1; v <= m; v++) {
            if (adj[u][v] && dist[pairV[v]] == dist[u] + 1) {
                if (dfs(pairV[v])) {
                    pairU[u] = v;
                    pairV[v] = u;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

// Function to find maximum matching
int hopcroftKarp() {
    memset(pairU, NIL, sizeof(pairU));
    memset(pairV, NIL, sizeof(pairV));
    int matching = 0;

    while (bfs()) {
        for (int u = 1; u <= n; u++) {
            if (pairU[u] == NIL && dfs(u)) {
                matching++;
            }
        }
    }
    return matching;
}

int main() {
    // Example: bipartite graph with 3 nodes on each side
    n = 3;
    m = 3;

    // Defining edges
    adj[1][1] = adj[1][2] = 1;
    adj[2][2] = adj[2][3] = 1;
    adj[3][3] = 1;

    int result = hopcroftKarp();
    printf("Maximum Matching: %d\n", result);

    return 0;
}
