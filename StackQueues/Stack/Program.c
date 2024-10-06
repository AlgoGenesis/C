#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 5 // Maximum size of the stack

struct Stack {
    int items[MAX];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack* s) {
    assert(s != NULL);
    s->top = -1; // Stack is empty
}

// Function to check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* s, int value) {
    assert(s != NULL);
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->items[++s->top] = value; // Increment top and add value
    printf("Pushed: %d\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    assert(s != NULL);
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1; // Indicating the stack is empty
    }
    return s->items[s->top--]; // Return value and decrement top
}

// Function to display the stack
void display(struct Stack* s) {
    assert(s != NULL);
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    initializeStack(&s);
    int choice, value;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                value = pop(&s);
                if (value != -1) {
                    printf("Popped: %d\n", value);
                }
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}