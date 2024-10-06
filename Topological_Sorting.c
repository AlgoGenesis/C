#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** head;
    int* in_degree;
} Graph;

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->head = (Node**)malloc(numVertices * sizeof(Node*));
    graph->in_degree = (int*)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++) {
        graph->head[i] = NULL;
        graph->in_degree[i] = 0;
    }

    return graph;
}

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
    graph->in_degree[dest]++;
}

int* findOrder(int n, int prerequisites[][2], int prerequisitesSize, int* returnSize) {
    Graph* graph = createGraph(n);

    for (int i = 0; i < prerequisitesSize; i++) {
        addEdge(graph, prerequisites[i][0], prerequisites[i][1]);
    }

    int* result = (int*)malloc(n * sizeof(int));
    int index = 0;
    int* stack = (int*)malloc(n * sizeof(int));
    int stackIndex = 0;

    for (int i = 0; i < n; i++) {
        if (graph->in_degree[i] == 0) {
            stack[stackIndex++] = i;
        }
    }

    while (stackIndex > 0) {
        int node = stack[--stackIndex];
        result[index++] = node;

        Node* temp = graph->head[node];
        while (temp != NULL) {
            graph->in_degree[temp->dest]--;
            if (graph->in_degree[temp->dest] == 0) {
                stack[stackIndex++] = temp->dest;
            }
            temp = temp->next;
        }
    }

    if (index != n) {
        *returnSize = 0;
        free(result);
        return NULL;
    }

    *returnSize = n;
    return result;
}

void main() {
    int n = 6;
    int prerequisites[][2] = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    int returnSize;
    int* order = findOrder(n, prerequisites, 6, &returnSize);

    if (order != NULL) {
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");
    }
}
