#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;
// Function prototypes
Stack* createStack();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, char item);
char pop(Stack* s);
char peek(Stack* s);
bool isBalanced(const char* expression);
void freeStack(Stack* s);

int main() {
    char expression[MAX_SIZE];
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);
    if (isBalanced(expression)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }
    return 0;
}
// Function to create a stack
Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}
bool isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}
bool isEmpty(Stack* s) {
    return s->top == -1;
}
void push(Stack* s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    }
}
char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0'; 
}
// Function to peek the top item of the stack
char peek(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[s->top];
    }
    return '\0'; // Return null character if stack is empty
}
// Function to check if the parentheses in the expression are balanced
bool isBalanced(const char* expression) {
    Stack* stack = createStack();
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(stack)) {
                freeStack(stack);
                return false; // Unmatched closing parenthesis
            }
            char top = pop(stack);
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                freeStack(stack);
                return false; // Mismatched parentheses
            }
        }
    }
    bool balanced = isEmpty(stack); // Check if stack is empty at the end
    freeStack(stack);
    return balanced;
}
void freeStack(Stack* s) {
    free(s);
}
