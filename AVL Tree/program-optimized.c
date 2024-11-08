#include <stdio.h>
#include <stdlib.h>

// AVL Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Get the height of a node
int height(struct Node* node) {
    return (node == NULL) ? 0 : node->height;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Update the height of a node based on its children
void updateHeight(struct Node* node) {
    node->height = 1 + ((height(node->left) > height(node->right)) ? height(node->left) : height(node->right));
}

// Perform a right rotation
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;
    x->right = y;
    updateHeight(y);
    updateHeight(x);
    return x;
}

// Perform a left rotation
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    y->left = x;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// Get the balance factor of a node
int getBalance(struct Node* node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

// Insert a node into the AVL tree
struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL) return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node;

    updateHeight(node);

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find the node with the minimum value in an AVL tree
struct Node* findMin(struct Node* node) {
    while (node->left != NULL) node = node->left;
    return node;
}

// Delete a node from the AVL tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return NULL;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    updateHeight(root);
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Search for a node in the AVL tree
int searchNode(struct Node* root, int data) {
    if (root == NULL) return 0;
    if (data == root->data) return 1;
    return (data < root->data) ? searchNode(root->left, data) : searchNode(root->right, data);
}

// In-order traversal of the AVL tree
void inorderTraversal(struct Node* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d -> ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    printf("In-order traversal after insertions:\n");
    inorderTraversal(root);
    printf("NULL\n");

    // Deletion
    root = deleteNode(root, 20);
    printf("In-order traversal after deleting 20:\n");
    inorderTraversal(root);
    printf("NULL\n");

    // Searching
    int searchKey = 25;
    printf("Node %d %s in the AVL tree.\n", searchKey, searchNode(root, searchKey) ? "found" : "not found");

    return 0;
}
