#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *stack)
{
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow, cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow, cannot pop\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

// Function to implement a circular queue using two stacks
typedef struct
{
    Stack stack1;
    Stack stack2;
} CircularQueue;

// Function to initialize the circular queue
void initQueue(CircularQueue *queue)
{
    initStack(&queue->stack1);
    initStack(&queue->stack2);
}

// Function to enqueue an element into the queue
void enqueue(CircularQueue *queue, int value)
{
    push(&queue->stack1, value);
}

// Function to dequeue an element from the queue
int dequeue(CircularQueue *queue)
{
    if (isEmpty(&queue->stack2))
    {
        // Transfer all elements from stack1 to stack2
        while (!isEmpty(&queue->stack1))
        {
            int temp = pop(&queue->stack1);
            push(&queue->stack2, temp);
        }
    }

    if (isEmpty(&queue->stack2))
    {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }

    return pop(&queue->stack2);
}

// Function to display the elements of the queue
void displayQueue(CircularQueue *queue)
{
    if (isEmpty(&queue->stack1) && isEmpty(&queue->stack2))
    {
        printf("Queue is empty\n");
        return;
    }

    // Print elements from stack2 (front of the queue)
    for (int i = queue->stack2.top; i >= 0; i--)
    {
        printf("%d ", queue->stack2.arr[i]);
    }

    // Print elements from stack1 (end of the queue)
    for (int i = 0; i <= queue->stack1.top; i++)
    {
        printf("%d ", queue->stack1.arr[i]);
    }
    printf("\n");
}

int main()
{
    CircularQueue queue;
    initQueue(&queue);

    // Enqueue elements
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    // Display queue
    printf("Queue after enqueuing 10, 20, 30: ");
    displayQueue(&queue);

    // Dequeue an element
    printf("Dequeued element: %d\n", dequeue(&queue));

    // Display queue after dequeue
    printf("Queue after dequeue: ");
    displayQueue(&queue);

    // Enqueue more elements
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    // Display final state of the queue
    printf("Queue after enqueuing 40, 50: ");
    displayQueue(&queue);

    return 0;
}
