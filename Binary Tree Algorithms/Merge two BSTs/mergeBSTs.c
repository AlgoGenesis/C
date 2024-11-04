#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode *left, *right;
} TreeNode;

// Create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// In-order traversal to store values in a sorted array
void inorderTraversal(TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    inorderTraversal(root->left, arr, index);
    arr[(*index)++] = root->value;
    inorderTraversal(root->right, arr, index);
}

// Merge two sorted arrays into one
int* mergeSortedArrays(int* arr1, int size1, int* arr2, int size2, int* mergedSize) {
    *mergedSize = size1 + size2;
    int* mergedArr = (int*)malloc(*mergedSize * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }

    // Copy any remaining elements from arr1
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    // Copy any remaining elements from arr2
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }

    return mergedArr;
}

// Convert a sorted array to a balanced BST
TreeNode* sortedArrayToBST(int* arr, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    TreeNode* root = createNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Merge two BSTs into a single balanced BST
TreeNode* mergeTwoBSTs(TreeNode* root1, TreeNode* root2) {
    int arr1[100], arr2[100];  // Assuming max 100 nodes in each tree
    int index1 = 0, index2 = 0;

    // Get in-order traversal of both trees
    inorderTraversal(root1, arr1, &index1);
    inorderTraversal(root2, arr2, &index2);

    // Merge the two sorted arrays
    int mergedSize;
    int* mergedArr = mergeSortedArrays(arr1, index1, arr2, index2, &mergedSize);

    // Convert the merged sorted array into a balanced BST
    TreeNode* mergedBST = sortedArrayToBST(mergedArr, 0, mergedSize - 1);

    // Free the merged array after use
    free(mergedArr);

    return mergedBST;
}

// Utility function to print in-order traversal of a BST
void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
}

// Driver code to test the merge function
int main() {
    // Creating two sample BSTs

    // BST 1:
    //      3
    //     / \
    //    1   5
    TreeNode* root1 = createNode(3);
    root1->left = createNode(1);
    root1->right = createNode(5);

    // BST 2:
    //      4
    //     / \
    //    2   6
    TreeNode* root2 = createNode(4);
    root2->left = createNode(2);
    root2->right = createNode(6);

    // Merge the two BSTs
    TreeNode* mergedBST = mergeTwoBSTs(root1, root2);

    // Print the in-order traversal of the merged BST
    printf("In-order traversal of the merged BST: ");
    printInOrder(mergedBST);

    return 0;
}
