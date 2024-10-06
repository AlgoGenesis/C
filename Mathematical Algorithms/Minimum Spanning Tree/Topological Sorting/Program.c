#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Stack structure for storing the topological sort order
struct Stack {
    int items[MAX];
    int top;
};

// Function to create a graph node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Stack functions
void push(struct Stack* stack, int value) {
    stack->items[++stack->top] = value;
}

int pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to perform DFS and push the vertex onto the stack
void dfs(struct Graph* graph, int vertex, struct Stack* stack) {
    graph->visited[vertex] = 1;

    struct Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int adjVertex = adjList->vertex;
        if (graph->visited[adjVertex] == 0) {
            dfs(graph, adjVertex, stack);
        }
        adjList = adjList->next;
    }

    push(stack, vertex); // Push vertex onto stack after visiting all its neighbors
}

// Function to perform topological sort
void topologicalSort(struct Graph* graph) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            dfs(graph, i, stack);
        }
    }

    printf("Topological Sort: ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");
}

int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    // Adding edges to the directed graph
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Performing Topological Sort on the graph:\n");
    topologicalSort(graph);

    return 0;
}