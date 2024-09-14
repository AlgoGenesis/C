#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define INFINITY 999999

typedef struct Node {
    int id;
    int heuristic; // Estimated cost to goal
    struct Node* next;
} Node;

typedef struct {
    Node* nodes[MAX_NODES];
    int size;
} PriorityQueue;

typedef struct Graph {
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
    int heuristic[MAX_NODES];
} Graph;

// Function to create a new node
Node* createNode(int id, int heuristic) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->heuristic = heuristic;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the priority queue
void initQueue(PriorityQueue* queue) {
    queue->size = 0;
}

// Function to enqueue a node based on heuristic value
void enqueue(PriorityQueue* queue, int id, int heuristic) {
    Node* newNode = createNode(id, heuristic);
    int i;
    for (i = 0; i < queue->size; i++) {
        if (queue->nodes[i]->heuristic > heuristic) {
            break;
        }
    }
    for (int j = queue->size; j > i; j--) {
        queue->nodes[j] = queue->nodes[j - 1];
    }
    queue->nodes[i] = newNode;
    queue->size++;
}

// Function to dequeue the node with the lowest heuristic value
Node* dequeue(PriorityQueue* queue) {
    if (queue->size == 0) return NULL;
    Node* node = queue->nodes[0];
    for (int i = 1; i < queue->size; i++) {
        queue->nodes[i - 1] = queue->nodes[i];
    }
    queue->size--;
    return node;
}

// Function to perform Best-First Search
void bestFirstSearch(Graph* graph, int start, int goal) {
    PriorityQueue queue;
    initQueue(&queue);
    int visited[MAX_NODES] = {0};

    enqueue(&queue, start, graph->heuristic[start]);

    while (queue.size > 0) {
        Node* currentNode = dequeue(&queue);
        int currentId = currentNode->id;

        // If we reached the goal
        if (currentId == goal) {
            printf("Goal node %d found!\n", goal);
            return;
        }

        if (!visited[currentId]) {
            visited[currentId] = 1; // Mark as visited
            printf("Visiting node %d\n", currentId);

            // Explore neighbors
            for (int i = 0; i < graph->numNodes; i++) {
                if (graph->adjacencyMatrix[currentId][i] == 1 && !visited[i]) {
                    enqueue(&queue, i, graph->heuristic[i]);
                }
            }
        }
    }
    printf("Goal node %d not found.\n", goal);
}

int main() {
    Graph graph = {
        .numNodes = 5,
        .adjacencyMatrix = {
            {0, 1, 1, 0, 0},
            {1, 0, 0, 1, 1},
            {1, 0, 0, 0, 1},
            {0, 1, 0, 0, 1},
            {0, 1, 1, 1, 0}
        },
        .heuristic = {7, 6, 2, 1, 0} // Example heuristic values
    };

    int start = 0; // Starting node
    int goal = 4;  // Goal node

    bestFirstSearch(&graph, start, goal); // Perform Best-First Search

    return 0;
}
