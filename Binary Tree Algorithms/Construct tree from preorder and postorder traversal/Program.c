#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findIndex(int *postorder, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (postorder[i] == value) {
            return i;
        }
    }
    return -1; 
}

struct TreeNode* constructTree(int *preorder, int *postorder, int preStart, int preEnd, int postStart, int postEnd) {
    // Base case
    if (preStart > preEnd || postStart > postEnd) {
        return NULL;
    }

    // The first element in preorder is the root
    struct TreeNode* root = createNode(preorder[preStart]);

    // If there's only one node, return it
    if (preStart == preEnd) {
        return root;
    }

    // Find the left root in the preorder
    int leftRootValue = preorder[preStart + 1];
    int leftRootIndex = findIndex(postorder, postEnd - postStart + 1, leftRootValue);

    // Size of the left subtree
    int leftSize = leftRootIndex + 1;

    // Recursively construct left and right subtrees
    root->left = constructTree(preorder, postorder, preStart + 1, preStart + leftSize, postStart, postStart + leftSize - 1);
    root->right = constructTree(preorder, postorder, preStart + leftSize + 1, preEnd, postStart + leftSize, postEnd - 1);

    return root;
}

void printInOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
}
int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int postorder[] = {4, 5, 2, 6, 3, 1};

    int n = sizeof(preorder) / sizeof(preorder[0]);
    
    struct TreeNode* root = constructTree(preorder, postorder, 0, n - 1, 0, n - 1);

    printf("Inorder traversal of the constructed tree: ");
    printInOrder(root);
    printf("\n");


    return 0;
}