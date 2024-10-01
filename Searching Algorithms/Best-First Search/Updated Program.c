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
    Node* front;
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
    queue->front = NULL;
    queue->size = 0;
}

// Function to enqueue a node based on heuristic value (sorted insert)
void enqueue(PriorityQueue* queue, int id, int heuristic) {
    Node* newNode = createNode(id, heuristic);

    if (queue->size >= MAX_NODES) {
        printf("Queue overflow, cannot enqueue node %d\n", id);
        free(newNode); // Prevent memory leak if queue is full
        return;
    }

    if (queue->front == NULL || queue->front->heuristic > heuristic) {
        newNode->next = queue->front;
        queue->front = newNode;
    } else {
        Node* current = queue->front;
        while (current->next != NULL && current->next->heuristic <= heuristic) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    queue->size++;
}

// Function to dequeue the node with the lowest heuristic value
Node* dequeue(PriorityQueue* queue) {
    if (queue->size == 0) return NULL;

    Node* node = queue->front;
    queue->front = queue->front->next;
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
            free(currentNode);  // Free the current node to prevent memory leak
            break;
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

        // Free the memory of the processed node
        free(currentNode);
    }

    // Cleanup remaining nodes in the queue
    while (queue.size > 0) {
        Node* remainingNode = dequeue(&queue);
        free(remainingNode); // Free remaining nodes to prevent memory leak
    }
    printf("Search completed.\n");
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
