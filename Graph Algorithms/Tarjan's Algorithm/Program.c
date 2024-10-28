#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

// Graph structure using adjacency list
struct Graph {
    int V;                   // Number of vertices
    int adj[MAX][MAX];        // Adjacency matrix representation of the graph
};

// Stack structure to help with the DFS
struct Stack {
    int top;
    int items[MAX];
};

// Function prototypes
void tarjanSCC(struct Graph *graph);
void SCCUtil(struct Graph *graph, int u, int disc[], int low[], int stackMember[], struct Stack *stack);
void push(struct Stack *stack, int u);
int pop(struct Stack *stack);
int isEmpty(struct Stack *stack);

// Function to create a new graph
struct Graph* createGraph(int V);

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int v, int w);

// Main function
int main() {
    int V = 5;  // Example with 5 vertices

    // Create a graph
    struct Graph *graph = createGraph(V);

    // Add edges
    addEdge(graph, 1, 0);
    addEdge(graph, 0, 2);
    addEdge(graph, 2, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 4);

    // Find and print all SCCs
    printf("Strongly Connected Components are:\n");
    tarjanSCC(graph);

    return 0;
}

// Function to create a new graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));
    graph->V = V;

    // Initialize adjacency matrix to 0 (no edges)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge from vertex v to vertex w
void addEdge(struct Graph *graph, int v, int w) {
    graph->adj[v][w] = 1;  // Mark the edge in the adjacency matrix
}

// Tarjan's Algorithm to find all Strongly Connected Components (SCCs)
void tarjanSCC(struct Graph *graph) {
    int V = graph->V;
    
    // Arrays to store discovery times of visited vertices
    int disc[V];
    
    // Array to store the lowest discovery time reachable from the subtree rooted with the vertex
    int low[V];
    
    // Boolean array to check whether a vertex is in the stack
    int stackMember[V];
    
    // Stack to store vertices while processing DFS
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->top = -1;

    // Initialize all arrays with initial values
    for (int i = 0; i < V; i++) {
        disc[i] = -1;  // -1 means the vertex is not yet visited
        low[i] = -1;
        stackMember[i] = 0;  // Initially no vertex is part of the stack
    }

    // Call the recursive helper function for each vertex
    for (int i = 0; i < V; i++) {
        if (disc[i] == -1)  // Only call if the vertex hasn't been visited
            SCCUtil(graph, i, disc, low, stackMember, stack);
    }
}

// Utility function to perform the DFS traversal
void SCCUtil(struct Graph *graph, int u, int disc[], int low[], int stackMember[], struct Stack *stack) {
    static int time = 0;  // Static variable to keep track of discovery time
    disc[u] = low[u] = ++time;  // Initialize discovery and low time for the current vertex
    push(stack, u);  // Push the current vertex to the stack
    stackMember[u] = 1;  // Mark the vertex as part of the stack

    // Explore all vertices adjacent to the current vertex u
    for (int v = 0; v < graph->V; v++) {
        if (graph->adj[u][v]) {  // If there's an edge from u to v
            if (disc[v] == -1) {  // If vertex v has not been visited yet
                SCCUtil(graph, v, disc, low, stackMember, stack);  // Recur for v

                // Update the low value of u based on the subtree rooted at v
                low[u] = (low[u] < low[v]) ? low[u] : low[v];
            } else if (stackMember[v]) {
                // If v is already on the stack, update low[u] if necessary
                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }

    // If u is a root node, pop the stack and print the SCC
    if (low[u] == disc[u]) {
        int w = 0;  // To store stack extracted vertices
        while (stack->items[stack->top] != u) {
            w = pop(stack);
            printf("%d ", w);
            stackMember[w] = 0;  // Mark vertex as not in the stack
        }
        w = pop(stack);  // Pop the root vertex itself
        printf("%d\n", w);
        stackMember[w] = 0;
    }
}

// Function to push a vertex to the stack
void push(struct Stack *stack, int u) {
    stack->items[++stack->top] = u;
}

// Function to pop a vertex from the stack
int pop(struct Stack *stack) {
    return stack->items[stack->top--];
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}
