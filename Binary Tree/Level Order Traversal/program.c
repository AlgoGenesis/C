#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue structure for holding TreeNode pointers
struct Queue {
    struct TreeNode** data;
    int front, rear, size, capacity;
};

// Function to create a queue of given capacity
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (struct TreeNode**)malloc(queue->capacity * sizeof(struct TreeNode*));
    return queue;
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    return queue->size == queue->capacity;
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, struct TreeNode* item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to remove an item from the queue
struct TreeNode* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return NULL;
    struct TreeNode* item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to build a tree by taking user input
struct TreeNode* buildTree() {
    int val;
    printf("Enter root node value (or -1 for NULL): ");
    scanf("%d", &val);
    
    if (val == -1) return NULL;

    struct TreeNode* root = createNode(val);
    struct Queue* queue = createQueue(100);  // Adjust size as needed
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        struct TreeNode* current = dequeue(queue);

        // Left child
        printf("Enter left child of %d (or -1 for NULL): ", current->val);
        scanf("%d", &val);
        if (val != -1) {
            current->left = createNode(val);
            enqueue(queue, current->left);
        }

        // Right child
        printf("Enter right child of %d (or -1 for NULL): ", current->val);
        scanf("%d", &val);
        if (val != -1) {
            current->right = createNode(val);
            enqueue(queue, current->right);
        }
    }

    free(queue->data);
    free(queue);
    return root;
}

// Function to perform level order traversal
void levelOrder(struct TreeNode* root) {
    if (!root) return;

    struct Queue* queue = createQueue(100);  // Adjust size as needed
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        int levelSize = queue->size;

        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* node = dequeue(queue);
            printf("%d ", node->val);

            if (node->left) enqueue(queue, node->left);
            if (node->right) enqueue(queue, node->right);
        }
        printf("\n");  // End of level
    }

    free(queue->data);
    free(queue);
}

int main() {
    printf("Build the binary tree:\n");
    struct TreeNode* root = buildTree();

    printf("\nLevel Order Traversal:\n");
    levelOrder(root);

    return 0;
}
