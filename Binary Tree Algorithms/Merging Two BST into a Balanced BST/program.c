#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Utility function to create a new BST node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node) {
        node->data = data;
        node->left = node->right = NULL;
    }
    return node;
}

// Utility structure for stack to support in-order traversal
typedef struct Stack {
    Node** arr;
    int top;
    int capacity;
} Stack;

// Create a stack with initial capacity
Stack* createStack(int initialCapacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack) {
        stack->capacity = initialCapacity;
        stack->top = -1;
        stack->arr = (Node**)malloc(stack->capacity * sizeof(Node*));
    }
    return stack;
}

// Resize stack capacity when full
void resizeStack(Stack* stack) {
    stack->capacity *= 2;
    stack->arr = (Node**)realloc(stack->arr, stack->capacity * sizeof(Node*));
}

// Stack utility functions
bool isEmpty(const Stack* stack) { return stack->top == -1; }

void push(Stack* stack, Node* node) {
    if (stack->top >= stack->capacity - 1) {
        resizeStack(stack);  // Double the capacity if needed
    }
    stack->arr[++stack->top] = node;
}

Node* pop(Stack* stack) { return isEmpty(stack) ? NULL : stack->arr[stack->top--]; }

// Insert a node into the BST in a balanced way
Node* sortedArrayToBST(int* restrict arr, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = newNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

// Function to store merged nodes in an array and build balanced BST
Node* mergeAndBalanceBST(Node* root1, Node* root2) {
    // Stacks for in-order traversal with initial capacity
    Stack* stack1 = createStack(100);
    Stack* stack2 = createStack(100);
    if (!stack1 || !stack2) return NULL;

    Node* current1 = root1;
    Node* current2 = root2;
    
    int mergedArr[2000];
    int idx = 0;

    // Perform in-order traversal of both trees simultaneously
    while ((current1 != NULL || !isEmpty(stack1)) ||
           (current2 != NULL || !isEmpty(stack2))) {
        
        // Traverse the first tree
        while (current1 != NULL) {
            push(stack1, current1);
            current1 = current1->left;
        }

        // Traverse the second tree
        while (current2 != NULL) {
            push(stack2, current2);
            current2 = current2->left;
        }

        // Process the smaller of the two nodes
        if (isEmpty(stack2) || (!isEmpty(stack1) && stack1->arr[stack1->top]->data <= stack2->arr[stack2->top]->data)) {
            current1 = pop(stack1);
            mergedArr[idx++] = current1->data;
            current1 = current1->right;
        } else {
            current2 = pop(stack2);
            mergedArr[idx++] = current2->data;
            current2 = current2->right;
        }
    }

    // Build a balanced BST from merged sorted array
    Node* balancedBST = sortedArrayToBST(mergedArr, 0, idx - 1);

    // Free the stacks
    free(stack1->arr);
    free(stack1);
    free(stack2->arr);
    free(stack2);

    return balancedBST;
}

// Function to print the BST in in-order traversal (for testing)
void inorderPrint(const Node* root) {
    if (root == NULL) return;
    inorderPrint(root->left);
    printf("%d ", root->data);
    inorderPrint(root->right);
}

// Test the function
int main() {
    // Create two example BSTs
    Node* root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(3);

    Node* root2 = newNode(7);
    root2->left = newNode(6);
    root2->right = newNode(8);

    // Merge the BSTs
    Node* mergedRoot = mergeAndBalanceBST(root1, root2);

    // Print the merged BST
    printf("In-order traversal of the merged balanced BST:\n");
    inorderPrint(mergedRoot);

    return 0;
}
