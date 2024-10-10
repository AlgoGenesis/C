// this is the code of reverse level order tree traversal. this code stores the tree elements in level order and then prints it by poping out.

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


void reverseLevelOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    
    struct Node **queue = (struct Node **)malloc(100 * sizeof(struct Node *));
    int front = 0, rear = 0;

    
    struct Node **stack = (struct Node **)malloc(100 * sizeof(struct Node *));
    int top = -1;

    
    queue[rear++] = root;

    
    while (front != rear)
    {
        
        struct Node *currentNode = queue[front++];

        
        stack[++top] = currentNode;

        
        if (currentNode->right != NULL)
        {
            queue[rear++] = currentNode->right;
        }


        if (currentNode->left != NULL)
        {
            queue[rear++] = currentNode->left;
        }
    }

    
    while (top >= 0)
    {
        printf("%d ", stack[top--]->data);
    }

    
    free(queue);
    free(stack);
}


int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Reverse Level Order Traversal: ");
    reverseLevelOrder(root);

    return 0;
}
