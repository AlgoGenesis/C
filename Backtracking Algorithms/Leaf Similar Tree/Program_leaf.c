#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to collect leaf nodes in the tree
void collectLeaves(struct TreeNode* root, int* leaves, int* index) {
    if (root == NULL) {
        return;
    }
    // If it's a leaf node, add its value to the leaves array
    if (root->left == NULL && root->right == NULL) {
        leaves[(*index)++] = root->val;
        return;
    }
    // Recur for left and right subtrees
    collectLeaves(root->left, leaves, index);
    collectLeaves(root->right, leaves, index);
}

// Function to check if two trees are leaf-similar
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    // Assuming a maximum of 100 leaves for simplicity
    int leaves1[100], leaves2[100];
    int index1 = 0, index2 = 0;

    // Collect leaves of both trees
    collectLeaves(root1, leaves1, &index1);
    collectLeaves(root2, leaves2, &index2);

    // Compare the number of leaves
    if (index1 != index2) {
        return false;
    }

    // Compare the leaf values
    for (int i = 0; i < index1; i++) {
        if (leaves1[i] != leaves2[i]) {
            return false;
        }
    }

    return true;
}

// Main function to test the leafSimilar function
int main() {
    // Create first tree
    struct TreeNode* root1 = createNode(3);
    root1->left = createNode(5);
    root1->right = createNode(1);
    root1->left->left = createNode(6);
    root1->left->right = createNode(2);
    root1->left->right->left = createNode(9);
    root1->left->right->right = createNode(4);

    // Create second tree
    struct TreeNode* root2 = createNode(7);
    root2->left = createNode(2);
    root2->right = createNode(1);
    root2->left->left = createNode(6);
    root2->left->right = createNode(5);

    // Check if the trees are leaf-similar
    if (leafSimilar(root1, root2)) {
        printf("The trees are leaf-similar.\n");
    } else {
        printf("The trees are not leaf-similar.\n");
    }

    // Free allocated memory (not shown for brevity)
    // You should implement a function to free the tree nodes.

    return 0;
}