#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct Stack {
    int top;
    int capacity;
    int* array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack
void push(Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack
int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

// Queue structure using two stacks
typedef struct Queue {
    Stack* stack1;
    Stack* stack2;
} Queue;

// Function to create a queue using two stacks
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

// Function to add an item to the queue
void enqueue(Queue* queue, int item) {
    push(queue->stack1, item);
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}

// Main function to demonstrate the queue implementation
int main() {
    Queue* queue = createQueue(100);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Dequeued: %d\n", dequeue(queue)); // Outputs 1
    printf("Dequeued: %d\n", dequeue(queue)); // Outputs 2

    enqueue(queue, 4);
    printf("Dequeued: %d\n", dequeue(queue)); // Outputs 3
    printf("Dequeued: %d\n", dequeue(queue)); // Outputs 4

    return 0;
}
