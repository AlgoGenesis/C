// C++ code to check if leaf traversals
// of two Binary Trees are same or not.
#include <bits/stdc++.h>
using namespace std;
 
// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
 
// Returns new Node with data as
// input to below function.
Node* newNode(int d)
{
    Node* temp = new Node;
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
 
    return temp;
}
 
// Function to store the leaf nodes of the tree
void collectLeafNodes(Node* root, vector<int>& storeLeaf)
{
    if (!root->left && !root->right) {
        storeLeaf.push_back(root->data);
    }
    if (root->left) {
        collectLeafNodes(root->left, storeLeaf);
    }
    if (root->right) {
        collectLeafNodes(root->right, storeLeaf);
    }
}
 
// iterative function.
// returns true if leaf traversals
// are same, else false.
bool isSame(Node* root1, Node* root2)
{
    vector<int> storeLeafTree1, storeLeafTree2;
    collectLeafNodes(root1, storeLeafTree1);
    collectLeafNodes(root2, storeLeafTree2);
    return storeLeafTree1 == storeLeafTree2;
}
 
// Driver Code
int main()
{
    Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);
 
    Node* root2 = newNode(0);
    root2->left = newNode(1);
    root2->right = newNode(5);
    root2->left->right = newNode(4);
    root2->right->left = newNode(6);
    root2->right->right = newNode(7);
 
    if (isSame(root1, root2))
        cout << "Same";
    else
        cout << "Not Same";
    return 0;
}