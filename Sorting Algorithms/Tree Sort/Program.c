#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to perform an in-order traversal of the tree and store the result in the array
void inOrder(struct Node* root, int arr[], int* index) {
    if (root != NULL) {
        inOrder(root->left, arr, index);
        arr[(*index)++] = root->data;
        inOrder(root->right, arr, index);
    }
}

// Function to perform tree sort
void treeSort(int arr[], int n) {
    struct Node* root = NULL;

    // Build the binary search tree
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    // Store the sorted elements in the array
    int index = 0;
    inOrder(root, arr, &index);
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {10, 3, 2, 8, 6, 4, 5, 1, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    treeSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
