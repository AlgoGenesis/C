#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int size;
    struct Node *left, *right;
} Node;

// Utility function to create a new node
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->size = 1;
    node->left = node->right = NULL;
    return node;
}

// Updates the size of a node based on its children
void updateSize(Node *node) {
    if (node != NULL) {
        node->size = 1 + (node->left ? node->left->size : 0) + (node->right ? node->right->size : 0);
    }
}

// Perform right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    updateSize(y);
    updateSize(x);
    return x;
}

// Perform left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    updateSize(x);
    updateSize(y);
    return y;
}

// Splay operation to bring a key to the root of the tree
Node* splay(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key) {
        if (root->left == NULL) return root;

        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right) root->left = leftRotate(root->left);
        }
        return (root->left == NULL) ? root : rightRotate(root);
    } else {
        if (root->right == NULL) return root;

        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        } else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left) root->right = rightRotate(root->right);
        }
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Insert a new key in the augmented splay tree
Node* insert(Node* root, int key) {
    if (root == NULL) return newNode(key);

    root = splay(root, key);
    if (root->key == key) return root;

    Node* new_node = newNode(key);
    if (key < root->key) {
        new_node->right = root;
        new_node->left = root->left;
        root->left = NULL;
    } else {
        new_node->left = root;
        new_node->right = root->right;
        root->right = NULL;
    }
    updateSize(root);
    updateSize(new_node);
    return new_node;
}

// Find the k-th smallest element in the tree
Node* findKthSmallest(Node* root, int k) {
    if (root == NULL || k <= 0 || k > root->size) return NULL;

    int leftSize = root->left ? root->left->size : 0;
    if (k == leftSize + 1) return root;
    else if (k <= leftSize) return findKthSmallest(root->left, k);
    else return findKthSmallest(root->right, k - leftSize - 1);
}

// Print in-order traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 10);
    root = insert(root, 5);

    printf("In-order traversal of the augmented splay tree:\n");
    inorder(root);

    int k = 3;
    Node* kthNode = findKthSmallest(root, k);
    if (kthNode) printf("\n%d-th smallest element is %d\n", k, kthNode->key);
    else printf("\n%d-th smallest element does not exist\n", k);

    return 0;
}
