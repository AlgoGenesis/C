#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// A structure to represent an adjacency list
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'vertices' vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Stack structure for storing topological sort order
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an item to stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

// Pop an item from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

// DFS utility function for topological sort
void topologicalSortUtil(struct Graph* graph, int vertex, struct Stack* stack) {
    graph->visited[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex])
            topologicalSortUtil(graph, adjVertex, stack);
        temp = temp->next;
    }

    // Push current vertex to stack after visiting all its adjacent vertices
    push(stack, vertex);
}

// Function to perform topological sort
void topologicalSort(struct Graph* graph) {
    struct Stack* stack = createStack(graph->numVertices);

    // Call the recursive helper function to store Topological Sort starting from all unvisited vertices
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->visited[i] == 0) {
            topologicalSortUtil(graph, i, stack);
        }
    }

    // Print the contents of the stack (topological sort order)
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");
}

// Main function
int main() {
    // Example graph with 6 vertices (V = 6)
    int V = 6;
    struct Graph* graph = createGraph(V);

    // Adding edges to the graph
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Topological Sort of the given graph:\n");
    topologicalSort(graph);

    return 0;
}
