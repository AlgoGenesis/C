#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;      // Dynamic array to store elements
    int size;       // Current size of the array
    int capacity;   // Current allocated capacity
} AdjList;

typedef struct {
    AdjList* arr;   // Array of AdjLists representing the graph
    int size;       // Number of nodes in the graph
} Graph;

// Initialize an AdjList with a given capacity
void initAdjList(AdjList* al, int initialCapacity) {
    al->data = (int*)malloc(initialCapacity * sizeof(int));
    al->size = 0;
    al->capacity = initialCapacity;
}

// Adds a value to the AdjList, resizing only if necessary
void pushBack(AdjList* al, int value) {
    if (al->size == al->capacity) {
        al->capacity = al->capacity == 0 ? 2 : al->capacity * 2;
        al->data = (int*)realloc(al->data, al->capacity * sizeof(int));
    }
    al->data[al->size++] = value;
}

// Initialize a graph with a given size (number of nodes)
void initGraph(Graph* g, int size) {
    g->arr = (AdjList*)malloc(size * sizeof(AdjList));
    g->size = size;
    for (int i = 0; i < size; ++i) {
        initAdjList(&g->arr[i], 2);  // Small initial capacity to reduce reallocations
    }
}

// Transpose the graph by reversing edges
Graph solve(Graph* graph) {
    Graph ans;
    initGraph(&ans, graph->size);

    for (int i = 0; i < graph->size; ++i) {
        for (int j = 0; j < graph->arr[i].size; ++j) {
            int x = graph->arr[i].data[j];
            pushBack(&ans.arr[x], i);  // Add node 'i' to the list of node 'x' in the transposed graph
        }
    }
    return ans;
}

// Print the adjacency list of the graph
void printGraph(Graph* g) {
    for (int i = 0; i < g->size; ++i) {
        printf("[ ");
        for (int j = 0; j < g->arr[i].size; ++j) {
            printf("%d ", g->arr[i].data[j]);
        }
        printf("]\n");
    }
}

int main() {
    Graph graph;
    initGraph(&graph, 5);

    // Building the adjacency list for the input graph
    pushBack(&graph.arr[0], 1);
    pushBack(&graph.arr[0], 2);
    pushBack(&graph.arr[1], 4);
    pushBack(&graph.arr[2], 4);
    pushBack(&graph.arr[3], 1);
    pushBack(&graph.arr[3], 2);
    pushBack(&graph.arr[4], 3);

    Graph result = solve(&graph);
    printGraph(&result);
    return 0;
}
