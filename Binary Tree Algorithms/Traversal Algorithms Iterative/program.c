#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform iterative inorder traversal
void inorderTraversal(struct Node *root) {
    struct Node *stack[100]; // Stack to hold nodes
    int top = -1;
    struct Node *current = root;

    while (current != NULL || top != -1) {
        // Reach the leftmost node of the current node
        while (current != NULL) {
            stack[++top] = current; // Push current node to stack
            current = current->left; // Move to left child
        }

        // Current must be NULL at this point
        current = stack[top--]; // Pop the top node
        printf("%d ", current->data); // Visit the node

        // We have visited the node and its left subtree.
        // Now, it's right subtree's turn
        current = current->right; // Move to right child
    }
}

// Function to perform iterative preorder traversal
void preorderTraversal(struct Node *root) {
    if (root == NULL) return;

    struct Node *stack[100]; // Stack to hold nodes
    int top = -1;
    stack[++top] = root; // Push root node

    while (top != -1) {
        struct Node *current = stack[top--]; // Pop the top node
        printf("%d ", current->data); // Visit the node

        // Push right child first so that left child is processed first
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
}

// Function to perform iterative postorder traversal
void postorderTraversal(struct Node *root) {
    if (root == NULL) return;

    struct Node *stack[100]; // Stack to hold nodes
    int top = -1;
    struct Node *lastVisited = NULL; // Track the last visited node
    struct Node *current = root;

    while (top != -1 || current != NULL) {
        while (current != NULL) {
            stack[++top] = current; // Push current node to stack
            current = current->left; // Move to left child
        }

        current = stack[top]; // Peek the top node

        // If the right child is not visited or does not exist
        if (current->right == NULL || current->right == lastVisited) {
            printf("%d ", current->data); // Visit the node
            lastVisited = current; // Mark the node as visited
            top--; // Pop the node
            current = NULL; // Set current to NULL
        } else {
            current = current->right; // Move to right child
        }
    }
}

// Level Order Traversal (remains unchanged)
struct QNode {
    struct Node *tNode;
    struct QNode *next;
};

struct QNode *front = NULL;
struct QNode *rear = NULL;

void enqueue(struct Node *tNode);
struct Node *dequeue();

void levelOrderTraversal(struct Node *root) {
    if (root == NULL) return;

    enqueue(root);

    while (front != NULL) {
        struct Node *curr = dequeue();
        printf("%d ", curr->data);
        if (curr->left != NULL) enqueue(curr->left);
        if (curr->right != NULL) enqueue(curr->right);
    }
}

struct QNode *newQNode(struct Node *tNode) {
    struct QNode *qNode = (struct QNode *)malloc(sizeof(struct QNode));
    qNode->tNode = tNode;
    qNode->next = NULL;
    return qNode;
}

void enqueue(struct Node *tNode) {
    struct QNode *qNode = newQNode(tNode);

    if (rear == NULL) {
        front = rear = qNode;
    } else {
        rear->next = qNode;
        rear = qNode;
    }
}

struct Node *dequeue() {
    if (front == NULL) return NULL;
    struct Node *tNode = front->tNode;
    struct QNode *temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return tNode;
}

int main() {
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Tree Representation
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5

    printf("\nInorder traversal: ");
    inorderTraversal(root);
    printf("\nPreorder traversal: ");
    preorderTraversal(root);
    printf("\nPostorder traversal: ");
    postorderTraversal(root);
    printf("\nLevel order traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
