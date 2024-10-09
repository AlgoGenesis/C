
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int disc[MAX], low[MAX], stack[MAX], inStack[MAX], scc[MAX];
int time = 0, top = -1, sccCount = 0;

void tarjanDFS(int u, int graph[MAX][MAX], int V) {
    disc[u] = low[u] = ++time;
    stack[++top] = u;
    inStack[u] = 1;

    for (int v = 0; v < V; v++) {
        if (graph[u][v]) {
            if (disc[v] == -1) {
                tarjanDFS(v, graph, V);
                low[u] = (low[u] < low[v]) ? low[u] : low[v];
            } else if (inStack[v]) {
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }

    if (low[u] == disc[u]) {
        printf("SCC %d: ", ++sccCount);
        int v;
        do {
            v = stack[top--];
            inStack[v] = 0;
            printf("%d ", v);
        } while (u != v);
        printf("\n");
    }
}

void tarjan(int graph[MAX][MAX], int V) {
    for (int i = 0; i < V; i++) {
        disc[i] = -1;
        low[i] = -1;
        inStack[i] = 0;
    }

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            tarjanDFS(i, graph, V);
        }
    }
}

int main() {
    int V = 5;
    int graph[MAX][MAX] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    printf("Strongly Connected Components in the graph:\n");
    tarjan(graph, V);

    return 0;
}
