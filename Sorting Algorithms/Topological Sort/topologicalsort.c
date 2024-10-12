#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    int *adjLists;
    int *visited;
} Graph;

// Function to create a graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (int*) calloc(numVertices, sizeof(int));
    graph->visited = (int*) calloc(numVertices, sizeof(int));
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjLists[src] = dest;
}

// Function to perform topological sort using DFS
void topologicalSortUtil(Graph* graph, int vertex, int* sortedOrder) {
    graph->visited[vertex] = 1;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjLists[vertex] == i && !graph->visited[i]) {
            topologicalSortUtil(graph, i, sortedOrder);
        }
    }
    sortedOrder[graph->numVertices - 1] = vertex;
    graph->numVertices--;
}

// Function to perform topological sort
void topologicalSort(Graph* graph) {
    int* sortedOrder = (int*) calloc(graph->numVertices, sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            topologicalSortUtil(graph, i, sortedOrder);
        }
    }
    printf("Topological Sort Order: ");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d ", sortedOrder[i]);
    }
    printf("\n");
    free(sortedOrder);
}

int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    topologicalSort(graph);
    return 0;
}