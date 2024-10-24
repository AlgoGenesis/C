# Monotonic Stack Algorithm

## Problem Statement

The Monotonic Stack is a data structure designed to maintain elements in a sorted order, which can either be increasing or decreasing. It is particularly effective for solving problems that involve ranges, such as:

- Finding the **next greater element** for each element in an array.
- Finding the **next smaller element** for each element in an array.

These operations can be accomplished efficiently in linear time, O(n), making the Monotonic Stack a valuable tool in algorithm design.

## Algorithm Approach

1. **Initialization**: Create an empty stack to hold indices of the array elements.
2. **Iterate through the array**: For each element:
   - While the stack is not empty and the current element is greater (for next greater) or smaller (for next smaller) than the element at the index stored at the top of the stack:
     - Pop the index from the stack and assign the current element as the next greater or smaller element for the popped index.
   - Push the current index onto the stack.
3. **Handle remaining elements**: After processing all elements, any indices left in the stack indicate that there is no next greater or smaller element, so assign a value (commonly -1) for those indices.
4. **Output the results**: Print or return the next greater and smaller elements.

## Time Complexity

- **Time Complexity**: O(n) for both finding the next greater and next smaller elements, as each element is pushed and popped from the stack at most once.
- **Space Complexity**: O(n) due to the additional space used by the stack and result arrays.

## Code Overview

The following code implements the Monotonic Stack to find the next greater and next smaller elements in an array:

```c
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

// Stack operations: isFull, isEmpty, push, pop, peek...

// Function to find the next greater element
void nextGreaterElement(int arr[], int n) {
    Stack *stack = createStack(n);
    int result[n];

    for (int i = 0; i < n; i++) {
        while (!isEmpty(stack) && arr[peek(stack)] < arr[i]) {
            result[pop(stack)] = arr[i];
        }
        push(stack, i);
    }

    while (!isEmpty(stack)) {
        result[pop(stack)] = -1; // -1 indicates no greater element
    }

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
        while (!isEmpty(stack) && arr[peek(stack)] > arr[i]) {
            result[pop(stack)] = arr[i];
        }
        push(stack, i);
    }

    while (!isEmpty(stack)) {
        result[pop(stack)] = -1; // -1 indicates no smaller element
    }

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
