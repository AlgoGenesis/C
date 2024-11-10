#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure with top pointer and array for elements
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize a stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Function to check if a stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if a stack is full
int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto a stack
void push(Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

// Function to pop an element from a stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Queue structure using two stacks
typedef struct QueueUsingStacks {
    Stack stack1;
    Stack stack2;
} QueueUsingStacks;

// Function to initialize the queue
void initQueue(QueueUsingStacks *queue) {
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

// Enqueue operation
void enqueue(QueueUsingStacks *queue, int data) {
    push(&queue->stack1, data);
    printf("Enqueued %d\n", data);
}

// Dequeue operation
int dequeue(QueueUsingStacks *queue) {
    // If both stacks are empty, queue is empty
    if (isEmpty(&queue->stack1) && isEmpty(&queue->stack2)) {
        printf("Queue is empty\n");
        return -1;
    }

    // Move elements from stack1 to stack2 if stack2 is empty
    if (isEmpty(&queue->stack2)) {
        while (!isEmpty(&queue->stack1)) {
            push(&queue->stack2, pop(&queue->stack1));
        }
    }

    // Pop from stack2, which is the front of the queue
    int dequeuedValue = pop(&queue->stack2);
    printf("Dequeued %d\n", dequeuedValue);
    return dequeuedValue;
}

int main() {
    QueueUsingStacks queue;
    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);  // Queue is empty at this point

    return 0;
}
