//this is the code of bottom view traversal of tree. this is how a binary tree looks when we see it from bottom

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Structure to store a node along with its horizontal distance and height
struct Info
{
    struct Node *node;
    int hd;
    int height;
};

void bottomViewUtil(struct Node *root, struct Info bottomNodes[], int hd, int height)
{
    if (root == NULL)
        return;

    if (bottomNodes[hd].node == NULL || height >= bottomNodes[hd].height)
    {
        bottomNodes[hd].node = root;
        bottomNodes[hd].height = height;
    }

    bottomViewUtil(root->left, bottomNodes, hd - 1, height + 1);
    bottomViewUtil(root->right, bottomNodes, hd + 1, height + 1);
}

void bottomView(struct Node *root)
{
    struct Info bottomNodes[1000];
    for (int i = 0; i < 1000; i++)
    {
        bottomNodes[i].node = NULL;
        bottomNodes[i].hd = i;
        bottomNodes[i].height = INT_MIN;
    }

    int hd = 500; // Consider this as the middle index
    bottomViewUtil(root, bottomNodes, hd, 0);

    for (int i = 0; i < 1000; i++)
    {
        if (bottomNodes[i].node != NULL)
        {
            printf("%d ", bottomNodes[i].node->data);
        }
    }
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

    printf("Bottom view traversal is: \n");
    bottomView(root);

    return 0;
}
