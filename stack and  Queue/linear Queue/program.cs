#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int size;
    int* queue;
} LinearQueue;

// Initialize the linear queue
void initQueue(LinearQueue* q, int size) {
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->queue = (int*)malloc(size * sizeof(int));
}

// Free memory allocated for the linear queue
void destroyQueue(LinearQueue* q) {
    free(q->queue);
}

// Check if the queue is empty
int isEmpty(LinearQueue* q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(LinearQueue* q) {
    return q->rear == q->size - 1;
}

// Enqueue an element
void enqueue(LinearQueue* q, int x) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0; // First element being added
        }
        q->rear++;
        q->queue[q->rear] = x;
    }
}

// Dequeue an element
int dequeue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1; // Return -1 or some error code
    } else {
        int x = q->queue[q->front];
        // Move the front pointer
        if (q->front >= q->rear) {
            // Queue is now empty
            q->front = q->rear = -1;
        } else {
            q->front++;
        }
        return x;
    }
}

// Display the queue
void display(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->queue[i]);
        if (i != q->rear) {
            printf(" <- ");
        }
    }
    printf("\n");
}

int main() {
    LinearQueue q;
    initQueue(&q, 5); // Initialize queue of size 5

    // Enqueue elements
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);

    // Dequeue an element
    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    // Enqueue more elements
    enqueue(&q, 4);
    enqueue(&q, 5);
    display(&q);

    // Overflow
    enqueue(&q, 6); // Should display "Queue Overflow"

    // Clean up
    destroyQueue(&q);

    return 0;
}
