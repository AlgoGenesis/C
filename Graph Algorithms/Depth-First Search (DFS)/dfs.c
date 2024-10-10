#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int graph[MAX][MAX], n;

void dfs(int current) {
    visited[current] = 1;
    printf("%d ", current);

    for (int i = 0; i < n; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    // Example graph input
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    dfs(start);
    return 0;
}
