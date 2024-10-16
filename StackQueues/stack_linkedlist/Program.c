#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* stackNode = (struct Node*)malloc(sizeof(struct Node));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node* root) {
    return !root;
}

// Function to push an element onto the stack
void push(struct Node** root, int data) {
    struct Node* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

// Function to pop the top element from the stack
int pop(struct Node** root) {
    if (isEmpty(*root)) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to get the top element of the stack
int peek(struct Node* root) {
    if (isEmpty(root)) {
        return -1;
    }
    return root->data;
}

// Main function to demonstrate stack operations
int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("%d popped from stack\n", pop(&stack));

    printf("Top element is %d\n", peek(stack));

    return 0;
}
