#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

struct Stack {
    int top;
    char items[MAX];
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

int isFull(struct Stack* stack) {
    return (stack->top == (MAX - 1));
}

void push(struct Stack* stack, char c) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = c;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->items[stack->top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to reverse a string
void reverse(char* exp) {
    int length = strlen(exp);
    for (int i = 0; i < length / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
}

// Function to swap '(' with ')' and vice versa
void swapBrackets(char* exp) {
    int length = strlen(exp);
    for (int i = 0; i < length; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
}

void infixToPrefix(char* infix, char* prefix) {
    struct Stack stack;
    initStack(&stack);

    // Reverse the infix expression and handle brackets
    reverse(infix);
    swapBrackets(infix);

    int i = 0, j = 0;
    while (infix[i] != '\0') {

        // If the character is an operand, add it to the prefix output
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        }
        // If the character is '(', push it to the stack
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        // If the character is ')', pop from the stack until '(' is found
        else if (infix[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                prefix[j++] = pop(&stack);
            }
            pop(&stack);  // Pop '('
        }
        // If the character is an operator
        else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) > precedence(infix[i])) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        i++;
    }

    // Pop all the remaining operators from the stack
    while (!isEmpty(&stack)) {
        prefix[j++] = pop(&stack);
    }

    prefix[j] = '\0';  // Null-terminate the string

    // Reverse the prefix expression to get the correct result
    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix: %s\n", prefix);

    return 0;
}
