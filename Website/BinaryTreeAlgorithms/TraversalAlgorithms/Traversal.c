#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node *newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform inorder traversal
void inorderTraversal(Node *root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to perform preorder traversal
void preorderTraversal(Node *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function to perform postorder traversal
void postorderTraversal(Node *root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Define the structure for a queue node
typedef struct QNode {
    Node *tNode;
    struct QNode *next;
} QNode;

// Function to create a new queue node
QNode *newQNode(Node *tNode) {
    QNode *qNode = (QNode *)malloc(sizeof(QNode));
    qNode->tNode = tNode;
    qNode->next = NULL;
    return qNode;
}

// Function to enqueue a node
void enqueue(Node *tNode) {
    QNode *qNode = newQNode(tNode);

    if (rear == NULL)
        front = rear = qNode;
    else {
        rear->next = qNode;
        rear = qNode;
    }
}

// Function to dequeue a node
Node *dequeue() {
    if (front == NULL)
        return NULL;

    Node *tNode = front->tNode;
    QNode *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    return tNode;
}

// Function to perform level order traversal
void levelOrderTraversal(Node *root) {
    if (root == NULL)
        return;

    enqueue(root);

    while (front != NULL) {
        Node *curr = dequeue();
        printf("%d ", curr->data);
        if (curr->left != NULL)
            enqueue(curr->left);
        if (curr->right != NULL)
            enqueue(curr->right);
    }
}

QNode *front = NULL;
QNode *rear = NULL;

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("\n\n");
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n\n");
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n\n");
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n\n");
    printf("Level order traversal: ");
    levelOrderTraversal(root);
    printf("\n\n");
    return 0;
}