#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct MinStack {
    int *mainStack;
    int top;
    int capacity;
    int minElement;
};

struct MinStack* createStack(int capacity) {
    struct MinStack* stack = (struct MinStack*)malloc(sizeof(struct MinStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->mainStack = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isEmpty(struct MinStack* stack) {
    return stack->top == -1;
}

bool isFull(struct MinStack* stack) {
    return stack->top == stack->capacity - 1;
}

void getMin(struct MinStack* stack) {
    if (isEmpty(stack))
        printf("Stack is empty\n");
    else
        printf("Minimum Element in the stack is: %d\n", stack->minElement);
}

void peek(struct MinStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    int topElement = stack->mainStack[stack->top]; // Top element.
    printf("Top Most Element is: ");
    (topElement < stack->minElement) ? printf("%d\n", stack->minElement) : printf("%d\n", topElement);
}

void pop(struct MinStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Element popped: ");
    int topElement = stack->mainStack[stack->top];
    stack->top--;

    // Minimum will change if the minimum element
    // is being removed.
    if (topElement < stack->minElement) {
        printf("%d\n", stack->minElement);
        stack->minElement = 2 * stack->minElement - topElement;
    } else {
        printf("%d\n", topElement);
    }
}

// Inserts an element into MinStack
void push(struct MinStack* stack, int val) {
    // Insert new number into the stack
    if (isEmpty(stack)) {
        stack->minElement = val;
        stack->mainStack[++stack->top] = val;
        printf("Element Pushed: %d\n", val);
        return;
    }

    // If new number is less than minElement
    else if (val < stack->minElement) {
        stack->mainStack[++stack->top] = 2 * val - stack->minElement;
        stack->minElement = val;
    } else {
        stack->mainStack[++stack->top] = val;
    }

    printf("Element Pushed: %d\n", val);
}

int main() {
    struct MinStack* s = createStack(100);
    push(s, 8);
    push(s, 16);
    getMin(s);
    push(s, 1);
    getMin(s);
    pop(s);
    getMin(s);
    push(s, 5);
    getMin(s);
    pop(s);
    peek(s);

    free(s->mainStack);
    free(s);
    return 0;
}
