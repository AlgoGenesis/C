#include <stdio.h>
#include <stdlib.h>

// Define a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE); // Exit if malloc fails
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data); 
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);  
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);  
    }

    return root;
}

// Function to search for a node with a given value in the binary tree
int searchNode(struct Node* root, int key) {
    if (root == NULL) {
        return 0; 
    }

    if (root->data == key) {
        return 1;  
    }

    if (key < root->data) {
        return searchNode(root->left, key);  
    } else {
        return searchNode(root->right, key);  
    }
}

// Function for in-order traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);
    printf("%d -> ", root->data);
    inorderTraversal(root->right);
}

// Function for pre-order traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root == NULL) return;

    printf("%d -> ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Function for post-order traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->data);
}

// Function for level-order traversal (Breadth-First Search)
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    // Dynamically allocated queue
    struct Node** queue = malloc(100 * sizeof(struct Node*));
    if (queue == NULL) {
        perror("Failed to allocate memory for the queue");
        exit(EXIT_FAILURE);
    }

    int front = 0, rear = 0;
    queue[rear++] = root;  // Enqueue the root node

    while (front < rear) {
        struct Node* current = queue[front++]; // Dequeue the current node
        printf("%d -> ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;  // Enqueue left child
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;  // Enqueue right child
        }
    }

    free(queue);  // Free the dynamically allocated memory for the queue
}

// Function to free memory allocated for the binary tree
void freeTree(struct Node* root) {
    if (root == NULL) return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;

    // Insert nodes into the binary search tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    // Search for a value in the tree
    int searchValue = 40;
    if (searchNode(root, searchValue)) {
        printf("Node with value %d found in the tree.\n", searchValue);
    } else {
        printf("Node with value %d not found in the tree.\n", searchValue);
    }

    // Perform various tree traversals
    printf("\nIn-order Traversal (Depth-First):\n");
    inorderTraversal(root);
    printf("NULL\n");

    printf("\nPre-order Traversal (Depth-First):\n");
    preorderTraversal(root);
    printf("NULL\n");

    printf("\nPost-order Traversal (Depth-First):\n");
    postorderTraversal(root);
    printf("NULL\n");

    printf("\nLevel-order Traversal (Breadth-First):\n");
    levelOrderTraversal(root);
    printf("NULL\n");

    // Free the allocated memory for the binary tree
    freeTree(root);

    return 0;
}
