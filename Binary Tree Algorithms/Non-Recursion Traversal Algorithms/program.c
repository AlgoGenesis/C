#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;               
    struct Node *left;      
    struct Node *right;     
} Node;


typedef struct StackNode {
    Node *treeNode;
    // Pointer to the next stack node
    struct StackNode *next; 
} StackNode;

// Function to create a new node
Node* newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node)); 
    node->data = data;                          
    node->left = NULL;                          
    node->right = NULL;                         
    return node;
}

// Function to create a new stack node
StackNode* newStackNode(Node *treeNode) {
    StackNode *stackNode = (StackNode *)malloc(sizeof(StackNode)); 
    stackNode->treeNode = treeNode;  
    stackNode->next = NULL;   
    return stackNode;
}

// Function to check if the stack is empty
int isStackEmpty(StackNode *top) {
    return top == NULL;
}

// Function to push a node onto the stack
void push(StackNode **top, Node *treeNode) {
    StackNode *newStackNode = (StackNode *)malloc(sizeof(StackNode));
    newStackNode->treeNode = treeNode; 
    newStackNode->next = *top;        
    *top = newStackNode;           
}

// Function to pop a node from the stack
Node* pop(StackNode **top) {
    if (isStackEmpty(*top)) {
        return NULL;
    }
    StackNode *temp = *top; 
    Node *treeNode = temp->treeNode; 
    *top = temp->next; 
    free(temp);        
    return treeNode; 
}

// Function to get the top node of the stack
Node* top(StackNode *top) {
    if (isStackEmpty(top)) {
        return NULL; 
    }
    return top->treeNode;
}

// Function to perform preorder traversal of the tree
void preorderTraversal(Node *root) {
    if (root == NULL) return; 
    StackNode *stack = NULL;  
    // Push the root node onto the stack
    push(&stack, root);       
    while (!isStackEmpty(stack)) {
        Node *current = pop(&stack); 
        // Print the data
        printf("%d ", current->data);
        if (current->right) push(&stack, current->right);
        if (current->left) push(&stack, current->left); 
    }
}

// Function to perform inorder traversal of the tree
void inorderTraversal(Node *root) {
    if (root == NULL) return; 
    StackNode *stack = NULL; 
    Node *current = root;     
    while (current != NULL || !isStackEmpty(stack)) {
        while (current != NULL) {
            // Push nodes onto the stack
            push(&stack, current); 
            // Move to the left child
            current = current->left; 
        }
        current = pop(&stack);
        printf("%d ", current->data); 
        // Move to the right child
        current = current->right; 
    }
}

// Function to perform postorder traversal of the tree
void postorderTraversal(Node *root) {
    if (root == NULL) return; 
    // Initialize stack1
    StackNode *stack1 = NULL; 
    // Initialize stack2
    StackNode *stack2 = NULL; 
    // Push the root node onto stack1
    push(&stack1, root);     
    while (!isStackEmpty(stack1)) {
        Node *current = pop(&stack1); 
        // Push the node onto stack2
        push(&stack2, current);       
        // Push left child if it exists
        if (current->left) push(&stack1, current->left); 
        // Push right child if it exists
        if (current->right) push(&stack1, current->right); 
    }
    while (!isStackEmpty(stack2)) {
        // Pop a node from stack2
        Node *current = pop(&stack2); 
        printf("%d ", current->data);
    }
}

// Main function to demonstrate tree traversals
int main() {
    Node* root = newNode(10); 
    root->left = newNode(5); 
    root->right = newNode(20); 
    root->left->left = newNode(3); 
    root->left->right = newNode(8); 
    printf("Preorder traversal: ");
    preorderTraversal(root); 
    printf("\n");
    printf("Inorder traversal: ");
    inorderTraversal(root); 
    printf("\n");
    printf("Postorder traversal: ");
    postorderTraversal(root); 
    printf("\n");
    return 0;
}