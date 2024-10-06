# Breadth-First Search (BFS)

## Description

Breadth-First Search (BFS) is an algorithm for traversing or searching tree or graph data structures. It explores all the neighbor nodes at the present depth prior to moving on to nodes at the next depth level. BFS is particularly useful for finding the shortest path in unweighted graphs.

### Problem Definition

Given:
- A graph represented as an adjacency list or matrix.
- A starting vertex (node).

Objective:
- Traverse the graph in breadth-first order, visiting all vertices reachable from the starting vertex.

### Algorithm Overview

1. **Initialization**: Create a queue to hold nodes to visit and an array to track visited nodes.
2. **Enqueue the Start Node**: Add the starting node to the queue and mark it as visited.
3. **Dequeue and Visit Nodes**:
   - While the queue is not empty:
     - Dequeue a node and process it (e.g., print it).
     - Enqueue all unvisited neighbors of the dequeued node, marking them as visited.
4. **Continue** until all reachable nodes have been visited.

### Time Complexity

The time complexity of BFS is `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges in the graph. This is because each vertex and edge is processed once.

## Example Code in C

Here’s a simple implementation of the BFS algorithm in C using an adjacency list representation of the graph:

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent an adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    Node* adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int numVertices;
} Graph;

// Function to create a new adjacency list node
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Mark all vertices as unvisited
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to perform BFS on the graph
void bfs(Graph* graph, int startVertex) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the starting node as visited and enqueue it
    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        // Dequeue a vertex from queue and print it
        int currentVertex = queue[front++];
        printf("Visited %d\n", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            // If an adjacent vertex has not been visited, mark it visited and enqueue it
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    Graph* graph = createGraph(5); // Create a graph with 5 vertices
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Breadth-First Search starting from vertex 0:\n");
    bfs(graph, 0); // Perform BFS starting from vertex 0

    return 0;
}
