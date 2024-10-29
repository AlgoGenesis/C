#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Utility function to check BST properties
bool isBSTUtil(struct Node* node, int min, int max) {
    if (node == NULL)
        return true;

    // Node's value must lie between min and max
    if (node->data <= min || node->data >= max)
        return false;

    // Recursively check left and right subtrees
    return isBSTUtil(node->left, min, node->data) &&
           isBSTUtil(node->right, node->data, max);
}

// Main function to check if a tree is a BST
bool isBST(struct Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(3);
    root->left->right = newNode(8);
    
    if (isBST(root))
        printf("The tree is a Binary Search Tree\n");
    else
        printf("The tree is not a Binary Search Tree\n");

    return 0;
}
