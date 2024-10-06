#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 5 // Maximum size of the circular queue

struct CircularQueue {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the circular queue
void initializeQueue(struct CircularQueue* q) {
    assert(q != NULL);
    q->front = -1;
    q->rear = -1; // Queue is empty
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* q) {
    return (q->front == (q->rear + 1) % MAX);
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

// Function to enqueue an element
void enqueue(struct CircularQueue* q, int value) {
    assert(q != NULL);
    if (isFull(q)) {
        printf("Circular Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Set front to 0 if the queue was empty
    }
    q->rear = (q->rear + 1) % MAX; // Circular increment
    q->items[q->rear] = value; // Add the value
    printf("Inserted: %d\n", value);
}

// Function to dequeue an element
int dequeue(struct CircularQueue* q) {
    assert(q != NULL);
    if (isEmpty(q)) {
        printf("Circular Queue is empty!\n");
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

// Function to display the circular queue
void display(struct CircularQueue* q) {
    assert(q != NULL);
    if (isEmpty(q)) {
        printf("Circular Queue is empty!\n");
        return;
    }
    printf("Circular Queue elements: ");
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
    struct CircularQueue q;
    initializeQueue(&q);
    int choice, value;

    do {
        printf("\nCircular Queue Menu:\n");
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