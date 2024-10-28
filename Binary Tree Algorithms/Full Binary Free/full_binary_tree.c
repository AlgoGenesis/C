#include <stdio.h>
#include <stdlib.h>

// Define a structure for tree nodes
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert nodes in a full binary tree
Node* insertLevelOrder(int arr[], Node* root, int i, int n) {
    // Base case for recursion
    if (i < n) {
        Node* temp = createNode(arr[i]);
        root = temp;

        // Insert left child
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        // Insert right child
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Function to perform inorder traversal
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    int n;

    // Ask user for the number of nodes
    printf("Enter the number of nodes in the full binary tree: ");
    scanf("%d", &n);

    // Check if the number of nodes is valid for a full binary tree
    if (n <= 0 || (n & (n + 1)) != 0) {
        printf("Number of nodes must be a power of 2 minus 1 (1, 3, 7, 15, ...).\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));

    // Get node values from the user
    printf("Enter the values for the nodes in level order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = insertLevelOrder(arr, root, 0, n);

    // Inorder traversal of the full binary tree
    printf("Inorder traversal of the full binary tree: ");
    inorderTraversal(root);
    printf("\n");

    // Free allocated memory (not shown for simplicity)
    free(arr);

    return 0;
}