#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list nodes
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to add an edge to the graph
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Function to print the graph's adjacency list
void printGraph(Node* adj[], int V) {
    for (int i = 0; i < V; i++) {
        printf("Adjacency list of vertex %d: ", i);
        Node* temp = adj[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to reverse the directed graph
Node** reverseGraph(Node* adj[], int V) {
    // Allocate memory for the reversed graph
    Node** revAdj = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        revAdj[i] = NULL;
    }

    // Traverse each adjacency list and reverse the edges
    for (int i = 0; i < V; i++) {
        Node* temp = adj[i];
        while (temp) {
            addEdge(revAdj, temp->data, i);  // Reverse the edge
            temp = temp->next;
        }
    }
    return revAdj;
}

// Free the memory allocated for the graph
void freeGraph(Node* adj[], int V) {
    for (int i = 0; i < V; i++) {
        Node* temp = adj[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
}

int main() {
    int V = 4;
    Node* adj[V];

    // Initialize adjacency lists
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    printf("Original Graph:\n");
    printGraph(adj, V);

    // Reverse the graph
    Node** revAdj = reverseGraph(adj, V);

    printf("\nReversed Graph:\n");
    printGraph(revAdj, V);

    // Free memory
    freeGraph(adj, V);
    freeGraph(revAdj, V);
    free(revAdj);

    return 0;
}
