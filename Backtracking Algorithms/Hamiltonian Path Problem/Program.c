#include <stdio.h>
#include <stdbool.h>

#define V 5

void printSolution(int path[]);

bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    if (!graph[path[pos - 1]][v]) return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) return false;
    }

    return true;
}

bool hamiltonianUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) return true;

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianUtil(graph, path, pos + 1)) return true;

            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

bool hamiltonianPath(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++) path[i] = -1;

    path[0] = 0;

    if (!hamiltonianUtil(graph, path, 1)) {
        printf("No solution\n");
        return false;
    }

    printSolution(path);
    return true;
}

void printSolution(int path[]) {
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int main() {
    bool graph[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};

    hamiltonianPath(graph);

    return 0;
}
