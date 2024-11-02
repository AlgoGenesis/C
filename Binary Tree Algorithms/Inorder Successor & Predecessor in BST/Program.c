#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new node in BST
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node with given data in BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to find the Inorder Predecessor
struct Node* findPredecessor(struct Node* root, struct Node* node) {
    struct Node* predecessor = NULL;

    while (root) {
        if (node->data <= root->data) {
            root = root->left;
        } else {
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

// Function to find the Inorder Successor
struct Node* findSuccessor(struct Node* root, struct Node* node) {
    struct Node* successor = NULL;

    while (root) {
        if (node->data >= root->data) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

// Driver function to test the above functions
int main() {
    struct Node* root = NULL;
    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    struct Node* node = root->left->right;  // Node with value 12

    struct Node* pred = findPredecessor(root, node);
    if (pred != NULL) {
        printf("Inorder Predecessor of %d is %d\n", node->data, pred->data);
    } else {
        printf("Inorder Predecessor of %d does not exist\n", node->data);
    }

    struct Node* succ = findSuccessor(root, node);
    if (succ != NULL) {
        printf("Inorder Successor of %d is %d\n", node->data, succ->data);
    } else {
        printf("Inorder Successor of %d does not exist\n", node->data);
    }

    return 0;
}
