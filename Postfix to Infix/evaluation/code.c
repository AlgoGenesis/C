#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100 // Maximum size of the stack

// Stack structure for integer values
struct Stack {
    int top;
    int items[MAX];
};

// Function to initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to push an integer onto the stack
void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Function to pop an integer from the stack
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
    int i = 0;

    while (postfix[i] != '\0') {
        char ch = postfix[i];

        // If the character is an operand (digit), push it to the stack
        if (isdigit(ch)) {
            push(&s, ch - '0'); // Convert character to integer and push
        }
        // If the character is an operator, pop two elements and apply the operation
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand2 = pop(&s);
            int operand1 = pop(&s);

            // Perform the operation and push the result back to the stack
            switch (ch) {
                case '+': push(&s, operand1 + operand2); break;
                case '-': push(&s, operand1 - operand2); break;
                case '*': push(&s, operand1 * operand2); break;
                case '/': 
                    if (operand2 != 0) {
                        push(&s, operand1 / operand2);
                    } else {
                        printf("Division by zero error!\n");
                        return -1; // Return an error code
                    }
                    break;
            }
        }
        i++;
    }

    // The final result is the only element left in the stack
    return pop(&s);
}

int main() {
    char postfix[MAX];

    // Input postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    if (result != -1) {
        printf("Result of evaluation: %d\n", result);
    }

    return 0;
}
