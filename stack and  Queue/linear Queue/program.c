#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *array;
};

// Function to create a queue of a given size
void create(struct Queue *q, int size) {
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->array = (int *)malloc(size * sizeof(int));
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return q->rear == q->size - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Function to add an element to the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full\n");
    } else {
        if (q->front == -1) {
            q->front = 0; // Initialize front on the first enqueue
        }
        q->rear++;
        q->array[q->rear] = value;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1; // Indicate that the queue is empty
    } else {
        int value = q->array[q->front];
        q->front++;
        return value;
    }
}

// Function to display the queue elements
void display(struct Queue q) {
    if (isEmpty(&q)) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.array[i]);
    }
    printf("\n");
}

// Function to free the allocated memory for the queue
void destroy(struct Queue *q) {
    free(q->array);
}

int main() {
    struct Queue q;
    create(&q, 5); // Create a queue of size 5

    // Enqueue elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // This will print "Queue is Full"

    // Display the queue
    display(q);

    // Dequeue an element
    printf("Dequeued: %d\n", dequeue(&q));
    display(q);

    // Clean up
    destroy(&q);
    return 0;
}
