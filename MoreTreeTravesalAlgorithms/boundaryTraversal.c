//this is the code of boundary traversal algorithm. this prints out only boundaries of the tree.

#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int isLeaf(struct Node *node)
{
    return (node->left == NULL && node->right == NULL);
}

// Function to print the left boundary (excluding leaf nodes)
void printLeftBoundary(struct Node *root)
{
    struct Node *current = root;
    while (current)
    {
        if (!isLeaf(current))
        {
            printf("%d ", current->data); 
        }
        
        if (current->left)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
}

// Function to print all leaf nodes
void printLeaves(struct Node *root)
{
    if (root == NULL)
        return;

    
    printLeaves(root->left);

    
    if (isLeaf(root))
    {
        printf("%d ", root->data);
    }

    
    printLeaves(root->right);
}

// Function to print the right boundary (excluding leaf nodes)
void printRightBoundary(struct Node *root)
{
    struct Node *current = root;
    struct Node *stack[100]; 
    int top = -1;

    while (current)
    {
        if (!isLeaf(current))
        {
            stack[++top] = current; 
        }
        
        if (current->right)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    
    while (top >= 0)
    {
        printf("%d ", stack[top--]->data);
    }
}

// Function for boundary traversal of binary tree
void boundaryTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    
    if (!isLeaf(root))
    {
        printf("%d ", root->data);
    }

    
    printLeftBoundary(root->left);

    printLeaves(root);


    printRightBoundary(root->right);
}


int main()
{
    // Create a binary tree
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(8);
    root->right->right = newNode(6);
    root->right->right->right = newNode(9);

    printf("Boundary Traversal: ");
    boundaryTraversal(root);

    return 0;
}

// Output : 1 2 4 7 8 9 6 3