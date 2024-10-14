#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int dest;
    struct Node* next;
};

// Define the structure of an adjacency list
struct AdjList {
    struct Node* head;
};

// Create a new node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Add an edge to an undirected graph
void addEdge(struct AdjList adj[], int s, int t) {
    struct Node* newNode = createNode(t);
    newNode->next = adj[s].head;
    adj[s].head = newNode;

    // Since the graph is undirected, add an edge from t to s
    newNode = createNode(s);
    newNode->next = adj[t].head;
    adj[t].head = newNode;
}

// Recursive function to perform DFS
void DFSRec(struct AdjList adj[], int visited[], int s) {

    // Mark the current node as visited
    visited[s] = 1;
    printf("%d ", s);

    // Recur for all the vertices adjacent to this vertex
    struct Node* current = adj[s].head;
    while (current != NULL) {
        int dest = current->dest;
        if (!visited[dest]) {
            DFSRec(adj, visited, dest);
        }
        current = current->next;
    }
}

// DFS traversal of the vertices reachable from v
void DFS(struct AdjList adj[], int V) {
    int visited[6] = {0}; 

    // Call the recursive helper function to print DFS traversal
    for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
            // Call the recursive function only if the vertex is not visited
            DFSRec(adj, visited, i);
        }
    }
}

int main() {

    // Create an adjacency list
    int V = 6;
    struct AdjList adj[V];

    for (int i = 0; i < V; i++) {
        adj[i].head = NULL;
    }

    // Define the number of edges
    int E = 5;
    // Define the edges of the graph starting from vertex 0
    //        Example Graph
    //        0 -- 1 -- 2
    //             |
    //             3 -- 4
    //             |
    //             5

    int edges[][2] = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}};

    // Add edges to the graph
    for (int i = 0; i < E; i++) {
        addEdge(adj, edges[i][0], edges[i][1]);
    }

    printf("DFS of the graph:\n");
    // Perform DFS traversal of the graph
    DFS(adj, V);

    return 0;
}