#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for adjacency list nodes
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to add edges to the adjacency list
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Queue structure for BFS
typedef struct Queue {
    int* arr;
    int front, rear, size;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (int*)malloc(capacity * sizeof(int));
    queue->front = queue->rear = -1;
    queue->size = capacity;
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == queue->size - 1) return;  // Overflow
    if (isEmpty(queue)) queue->front = 0;
    queue->arr[++queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1;
    int value = queue->arr[queue->front++];
    if (queue->front > queue->rear) queue->front = queue->rear = -1;
    return value;
}

// DFS function to check bipartiteness
bool dfsCheck(int node, int col, int color[], Node* adj[]) {
    color[node] = col;

    Node* temp = adj[node];
    while (temp) {
        int neighbor = temp->data;

        if (color[neighbor] == -1) {  // Not yet colored
            if (!dfsCheck(neighbor, !col, color, adj)) {
                return false;
            }
        } else if (color[neighbor] == col) {  // Same color conflict
            return false;
        }
        temp = temp->next;
    }
    return true;
}

// BFS function to check bipartiteness
bool bfsCheck(int start, int V, Node* adj[], int color[]) {
    Queue* q = createQueue(V);
    enqueue(q, start);
    color[start] = 0;

    while (!isEmpty(q)) {
        int node = dequeue(q);
        Node* temp = adj[node];

        while (temp) {
            int neighbor = temp->data;

            if (color[neighbor] == -1) {
                color[neighbor] = !color[node];
                enqueue(q, neighbor);
            } else if (color[neighbor] == color[node]) {
                free(q->arr);
                free(q);
                return false;
            }
            temp = temp->next;
        }
    }
    free(q->arr);
    free(q);
    return true;
}

// Function to check if the graph is bipartite using DFS
bool isBipartiteDFS(int V, Node* adj[]) {
    int* color = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) color[i] = -1;

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!dfsCheck(i, 0, color, adj)) {
                free(color);
                return false;
            }
        }
    }
    free(color);
    return true;
}

// Function to check if the graph is bipartite using BFS
bool isBipartiteBFS(int V, Node* adj[]) {
    int* color = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) color[i] = -1;

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            if (!bfsCheck(i, V, adj, color)) {
                free(color);
                return false;
            }
        }
    }
    free(color);
    return true;
}

int main() {
    int V = 4;
    Node* adj[V];
    for (int i = 0; i < V; i++) adj[i] = NULL;

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    printf("Using BFS: ");
    if (isBipartiteBFS(V, adj))
        printf("1\n");
    else
        printf("0\n");

    printf("Using DFS: ");
    if (isBipartiteDFS(V, adj))
        printf("1\n");
    else
        printf("0\n");

    // Free memory for adjacency lists
    for (int i = 0; i < V; i++) {
        Node* temp = adj[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }

    return 0;
}
