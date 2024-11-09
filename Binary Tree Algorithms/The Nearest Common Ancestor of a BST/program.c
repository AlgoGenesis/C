#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//Find the LCA non-recursively
Node* non_recursive_find_LCA(Node* root, Node* p, Node* q) {
    //check if the root is NULL
    if (root == NULL) {
        return 0;
    }
    //If the product of the differences between the root node and p, q is positive, it indicates that 
    //p and q are definitely on the same side of the root node, so continue searching downwards
    while ((root->data - p->data) * (root->data - q->data) > 0){
        root = root->data > p->data ? root->left : root->right; 
	} 
    return root;
}

//Find the LCA recursively
Node* recursive_find_LCA(Node* root, Node* p, Node* q) {
    if (root == NULL) {
        return 0;
    }
    if ((p->data - root->data) * (q->data - root->data) > 0) {
         // Recursively find left and right subtrees
        return recursive_find_LCA(root->data > p->data ? root->left : root->right, p, q);
    }
    return root;
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(20);
    root->left->left = newNode(3);
    root->left->right = newNode(8);
    Node* p = newNode(8);
    Node* q = newNode(20);
    Node* lca = recursive_find_LCA(root, p, q);
    if (lca != NULL) {
        printf("LCA of nodes %d and %d is %d\n", p->data, q->data, lca->data);
    } else {
        printf("One or both nodes are not present in the tree\n");
    }
    return 0;
}