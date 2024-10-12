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
        return createNode(data); 
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);  
    } else {
        root->right = insertNode(root->right, data);  
    }

    return root;
}


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

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d -> ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d -> ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d -> ", root->data);
    }
}


void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[100];  
    int front = 0, rear = 0;

    // Enqueue root node
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++]; 
        printf("%d -> ", current->data);        

        
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

// Find minimum node - used in delete node algorithm
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete Node Algorithm in binary tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root; 
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);
        root->data = temp->data; // Copy the in-order successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the in-order successor
    }
    return root;
}


int main() {
    struct Node* root = NULL; 

    
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    
    int searchValue = 40;
    if (searchNode(root, searchValue)) {
        printf("Node with value %d found in the tree.\n", searchValue);
    } else {
        printf("Node with value %d not found in the tree.\n", searchValue);
    }

    
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

    // Deleting a node
    root = deleteNode(root, 70);
    printf("\nAfter deleting node 70:\n");

    printf("\nIn-order Traversal (Depth-First):\n");
    inorderTraversal(root);
    printf("NULL\n");

    return 0;
}