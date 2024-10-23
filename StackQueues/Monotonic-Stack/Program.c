#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct {
    int *data; // Array to store stack elements
    int top;   // Index of the top element
    int capacity; // Maximum number of elements in the stack
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is -1
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to add an item to stack
void push(Stack *stack, int item) {
    if (isFull(stack))
        return;
    stack->data[++stack->top] = item;
}

// Function to remove an item from stack
int pop(Stack *stack) {
    if (isEmpty(stack))
        return -1; // Return -1 if stack is empty
    return stack->data[stack->top--];
}

// Function to get the top item from stack
int peek(Stack *stack) {
    if (isEmpty(stack))
        return -1; // Return -1 if stack is empty
    return stack->data[stack->top];
}

// Function to find the next greater element
void nextGreaterElement(int arr[], int n) {
    Stack *stack = createStack(n);
    int result[n];

    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while the current element is greater
        while (!isEmpty(stack) && arr[peek(stack)] < arr[i]) {
            result[pop(stack)] = arr[i];
        }
        push(stack, i);
    }

    // For remaining elements in stack
    while (!isEmpty(stack)) {
        result[pop(stack)] = -1; // -1 indicates no greater element
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        printf("Next greater element for %d is %d\n", arr[i], result[i]);
    }

    free(stack->data);
    free(stack);
}

// Function to find the next smaller element
void nextSmallerElement(int arr[], int n) {
    Stack *stack = createStack(n);
    int result[n];

    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while the current element is smaller
        while (!isEmpty(stack) && arr[peek(stack)] > arr[i]) {
            result[pop(stack)] = arr[i];
        }
        push(stack, i);
    }

    // For remaining elements in stack
    while (!isEmpty(stack)) {
        result[pop(stack)] = -1; // -1 indicates no smaller element
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        printf("Next smaller element for %d is %d\n", arr[i], result[i]);
    }

    free(stack->data);
    free(stack);
}

// Example usage
int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Finding next greater elements:\n");
    nextGreaterElement(arr, n);

    printf("\nFinding next smaller elements:\n");
    nextSmallerElement(arr, n);

    return 0;
}
