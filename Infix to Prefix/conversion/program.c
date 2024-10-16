#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
#define OPERATOR_PRECEDENCE 3 // Added constant for operator precedence

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
        fprintf(stderr, "Stack overflow: Unable to push '%c'\n", c);
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = c;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Stack underflow: No elements to pop\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->items[stack->top];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Changed to switch-case for better clarity
int precedence(char c) {
    switch (c) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
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
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            exp[i] = ')';
        } else if (exp[i] == ')') {
            exp[i] = '(';
        }
    }
}

// Added input validation function
int isValidInfix(const char* exp) {
    int openBrackets = 0;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') openBrackets++;
        if (exp[i] == ')') openBrackets--;
        if (openBrackets < 0) return 0;
    }
    return (openBrackets == 0);
}

void infixToPrefix(const char* infix, char* prefix) {
    struct Stack stack;
    initStack(&stack);

    // Validate the infix expression
    if (!isValidInfix(infix)) {
        fprintf(stderr, "Invalid infix expression: Unmatched parentheses\n"); // Improved error message
        exit(EXIT_FAILURE); // Exit program on invalid input
    }

    // Reverse the infix expression and handle brackets
    char reversed[MAX];
    strcpy(reversed, infix);
    reverse(reversed);
    swapBrackets(reversed);

    int i = 0, j = 0;
    while (reversed[i] != '\0') {
        if (isalnum(reversed[i])) {
            prefix[j++] = reversed[i];
        }
        else if (reversed[i] == '(') {
            push(&stack, reversed[i]);
        }
        else if (reversed[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                prefix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack)) {
                pop(&stack);
            }
        }
        // If the character is an operator
        else if (isOperator(reversed[i])) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(reversed[i])) {
                prefix[j++] = pop(&stack);
            }
            push(&stack, reversed[i]);
        } else {
            fprintf(stderr, "Invalid character in infix expression: %c\n", reversed[i]); // Error for invalid characters
            exit(EXIT_FAILURE); // Exit program on invalid character
        }
        i++;
    }
    while (!isEmpty(&stack)) {
        prefix[j++] = pop(&stack);
    }
    prefix[j] = '\0';
    reverse(prefix);
}

// Function to run test cases
void runTests() {
    const char* testCases[][3] = {
        {"A+B", " +AB", "Test 1"},        // Test case 1
        {"(A-B)/C", " /-ABC", "Test 2"},   // Test case 2
        {"A*B+C", " +*ABC", "Test 3"},     // Test case 3
        {"A+(B*C)", " +A*BC", "Test 4"},   // Test case 4
        {"(A-B)*(C+D)", " *-AB+CD", "Test 5"} // Test case 5
    };

    printf("%-10s | %-10s   | %-10s | %-10s | %-10s\n", "Test No", "Infix", "Expected", "Actual", "Status");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < 5; i++) {
        char prefix[MAX];
        infixToPrefix(testCases[i][0], prefix);
        
        // Checking status
        const char* status = (strcmp(prefix, testCases[i][1]) == 0) ? "Pass" : "Fail";
        
        // Printing test results
        printf("%-10s | %-10s  | %-10s | %-10s | %-10s\n", testCases[i][2], testCases[i][0], testCases[i][1], prefix, status);
    }
}

int main() {
    // Running test cases
    runTests();

    return 0;
}
