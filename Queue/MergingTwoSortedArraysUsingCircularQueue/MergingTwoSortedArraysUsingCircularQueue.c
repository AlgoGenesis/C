#include <stdio.h>
#include <stdbool.h>

#define SIZE 100 // Adjust this size as needed

typedef struct
{
    int arr[SIZE];
    int front;
    int rear;
    int capacity;
} CircularQueue;

// Function to initialize the queue
void initializeQueue(CircularQueue *queue, int capacity)
{
    queue->front = -1;
    queue->rear = -1;
    queue->capacity = capacity;
}

// Function to check if the queue is full
bool isFull(CircularQueue *queue)
{
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

// Function to check if the queue is empty
bool isEmpty(CircularQueue *queue)
{
    return (queue->front == -1);
}

// Function to enqueue an element into the queue
void enqueue(CircularQueue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = value;
}

// Function to dequeue an element from the queue
int dequeue(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->arr[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = -1; // Queue is now empty
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return value;
}

// Function to display the queue
void displayQueue(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    int i = queue->front;
    printf("Queue elements are: ");
    while (i != queue->rear)
    {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->capacity;
    }
    printf("%d\n", queue->arr[queue->rear]);
}

// Function to merge two sorted arrays using the circular queue
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, CircularQueue *queue)
{
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            enqueue(queue, arr1[i++]);
        }
        else
        {
            enqueue(queue, arr2[j++]);
        }
    }
    // Enqueue any remaining elements from arr1
    while (i < size1)
    {
        enqueue(queue, arr1[i++]);
    }
    // Enqueue any remaining elements from arr2
    while (j < size2)
    {
        enqueue(queue, arr2[j++]);
    }
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    CircularQueue queue;
    initializeQueue(&queue, size1 + size2);

    mergeSortedArrays(arr1, size1, arr2, size2, &queue);

    displayQueue(&queue);

    return 0;
}
