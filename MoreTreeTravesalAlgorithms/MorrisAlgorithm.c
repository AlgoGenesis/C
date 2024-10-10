//This is the Morris algorithm code for In-order and Pre-Order Traversal in a Binary Tree.

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

// Morris Inorder Traversal
void morrisInorderTraversal(struct Node *root)
{
    struct Node *current = root;

    while (current != NULL)
    {
        
        if (current->left == NULL)
        {
            printf("%d ", current->data);
            current = current->right;
        }
        else
        {
            
            struct Node *predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            
            if (predecessor->right == NULL)
            {
                predecessor->right = current;
                current = current->left;
            }
            
            else
            {
                predecessor->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}

//Morris Pre-Order Traversal
void morrisPreorderTraversal(struct Node *root)
{
    struct Node *current = root;

    while (current != NULL)
    {
        
        if (current->left == NULL)
        {
            printf("%d ", current->data);
            current = current->right;
        }
        else
        {
            
            struct Node *predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            
            if (predecessor->right == NULL)
            {
                predecessor->right = current;
                printf("%d ", current->data); 
                current = current->left;
            }
            
            else
            {
                predecessor->right = NULL;
                current = current->right;
            }
        }
    }
}


int main()
{

    struct Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    printf("Morris In-Order Traversal: ");
    morrisInorderTraversal(root);
    printf("\n");
    printf("Morris Pre-Order Traversal: ");
    morrisPreorderTraversal(root);
    printf("\n");

    return 0;
}
