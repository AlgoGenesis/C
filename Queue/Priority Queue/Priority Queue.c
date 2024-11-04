#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of elements in the priority queue

typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

// Function to swap elements in the heap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function for maintaining the min-heap property
void minHeapify(PriorityQueue *pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->data[left] < pq->data[smallest])
        smallest = left;

    if (right < pq->size && pq->data[right] < pq->data[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&pq->data[index], &pq->data[smallest]);
        minHeapify(pq, smallest);
    }
}

// Insert element into the priority queue
void enqueue(PriorityQueue *pq, int value) {
    if (pq->size >= MAX) {
        printf("Priority queue overflow\n");
        return;
    }

    // Insert the new element at the end
    int i = pq->size++;
    pq->data[i] = value;

    // Fix the min-heap property if it's violated
    while (i != 0 && pq->data[(i - 1) / 2] > pq->data[i]) {
        swap(&pq->data[i], &pq->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Remove element with highest priority (smallest element in min-heap)
int dequeue(PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Priority queue underflow\n");
        return -1;
    }
    if (pq->size == 1) {
        return pq->data[--pq->size];
    }

    // Store the minimum value, remove it, and fix the heap
    int root = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    minHeapify(pq, 0);

    return root;
}

// Peek at the highest-priority element
int peek(PriorityQueue *pq) {
    if (pq->size <= 0) {
        printf("Priority queue is empty\n");
        return -1;
    }
    return pq->data[0];
}

// Main function to demonstrate priority queue
int main() {
    PriorityQueue pq;
    pq.size = 0;

    enqueue(&pq, 10);
    enqueue(&pq, 20);
    enqueue(&pq, 5);
    enqueue(&pq, 7);

    printf("Highest priority element: %d\n", peek(&pq));
    printf("Dequeued element: %d\n", dequeue(&pq));
    printf("Highest priority element after dequeue: %d\n", peek(&pq));

    return 0;
}
