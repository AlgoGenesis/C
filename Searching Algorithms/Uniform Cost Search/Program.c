#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 7 // Number of nodes

// Node for adjacency list
typedef struct AdjListNode {
    int dest;
    int cost;
    struct AdjListNode* next;
} AdjListNode;

// Graph - array of adjacency lists
typedef struct Graph {
    AdjListNode* head[N];
} Graph;

// Priority queue node
typedef struct {
    int cost;
    int node;
} PriorityQueueNode;

// Priority queue functions
typedef struct {
    PriorityQueueNode* data;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->data = (PriorityQueueNode*)malloc(capacity * sizeof(PriorityQueueNode));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(PriorityQueueNode* a, PriorityQueueNode* b) {
    PriorityQueueNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(PriorityQueue* pq, int cost, int node) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->data = (PriorityQueueNode*)realloc(pq->data, pq->capacity * sizeof(PriorityQueueNode));
    }
    pq->data[pq->size].cost = cost;
    pq->data[pq->size].node = node;
    int i = pq->size;
    pq->size++;
    while (i > 0 && pq->data[i].cost < pq->data[(i - 1) / 2].cost) {
        swap(&pq->data[i], &pq->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

PriorityQueueNode pop(PriorityQueue* pq) {
    PriorityQueueNode result = pq->data[0];
    pq->size--;
    pq->data[0] = pq->data[pq->size];
    int i = 0;
    while (2 * i + 1 < pq->size) {
        int j = 2 * i + 1;
        if (j + 1 < pq->size && pq->data[j + 1].cost < pq->data[j].cost) {
            j++;
        }
        if (pq->data[i].cost <= pq->data[j].cost) {
            break;
        }
        swap(&pq->data[i], &pq->data[j]);
        i = j;
    }
    return result;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

// Function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest, int cost) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->cost = cost;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }
    return graph;
}

// Add edge to the graph
void addEdge(Graph* graph, int src, int dest, int cost) {
    AdjListNode* newNode = newAdjListNode(dest, cost);
    newNode->next = graph->head[src];
    graph->head[src] = newNode;
}

// UCS function
int* uniform_cost_search(Graph* graph, int* goal, int goalSize, int start) {
    int* answer = (int*)malloc(sizeof(int) * goalSize);
    for (int i = 0; i < goalSize; i++) {
        answer[i] = INT_MAX;
    }

    PriorityQueue* pq = createPriorityQueue(100);
    push(pq, 0, start);
    
    int visited[N] = {0};
    int count = 0;

    while (!isEmpty(pq)) {
        PriorityQueueNode p = pop(pq);
        int node = p.node;
        int currentCost = p.cost;

        if (visited[node]) continue;
        visited[node] = 1;

        // Check if the node is one of the goal nodes
        for (int i = 0; i < goalSize; i++) {
            if (node == goal[i]) {
                if (answer[i] == INT_MAX) {
                    count++;
                }
                if (answer[i] > currentCost) {
                    answer[i] = currentCost;
                }
                if (count == goalSize) {
                    return answer;
                }
            }
        }

        // Process adjacent nodes
        AdjListNode* temp = graph->head[node];
        while (temp) {
            if (!visited[temp->dest]) {
                push(pq, currentCost + temp->cost, temp->dest);
            }
            temp = temp->next;
        }
    }

    return answer;
}

// Main function
int main() {
    // Create the graph
    Graph* graph = createGraph();

    // Add edges and costs
    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 3, 1, 5);
    addEdge(graph, 3, 6, 6);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 1, 6, 1);
    addEdge(graph, 4, 2, 4);
    addEdge(graph, 4, 5, 3);
    addEdge(graph, 2, 1, 4);
    addEdge(graph, 5, 2, 6);
    addEdge(graph, 5, 6, 3);
    addEdge(graph, 6, 4, 7);

    // Goal state(s)
    int goal[] = {6}; // Multiple goals can be added here

    // Perform UCS
    int* answer = uniform_cost_search(graph, goal, 1, 0);

    // Output the result
    printf("Minimum cost from 0 to 6 is = %d\n", answer[0]);

    // Free allocated memory
    free(answer);
    free(graph);

    return 0;
}
