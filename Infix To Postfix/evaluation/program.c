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

// Function to evaluate the postfix expression
int evaluatePostfix(char *postfix) {
    struct Stack s;
    initStack(&s);
    int i = 0, operand1, operand2;

    while (postfix[i] != '\0') {
        char ch = postfix[i];

        // If the character is an operand, push it to the stack
        if (isdigit(ch)) {
            push(&s, ch - '0'); // Convert character to integer
        }
        // If the character is an operator, pop two elements and perform the operation
        else {
            operand2 = pop(&s);
            operand1 = pop(&s);

            switch (ch) {
                case '+': push(&s, operand1 + operand2); break;
                case '-': push(&s, operand1 - operand2); break;
                case '*': push(&s, operand1 * operand2); break;
                case '/': push(&s, operand1 / operand2); break;
            }
        }
        i++;
    }

    // The final result will be in the stack
    return pop(&s);
}

int main() {
    char postfix[MAX];

    // Input postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Evaluate the postfix expression
    printf("Result of evaluation: %d\n", evaluatePostfix(postfix));

    return 0;
}