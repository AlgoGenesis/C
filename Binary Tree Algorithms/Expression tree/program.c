#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
// Define a structure for tree nodes
struct Node {
    char value;
    struct Node *left, *right;
};
// Function to create a new node
struct Node* newNode(char value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}
// Stack structure to store nodes
struct Stack {
    int top;
    unsigned capacity;
    struct Node** array;
};
// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
    return stack;
}
// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
// Push node to stack
void push(struct Stack* stack, struct Node* node) {
    stack->array[++stack->top] = node;
}
// Pop node from stack
struct Node* pop(struct Stack* stack) {
    return stack->array[stack->top--];
}
// Function to check if given character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
// Function to create expression tree from postfix expression
struct Node* constructTree(char postfix[]) {
    struct Stack* stack = createStack(strlen(postfix));
    struct Node *t, *t1, *t2;
    // Iterate through each character of the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++) {
        // If operand, create node and push it to the stack
        if (!isOperator(postfix[i])) {
            t = newNode(postfix[i]);
            push(stack, t);
        }
        // If operator, pop two nodes, create new node, and push it to the stack
        else {
            t = newNode(postfix[i]);
            t1 = pop(stack); // first operand
            t2 = pop(stack); // second operand
            t->right = t1;
            t->left = t2;
            push(stack, t);
        }
    }
    // Root of the expression tree is at the top of the stack
    return pop(stack);
}
// Function to evaluate the expression in inorder traversal
int evaluate(struct Node* root) {
    // Base case: if node is a leaf node (operand), return its integer value
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->value - '0';
    // Recursive case: evaluate left and right subtrees
    int left_val = evaluate(root->left);
    int right_val = evaluate(root->right);
    // Apply operator on the left and right subtree values
    if (root->value == '+')
        return left_val + right_val;
    if (root->value == '-')
        return left_val - right_val;
    if (root->value == '*')
        return left_val * right_val;
    if (root->value == '/')
        return left_val / right_val;
    return 0;
}
// Inorder traversal to print infix expression
void inorder(struct Node* t) {
    if (t) {
        if (isOperator(t->value))
            printf("(");
        inorder(t->left);
        printf("%c", t->value);
        inorder(t->right);
        if (isOperator(t->value))
            printf(")");
    }
}

int main() {
    char postfix[] = "53+82-*"; 
    struct Node* root = constructTree(postfix);
    printf("Infix expression: ");
    inorder(root); 
    printf("\n");
    int result = evaluate(root);
    printf("Evaluated value: %d\n", result);
    return 0;
}
