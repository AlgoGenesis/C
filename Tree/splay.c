#include <stdio.h>
#include <stdlib.h>

// Structure of a Splay Tree Node
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Right rotation function
struct Node* rightRotate(struct Node* x) {
    struct Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Left rotation function
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splay operation to bring the key to the root
struct Node* splay(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    // Key is in the left subtree
    if (key < root->key) {
        if (root->left == NULL) return root;

        // Zig-Zig (Left Left)
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key is in the right subtree
    else {
        if (root->right == NULL) return root;

        // Zag-Zig (Right Left)
        if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Function to search a key in the Splay Tree
struct Node* search(struct Node* root, int key) {
    return splay(root, key);
}

// Function to insert a new key in the Splay Tree
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);

    root = splay(root, key);

    if (root->key == key) return root; // If key already exists, return root

    struct Node* newnode = newNode(key);

    if (key < root->key) {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    } else {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }

    return newnode;
}

// Function to delete a key from the Splay Tree
struct Node* deleteNode(struct Node* root, int key) {
    struct Node* temp;
    if (root == NULL) return NULL;

    root = splay(root, key);

    if (key != root->key) return root; // Key not found, return root

    // Key found
    if (root->left == NULL) {
        temp = root;
        root = root->right;
    } else {
        temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
    }

    free(temp);
    return root;
}

// Pre-order traversal of the Splay Tree
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Main function to test the Splay Tree implementation
int main() {
    struct Node* root = NULL;

    // Insert operations
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 20);

    printf("Pre-order traversal of the splay tree is: \n");
    preOrder(root);

    // Search operation
    root = search(root, 50);
    printf("\nAfter searching 50, pre-order traversal is: \n");
    preOrder(root);

    // Delete operation
    root = deleteNode(root, 50);
    printf("\nAfter deleting 50, pre-order traversal is: \n");
    preOrder(root);

    return 0;
}