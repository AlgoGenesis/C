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
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (int*)malloc(numVertices * sizeof(int));
    graph->visited = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = 0;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adjLists[src] = dest;
}

// Function to perform BFS traversal
void bfs(Graph* graph, int startVertex) {
    int queue[graph->numVertices];
    int front = 0, rear = 0;
    queue[rear++] = startVertex;
    graph->visited[startVertex] = 1;
    while (front < rear) {
        int temp = queue[front++];
        printf("%d ", temp);
        int neighbor = graph->adjLists[temp];
        while (neighbor != 0) {
            if (graph->visited[neighbor] == 0) {
                queue[rear++] = neighbor;
                graph->visited[neighbor] = 1;
            }
            neighbor = graph->adjLists[neighbor];
        }
    }
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    printf("BFS Traversal: ");
    bfs(graph, 0);
    return 0;
}