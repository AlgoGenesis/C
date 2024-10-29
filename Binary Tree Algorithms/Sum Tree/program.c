#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isSumTree(struct TreeNode* root, int* sum) {
    // An empty tree is a Sum Tree
    if (root == NULL) {
        *sum = 0;
        return 1; // true
    }
    
    // Leaf nodes are Sum Trees
    if (root->left == NULL && root->right == NULL) {
        *sum = root->value;
        return 1; // true
    }

    int leftSum = 0, rightSum = 0;

    // Recursively check the left and right subtrees
    int leftIsSumTree = isSumTree(root->left, &leftSum);
    int rightIsSumTree = isSumTree(root->right, &rightSum);

    // The current node's value should equal the sum of left and right subtrees
    *sum = leftSum + rightSum + root->value;

    return leftIsSumTree && rightIsSumTree && (root->value == leftSum + rightSum);
}

// Helper function to initiate the check
int isSumTreeWrapper(struct TreeNode* root) {
    int sum = 0;
    return isSumTree(root, &sum);
}

int main() {
    struct TreeNode* root = createNode(26);
    root->left = createNode(10);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(6);
    root->right->right = createNode(3);

    if (isSumTreeWrapper(root)) {
        printf("The binary tree is a Sum Tree.\n");
    } else {
        printf("The binary tree is NOT a Sum Tree.\n");
    }

    return 0;
}
