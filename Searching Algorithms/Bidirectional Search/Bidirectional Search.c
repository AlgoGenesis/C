#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of nodes

// Function to initialize a graph with no edges
void initializeGraph(int graph[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
}

// Add edge between nodes u and v (undirected graph)
void addEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Check if a queue is empty
bool isEmpty(int *queue, int *front) {
    return (*front == -1);
}

// Enqueue an element in the queue
void enqueue(int *queue, int *front, int *rear, int value) {
    if (*front == -1) {
        *front = *rear = 0;
        queue[*rear] = value;
    } else {
        (*rear)++;
        queue[*rear] = value;
    }
}

// Dequeue an element from the queue
int dequeue(int *queue, int *front, int *rear) {
    int value = queue[*front];
    if (*front == *rear)
        *front = *rear = -1;
    else
        (*front)++;
    return value;
}

// Check if there is an intersection between two sets of visited nodes
int isIntersecting(bool visited_from_src[], bool visited_from_dest[], int n) {
    for (int i = 0; i < n; i++) {
        if (visited_from_src[i] && visited_from_dest[i])
            return i;
    }
    return -1;
}

// Print the path from the source to the target
void printPath(int *parent_src, int *parent_dest, int intersect_node, int src, int dest) {
    int path[MAX];
    int path_len = 0;

    // Trace the path from source to intersection
    int node = intersect_node;
    while (node != -1) {
        path[path_len++] = node;
        node = parent_src[node];
    }
    
    // Print the path from source to intersection
    for (int i = path_len - 1; i >= 0; i--)
        printf("%d ", path[i]);

    // Trace the path from intersection to destination
    node = parent_dest[intersect_node];
    while (node != -1) {
        printf("%d ", node);
        node = parent_dest[node];
    }
    printf("\n");
}

// Bidirectional search function
void bidirectionalSearch(int graph[MAX][MAX], int src, int dest, int n) {
    // Queues for BFS from source and destination
    int queue_src[MAX], front_src = -1, rear_src = -1;
    int queue_dest[MAX], front_dest = -1, rear_dest = -1;

    // Visited arrays for both searches
    bool visited_from_src[MAX] = {false};
    bool visited_from_dest[MAX] = {false};

    // Parent arrays to store the path
    int parent_src[MAX], parent_dest[MAX];
    for (int i = 0; i < n; i++) {
        parent_src[i] = -1;
        parent_dest[i] = -1;
    }

    // Initialize by marking the source and destination as visited
    visited_from_src[src] = true;
    visited_from_dest[dest] = true;

    // Enqueue the source and destination nodes
    enqueue(queue_src, &front_src, &rear_src, src);
    enqueue(queue_dest, &front_dest, &rear_dest, dest);

    while (!isEmpty(queue_src, &front_src) && !isEmpty(queue_dest, &front_dest)) {
        // Expand from source side
        int current_src = dequeue(queue_src, &front_src, &rear_src);
        for (int i = 0; i < n; i++) {
            if (graph[current_src][i] && !visited_from_src[i]) {
                visited_from_src[i] = true;
                parent_src[i] = current_src;
                enqueue(queue_src, &front_src, &rear_src, i);

                if (visited_from_dest[i]) {
                    printf("Path found: ");
                    printPath(parent_src, parent_dest, i, src, dest);
                    return;
                }
            }
        }

        // Expand from destination side
        int current_dest = dequeue(queue_dest, &front_dest, &rear_dest);
        for (int i = 0; i < n; i++) {
            if (graph[current_dest][i] && !visited_from_dest[i]) {
                visited_from_dest[i] = true;
                parent_dest[i] = current_dest;
                enqueue(queue_dest, &front_dest, &rear_dest, i);

                if (visited_from_src[i]) {
                    printf("Path found: ");
                    printPath(parent_src, parent_dest, i, src, dest);
                    return;
                }
            }
        }
    }

    printf("No path found between %d and %d\n", src, dest);
}

// Main function
int main() {
    int n = 6; // Number of nodes in the graph
    int graph[MAX][MAX];

    // Initialize the graph
    initializeGraph(graph, n);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    int src = 0, dest = 5;
    printf("Finding shortest path between %d and %d:\n", src, dest);
    bidirectionalSearch(graph, src, dest, n);

    return 0;
}
