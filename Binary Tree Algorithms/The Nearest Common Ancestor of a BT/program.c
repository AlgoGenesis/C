#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// Function to create a new node
Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//Recursive-search for LCA
Node* find_LCA(Node* root, Node* p, Node* q) {
    if(root == NULL || root->data == p->data || root->data == q->data){
         return root;
    } 
    //Turn on the recursive left child node, the return value is denoted as left
    Node *left = find_LCA(root->left, p, q);
    //Turn on the recursive right child node, the return value is denoted as right
    Node *right = find_LCA(root->right, p, q);
    if(left == NULL){
    //This means nothing on the left. P,q are both on the right, go right
        return right;
    }
    //This means nothing on the right. P,q are both on the left, go left
    if(right == NULL){
        return left;
    } 
    //Left and right are not empty, which meaning p,q are on both sides of root,the root is what we want
    return root;
}


int main() {
    Node* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);
    Node* p=newNode(5);
	Node* q=newNode(4);
    Node* resultNode = find_LCA(root, p, q);
    if (resultNode != NULL) {
        printf("Node with value %d found.\n", resultNode->data);
    } else {
        printf("One or both nodes are not present in the tree\n");
    }
    return 0;
}