#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack implementation for iterative DFS
struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Function to perform DFS using recursion
void dfs_recursive(int graph[MAX][MAX], int start, int visited[], int n) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs_recursive(graph, i, visited, n);
        }
    }
}

// Function to perform DFS using iteration
void dfs_iterative(int graph[MAX][MAX], int start, int n) {
    int visited[MAX] = {0};
    struct Stack s;
    initStack(&s);

    push(&s, start);

    while (!isEmpty(&s)) {
        int node = pop(&s);

        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
        }

        for (int i = n - 1; i >= 0; i--) { // Reverse order for correct DFS sequence
            if (graph[node][i] == 1 && !visited[i]) {
                push(&s, i);
            }
        }
    }
}

int main() {
    int n, e;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int graph[MAX][MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("DFS Recursive: ");
    dfs_recursive(graph, start, visited, n);

    printf("\nDFS Iterative: ");
    dfs_iterative(graph, start, n);

    return 0;
}
