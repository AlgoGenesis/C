// Queue: Key Concepts
// Definition:

// A queue is a linear data structure that follows the First In First Out (FIFO) principle, meaning the first element added is the first to be removed.

// Implementation:

// Can be implemented using arrays or linked lists.
// Array-based queues have a fixed size, while linked-list queues can grow dynamically.
// Types of Queues:

// Simple Queue: Basic FIFO queue.
// Circular Queue: Connects the end of the queue back to the front, allowing efficient use of space.
// Priority Queue: Elements are dequeued based on priority rather than order of arrival.
// Double-Ended Queue (Deque): Allows insertion and deletion from both ends.
// Applications:

// Task scheduling (in operating systems).
// Managing requests in web servers (queue of requests).
// Breadth-first search (BFS) in graph algorithms.
// Print job management (spooling).
// Advantages:

// Efficient for managing and processing tasks in order.
// Suitable for handling data in a sequential manner.
// Disadvantages:

// Limited size in array-based implementations (risk of overflow).
// Requires extra memory for pointers in linked-list implementations.
// Inefficient access to elements in the middle of the queue.
// Complexity:

// Time Complexity:
// Enqueue: O(1)
// Dequeue: O(1)
// Front: O(1)
// Space Complexity: O(n) for n elements in the queue.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 5 // Maximum size of the queue

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* q) {
    assert(q != NULL);
    q->front = -1;
    q->rear = -1; // Queue is empty
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(struct Queue* q, int value) {
    assert(q != NULL);
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Set front to 0 if the queue was empty
    }
    q->rear = (q->rear + 1) % MAX; // Circular increment
    q->items[q->rear] = value; // Add the value
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    assert(q != NULL);
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1; // Indicating the queue is empty
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1; // Queue is now empty
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX; // Circular increment
    }
    return value; // Return dequeued value
}

// Function to display the queue
void display(struct Queue* q) {
    assert(q != NULL);
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % MAX; // Circular increment
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initializeQueue(&q);
    int choice, value;

    do {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
