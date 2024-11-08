#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to check if two trees are mirrors of each other
int isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) {
        return 1;  // Both nodes are NULL, so they are symmetric
    }
    if (left == NULL || right == NULL) {
        return 0;  // One of the nodes is NULL, so they are not symmetric
    }
    // Check if the current nodes have the same value and
    // the left subtree of one side is a mirror of the right subtree of the other side
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Main function to check if a tree is symmetric
int isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return 1;  // An empty tree is symmetric
    }
    // Use the helper function to compare the left and right subtrees
    return isMirror(root->left, root->right);
}

// Utility function to create a new tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);
    if (isSymmetric(root)) {
        printf("The tree is symmetrical\n");
    } else {
        printf("The tree is not symmetrical\n");
    }
    return 0;
}
