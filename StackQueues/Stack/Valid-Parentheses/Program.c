#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    char arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
bool push(Stack *s, char item) {
    if (s->top >= MAX - 1) {
        return false; // Stack overflow
    }
    s->arr[++s->top] = item;
    return true;
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // Return a null character if stack is empty
    }
    return s->arr[s->top--];
}

// Function to check if the brackets are valid
bool isValid(char *s) {
    Stack stack;
    initStack(&stack);
    
    for (int i = 0; s[i] != '\0'; i++) {
        char current = s[i];
        
        if (current == '(' || current == '{' || current == '[') {
            push(&stack, current);
        } else {
            if (isEmpty(&stack)) {
                return false; // No matching opening bracket
            }
            char top = pop(&stack);
            if ((current == ')' && top != '(') ||
                (current == '}' && top != '{') ||
                (current == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }
    
    return isEmpty(&stack); // Return true if stack is empty (all brackets matched)
}

// Example usage
int main() {
    char *testCases[] = {
        "(){}[]",     // Valid
        "(]",         // Invalid
        "{[()]}",     // Valid
        "([{}])",     // Valid
    };
    
    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTestCases; i++) {
        printf("Test Case %d: \"%s\" -> ", i + 1, testCases[i]);
        if (isValid(testCases[i])) {
            printf("The string is valid.\n");
        } else {
            printf("The string is invalid.\n");
        }
    }

    return 0;
}

/*
    Test Case 1: "(){}[]" -> The string is valid.
    Test Case 2: "(]" -> The string is invalid.
    Test Case 3: "{[()]}" -> The string is valid.
    Test Case 4: "([{}])" -> The string is valid.   
*/