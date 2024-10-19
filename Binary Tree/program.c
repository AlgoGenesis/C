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

//Method to free tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
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

    freeTree(root);

    return 0;
}
