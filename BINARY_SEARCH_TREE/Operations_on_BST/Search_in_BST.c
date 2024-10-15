#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Constructor to create a new BST node
struct Node* newNode(int item)
{
    struct Node* temp
        = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// function to search a key in a BST
struct Node* search(struct Node* root, int key)
{

    // Base Cases: root is null or key is
    // present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

// Driver Code
int main()
{
    // Creating a hard coded tree for keeping 
    // the length of the code small. We need 
    // to make sure that BST properties are 
    // maintained if we try some other cases.
    struct Node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    printf(search(root, 19) != NULL ? "Found\n"
                                    : "Not Found\n");
    printf(search(root, 80) != NULL ? "Found\n"
                                    : "Not Found\n");

    return 0;
}
