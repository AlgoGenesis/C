#include <stdio.h>
#include <stdlib.h>

// Binary Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);  // Create a new node if the tree is empty
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);  // Insert in the left subtree
    } else {
        root->right = insertNode(root->right, data);  // Insert in the right subtree
    }

    return root;
}

// Function to search for a value in the binary tree
int searchNode(struct Node* root, int key) {
    if (root == NULL) {
        return 0;  // Return 0 if the value is not found
    }

    if (root->data == key) {
        return 1;  // Return 1 if the value is found
    }

    if (key < root->data) {
        return searchNode(root->left, key);  // Search in the left subtree
    } else {
        return searchNode(root->right, key);  // Search in the right subtree
    }
}

// In-order traversal (Depth-First)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d -> ", root->data);
        inorderTraversal(root->right);
    }
}

// Pre-order traversal (Depth-First)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d -> ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Post-order traversal (Depth-First)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d -> ", root->data);
    }
}

// Breadth-First (Level-order traversal)
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[100];  // Static array as a simple queue
    int front = 0, rear = 0;

    // Enqueue root node
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];  // Dequeue current node
        printf("%d -> ", current->data);        // Print the node data

        // Enqueue the left child
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        // Enqueue the right child
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

// Main function to demonstrate binary tree operations
int main() {
    struct Node* root = NULL;  // Initialize an empty tree

    // Insert nodes into the tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    // Search for a node
    int searchValue = 40;
    if (searchNode(root, searchValue)) {
        printf("Node with value %d found in the tree.\n", searchValue);
    } else {
        printf("Node with value %d not found in the tree.\n", searchValue);
    }

    // Depth-first traversals
    printf("\nIn-order Traversal (Depth-First):\n");
    inorderTraversal(root);
    printf("NULL\n");

    printf("\nPre-order Traversal (Depth-First):\n");
    preorderTraversal(root);
    printf("NULL\n");

    printf("\nPost-order Traversal (Depth-First):\n");
    postorderTraversal(root);
    printf("NULL\n");

    // Breadth-first traversal
    printf("\nLevel-order Traversal (Breadth-First):\n");
    levelOrderTraversal(root);
    printf("NULL\n");

    return 0;
}