#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100 // Maximum size of the stack

// Stack structure
struct Stack {
    int top;
    int items[MAX];
};

// Function to initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to push an element to the stack
void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Function to evaluate the prefix expression
int evaluatePrefix(char *prefix) {
    struct Stack s;
    initStack(&s);
    int i, operand1, operand2;
    int length = strlen(prefix);

    // Scan the prefix expression from right to left
    for (i = length - 1; i >= 0; i--) {
        char ch = prefix[i];

        // If the character is an operand, push it to the stack
        if (isdigit(ch)) {
            push(&s, ch - '0'); // Convert character to integer
        }
        // If the character is an operator, pop two elements and perform the operation
        else {
            operand1 = pop(&s);
            operand2 = pop(&s);

            switch (ch) {
                case '+': push(&s, operand1 + operand2); break;
                case '-': push(&s, operand1 - operand2); break;
                case '*': push(&s, operand1 * operand2); break;
                case '/': push(&s, operand1 / operand2); break;
            }
        }
    }

    // The final result will be in the stack
    return pop(&s);
}

int main() {
    char prefix[MAX];

    // Input prefix expression
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    // Evaluate the prefix expression
    printf("Result of evaluation: %d\n", evaluatePrefix(prefix));

    return 0;
}
