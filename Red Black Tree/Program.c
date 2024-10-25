#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

typedef struct Node {
    int data;
    enum Color color;
    struct Node *left, *right, *parent;
} Node;

Node* root = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

// Function to perform a left rotation
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Function to perform a right rotation
void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Fixing the Red-Black Tree after insertion
void fixInsert(Node** root, Node* node) {
    Node *parent = NULL, *grandparent = NULL;

    while ((node != *root) && (node->color != BLACK) && (node->parent->color == RED)) {
        parent = node->parent;
        grandparent = parent->parent;

        // Parent is the left child of grandparent
        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            // Case 1: Uncle is red
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                // Case 2: Node is the right child
                if (node == parent->right) {
                    leftRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                // Case 3: Node is the left child
                rightRotate(root, grandparent);
                enum Color temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                node = parent;
            }
        } else {  // Parent is the right child of grandparent
            Node* uncle = grandparent->left;

            // Case 1: Uncle is red
            if ((uncle != NULL) && (uncle->color == RED)) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                // Case 2: Node is the left child
                if (node == parent->left) {
                    rightRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                // Case 3: Node is the right child
                leftRotate(root, grandparent);
                enum Color temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                node = parent;
            }
        }
    }
    (*root)->color = BLACK;
}

// Insert a node into the Red-Black Tree
void insert(Node** root, int data) {
    Node* node = createNode(data);
    Node* y = NULL;
    Node* x = *root;

    // BST insertion
    while (x != NULL) {
        y = x;
        if (node->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;
    if (y == NULL)
        *root = node;
    else if (node->data < y->data)
        y->left = node;
    else
        y->right = node;

    // Fix the Red-Black Tree properties
    fixInsert(root, node);
}

// In-order traversal of the tree
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d (%s) ", root->data, root->color == RED ? "R" : "B");
    inorderTraversal(root->right);
}

int main() {
    int n, data;
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter node %d value: ", i + 1);
        scanf("%d", &data);
        insert(&root, data);
    }

    printf("\nIn-order traversal of the Red-Black Tree:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
