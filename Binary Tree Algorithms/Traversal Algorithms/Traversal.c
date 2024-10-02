// #include <stdio.h>
// #include <stdlib.h>
// struct Node {
//     int data;
//     struct Node* next;
// };
// struct TreeNode {
//     int data;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };

// // Function to create a new TreeNode
// struct TreeNode* createTreeNode(int data) {
//     struct TreeNode* newTreeNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//     newTreeNode->data = data;
//     newTreeNode->left = NULL;
//     newTreeNode->right = NULL;
//     return newTreeNode;
// }
// // Queue structure with front and rear pointers
// struct Queue {
//     struct Node* front;
//     struct Node* rear;
// };

// // Function to create a new node
// struct Node* createNode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to create an empty queue
// struct Queue* createQueue() {
//     struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
//     q->front = q->rear = NULL;
//     return q;
// }

// // Function to add an element to the queue (enqueue)
// void enqueue(struct Queue* q, int data) {
//     struct TreeNode* newNode = createTreeNode(data);

//     // If the queue is empty, the new node becomes both front and rear
//     if (q->rear == NULL) {
//         q->front = q->rear = newNode;
//         return;
//     }

//     // Add the new node at the rear and change the rear pointer
//     q->rear->next = newNode;
//     q->rear = newNode;
// }

// // Function to remove an element from the queue (dequeue)
// int dequeue(struct Queue* q) {
//     if (q->front == NULL) {
//         printf("Queue is empty!\n");
//         return -1;
//     }

//     struct Node* temp = q->front;
//     int data = temp->data;

//     q->front = q->front->next;

//     // If front becomes NULL, rear should also be NULL
//     if (q->front == NULL)
//         q->rear = NULL;

//     free(temp);
//     return data;
// }

// // Function to check if the queue is empty
// int isEmpty(struct Queue* q) {
//     return (q->front == NULL);
// }

// // Function to print the queue
// void printQueue(struct Queue* q) {
//     struct Node* temp = q->front;
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// void inOrderTraversal(struct TreeNode* node) {
//     if (node == NULL)
//         return;

//     // Traverse the left subtree
//     inOrderTraversal(node->left);

//     // Visit the root
//     printf("%d ", node->data);

//     // Traverse the right subtree
//     inOrderTraversal(node->right);
// }

// void preOrderTraversal(struct TreeNode* node) {
//     if (node == NULL)
//         return;

//     // Visit the root
//     printf("%d ", node->data);

//     // Traverse the left subtree
//     preOrderTraversal(node->left);

//     // Traverse the right subtree
//     preOrderTraversal(node->right);
// }

// void postOrderTraversal(struct TreeNode* node) {
//     if (node == NULL)
//         return;

//     // Traverse the left subtree
//     postOrderTraversal(node->left);

//     // Traverse the right subtree
//     postOrderTraversal(node->right);

//     // Visit the root
//     printf("%d ", node->data);
// }

// void levelOrderTraversal(struct TreeNode* root) {
//     if (root == NULL)
//         return;

//     // Create a queue for level-order traversal
//     struct Queue* q = createQueue();

//     // Enqueue the root node
//     enqueue(q, root);

//     while (!isEmpty(q)) {
//         // Dequeue a node and print its data
//         struct TreeNode* node = dequeue(q);
//         printf("%d ", node->data);

//         // Enqueue the left child
//         if (node->left != NULL)
//             enqueue(q, node->left);

//         // Enqueue the right child
//         if (node->right != NULL)
//             enqueue(q, node->right);
//     }
//     free(q);  // Clean up the queue memory
// }

// int main() {
//     // Create the tree
//     struct TreeNode* root = createTreeNode(2);
//     root->left = createTreeNode(1);
//     root->right = createTreeNode(3);

//     printf("In-order Traversal: ");
//     inOrderTraversal(root);
//     printf("\n");

//     printf("Pre-order Traversal: ");
//     preOrderTraversal(root);
//     printf("\n");

//     printf("Post-order Traversal: ");
//     postOrderTraversal(root);
//     printf("\n");

//     printf("Level-order Traversal: ");
//     levelOrderTraversal(root);
//     printf("\n");

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to perform inorder traversal
void inorderTraversal(struct Node *root)
{

    // Empty Tree
    if (root == NULL)
        return;

    // Recur on the left subtree
    inorderTraversal(root->left);

    // Visit the current node
    printf("%d ", root->data);

    // Recur on the right subtree
    inorderTraversal(root->right);
}
// Function to perform preorder traversal
void preorderTraversal(struct Node *root)
{

    // Base case
    if (root == NULL)
        return;

    // Visit the current node
    printf("%d ", root->data);

    // Recur on the left subtree
    preorderTraversal(root->left);

    // Recur on the right subtree
    preorderTraversal(root->right);
}

// Function to perform postorder traversal
void postorderTraversal(struct Node *node)
{

    // Base case
    if (node == NULL)
        return;

    // Recur on the left subtree
    postorderTraversal(node->left);

    // Recur on the right subtree
    postorderTraversal(node->right);

    // Visit the current node
    printf("%d ", node->data);
}

struct QNode
{
    struct Node *tNode;
    struct QNode *next;
};

// Ideally we should not use global variables. We have used here
// to reduce code length. Refer the following link for code
// without globals
// https://ide.geeksforgeeks.org/online-c-compiler/022957c0-7344-4773-b2b9-8c0695418af1
struct QNode *front = NULL;
struct QNode *rear = NULL;

// The following functions are defined later
// in this code
void enqueue(struct Node *tNode);
struct Node *dequeue();

// Function to do level order traversal of given
// Binary Tree using a Queue
void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front != NULL)
    {
        struct Node *curr = dequeue();
        printf("%d ", curr->data);
        if (curr->left != NULL)
            enqueue(curr->left);
        if (curr->right != NULL)
            enqueue(curr->right);
    }
}

struct QNode *newQNode(struct Node *tNode)
{
    struct QNode *qNode =
        (struct QNode *)malloc(sizeof(struct QNode));
    qNode->tNode = tNode;
    qNode->next = NULL;
    return qNode;
}
void enqueue(struct Node *tNode)
{
    struct QNode *qNode = newQNode(tNode);

    if (rear == NULL)
    {
        front = rear = qNode;
    }
    else
    {
        rear->next = qNode;
        rear = qNode;
    }
}
struct Node *dequeue()
{
    if (front == NULL)
        return NULL;
    struct Node *tNode = front->tNode;
    struct QNode *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    return tNode;
}

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node =
        (struct Node *)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    //Tree Representation
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5


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
