#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define N 4 // Number of workers/jobs

// Node structure
typedef struct Node {
    struct Node* parent; // Pointer to the parent node
    int pathCost; // Cost of the path to this node
    int cost; // Lower bound cost
    int workerID; // Current worker
    int jobID; // Job assigned
    int assigned[N]; // Track assigned jobs
} Node;

// Function to create a new node
Node* createNode(int wID, int jID, int assignedJobs[], Node* parentNode, int costMatrix[N][N]) {
    Node* node = (Node*)malloc(sizeof(Node)); // Allocate memory for a new node
    node->workerID = wID;
    node->jobID = jID;
    node->parent = parentNode;
    node->pathCost = (parentNode ? parentNode->pathCost : 0);
    memcpy(node->assigned, assignedJobs, sizeof(node->assigned)); // Copy assigned jobs
    if (parentNode) {
        node->pathCost += costMatrix[wID][jID]; // Add cost of current job
        node->assigned[jID] = 1; // Mark job as assigned
    }
    return node;
}

// Function to calculate minimum cost for remaining unassigned jobs
int calculateCost(int costMatrix[N][N], int workerID, int assigned[]) {
    int cost = 0;
    for (int i = workerID + 1; i < N; i++) {
        int minCost = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (!assigned[j] && costMatrix[i][j] < minCost) {
                minCost = costMatrix[i][j]; // Find minimum cost for unassigned jobs
            }
        }
        if (minCost != INT_MAX) {
            cost += minCost; // Accumulate minimum cost
        }
    }
    return cost;
}

// Comparison function for priority queue (min-heap)
int compare(const void* a, const void* b) {
    Node* lhs = *(Node**)a;
    Node* rhs = *(Node**)b;
    return (lhs->cost > rhs->cost) ? 1 : -1; // Return comparison result
}

// Function to print assignments
void printAssignments(Node* node) {
    if (!node) return;
    printAssignments(node->parent); // Recursively print parent assignments
    printf("Assign Worker %c to Job %d\n", node->workerID + 'A', node->jobID);
}

// Function to find minimum cost using Branch and Bound
int findMinCost(int costMatrix[N][N]) {
    Node* pq[100]; // Priority queue for nodes
    int front = -1, rear = -1; // Queue pointers
    int assigned[N] = {0}; // Track assigned jobs

    // Create root node and push to the queue
    Node* root = createNode(-1, -1, assigned, NULL, costMatrix);
    root->cost = 0; // Initialize cost
    pq[++rear] = root; // Push root node to queue

    while (front != rear) {
        Node* minNode = pq[++front]; // Get the node with the least cost

        int workerID = minNode->workerID + 1; // Next worker

        // If all workers are assigned
        if (workerID == N) {
            printAssignments(minNode); // Print the assignments
            return minNode->pathCost; // Return total cost
        }

        // Explore unassigned jobs for the current worker
        for (int jobID = 0; jobID < N; jobID++) {
            if (!minNode->assigned[jobID]) {
                Node* childNode = createNode(workerID, jobID, minNode->assigned, minNode, costMatrix); // Create child node
                childNode->cost = childNode->pathCost + calculateCost(costMatrix, workerID, childNode->assigned); // Calculate cost

                // Add child node to the priority queue
                pq[++rear] = childNode;
                // Sort the priority queue
                qsort(pq, rear + 1, sizeof(Node*), compare);
            }
        }
    }
    return -1; // In case no assignment is possible
}

// Main function
int main() {
    int costMatrix[N][N]; // Cost matrix

    // User input for cost matrix
    printf("Enter the cost matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Cost of Worker %d for Job %d: ", i + 1, j + 1);
            scanf("%d", &costMatrix[i][j]); // Input cost
        }
    }

    // Find and print the optimal cost
    printf("\nOptimal Cost is %d\n", findMinCost(costMatrix));

    return 0;
}

