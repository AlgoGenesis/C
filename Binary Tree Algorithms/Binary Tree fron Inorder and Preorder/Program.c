#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to search for an index of a given value in the inorder array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i; // Return the index of the found value
        }
    }
    return -1; // Return -1 if the value is not found
}

// Function to construct the binary tree from inorder and preorder arrays
struct Node* buildTree(int inorder[], int preorder[], int inorderStart, int inorderEnd, int* preIndex) {
    if (inorderStart > inorderEnd) {
        return NULL; // Base case: no elements to construct the tree
    }

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = preorder[*preIndex]; // Get the current node value from preorder
    (*preIndex)++; // Move to the next value in the preorder array

    if (inorderStart == inorderEnd) {
        node->left = node->right = NULL; // Leaf node
        return node;
    }

    // Find the index of the current node in the inorder array
    int inorderIndex = search(inorder, inorderStart, inorderEnd, node->data);

    // Recursively construct the left and right subtrees
    node->left = buildTree(inorder, preorder, inorderStart, inorderIndex - 1, preIndex);
    node->right = buildTree(inorder, preorder, inorderIndex + 1, inorderEnd, preIndex);

    return node; // Return the constructed subtree
}

// Function to print the preorder traversal of the tree
void printPreOrder(struct Node* node) {
    if (node == NULL) {
        return; // Base case: empty node
    }
    printf("%d ", node->data); // Print the root
    printPreOrder(node->left);  // Print the left subtree
    printPreOrder(node->right); // Print the right subtree
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int inorder[n], preorder[n];

    printf("Enter the inorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]); // Input for inorder traversal
    }

    printf("Enter the preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]); // Input for preorder traversal
    }

    int preIndex = 0; // Initialize preIndex to the first index of preorder
    struct Node* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    printf("Preorder traversal of the constructed tree: ");
    printPreOrder(root);
    printf("\n");

    return 0;
}
