#include <stdio.h>
#include <stdlib.h>

#define QUEUE_CAPACITY 5  // Maximum size of the Drop-Out Queue

typedef struct {
    int front, rear, size;
    int capacity;
    int* array;
} DropOutQueue;

// Function to create a Drop-Out Queue
DropOutQueue* createQueue(int capacity) {
    DropOutQueue* queue = (DropOutQueue*)malloc(sizeof(DropOutQueue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This will change when we enqueue
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Check if the queue is full
int isFull(DropOutQueue* queue) {
    return (queue->size == queue->capacity);
}

// Check if the queue is empty
int isEmpty(DropOutQueue* queue) {
    return (queue->size == 0);
}

// Add an item to the queue (with drop-out if full)
void enqueue(DropOutQueue* queue, int item) {
    // If the queue is full, drop the oldest element (move front)
    if (isFull(queue)) {
        queue->front = (queue->front + 1) % queue->capacity;  // Drop the oldest
    } else {
        queue->size++;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;

    printf("Enqueued %d\n", item);
}

// Remove an item from the front of the queue
int dequeue(DropOutQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Function to print the queue
void printQueue(DropOutQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    int index = queue->front;
    printf("Queue: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[index]);
        index = (index + 1) % queue->capacity;
    }
    printf("\n");
}

// Main function to demonstrate Drop-Out Queue
int main() {
    DropOutQueue* queue = createQueue(QUEUE_CAPACITY);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printQueue(queue);

    enqueue(queue, 60);  // This will drop the oldest element (10)
    printQueue(queue);

    enqueue(queue, 70);  // This will drop the next oldest element (20)
    printQueue(queue);

    dequeue(queue);
    printQueue(queue);

    return 0;
}
