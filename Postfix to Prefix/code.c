#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum size for the stack and expression
#define MAX 100

// Stack structure to store strings (expressions)
struct Stack {
    int top;
    char* items[MAX];
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char* str) {
    if (stack->top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++(stack->top)] = strdup(str); // strdup duplicates the string
}

// Function to pop an item from the stack
char* pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack->items[(stack->top)--];
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert a Postfix expression to Prefix
void postfixToPrefix(char* postfix) {
    struct Stack stack;
    initStack(&stack);
    
    int length = strlen(postfix);
    
    // Traverse the Postfix expression from left to right
    for (int i = 0; i < length; i++) {
        // If the character is an operand, push it onto the stack
        if (isalnum(postfix[i])) {
            char operand[2] = {postfix[i], '\0'};  // Create a string for the operand
            push(&stack, operand);
        }
        // If the character is an operator
        else if (isOperator(postfix[i])) {
            // Pop the top two operands from the stack
            char* operand1 = pop(&stack);
            char* operand2 = pop(&stack);
            
            // Create a new string: (operator + operand2 + operand1)
            char* expression = (char*)malloc(strlen(operand1) + strlen(operand2) + 2);
            sprintf(expression, "%c%s%s", postfix[i], operand2, operand1);
            
            // Push the resulting expression back onto the stack
            push(&stack, expression);
            
            // Free dynamically allocated memory
            free(operand1);
            free(operand2);
        }
    }
    
    // The final result is the remaining element in the stack
    char* result = pop(&stack);
    printf("Prefix Expression: %s\n", result);
    
    // Free the final result memory
    free(result);
}

int main() {
    char postfix[MAX];
    
    // Input the Postfix expression
    printf("Enter a Postfix expression: ");
    scanf("%s", postfix);
    
    // Convert and display the Prefix expression
    postfixToPrefix(postfix);
    
    return 0;
}
