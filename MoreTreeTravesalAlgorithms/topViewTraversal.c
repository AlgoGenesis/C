//this is the code of top view traversal. it deomonstrate how a tree looks from the top 

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

// Structure to store a node along with its horizontal distance
struct Info
{
    struct Node *node;
    int hd;
    int height;
};

void topViewUtil(struct Node *root, struct Info topNodes[], int hd, int height)
{
    if (root == NULL)
        return;

    if (topNodes[hd].node == NULL || height < topNodes[hd].height)
    {
        topNodes[hd].node = root;
        topNodes[hd].height = height;
    }

    topViewUtil(root->left, topNodes, hd - 1, height + 1);
    topViewUtil(root->right, topNodes, hd + 1, height + 1);
}

void topView(struct Node *root)
{
    struct Info topNodes[1000];
    for (int i = 0; i < 1000; i++)
    {
        topNodes[i].node = NULL;
        topNodes[i].hd = i;
        topNodes[i].height = INT_MAX;
    }

    int hd = 500; // Consider this as the middle index
    topViewUtil(root, topNodes, hd, 0);

    for (int i = 0; i < 1000; i++)
    {
        if (topNodes[i].node != NULL)
        {
            printf("%d ", topNodes[i].node->data);
        }
    }
}

// Main function to test the algorithm
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Top view traversal is: \n");
    topView(root);

    return 0;
}
