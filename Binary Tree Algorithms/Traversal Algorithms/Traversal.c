#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to perform inorder traversal
void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    // Recur on the left subtree
    inorderTraversal(root->left);

    // Visit the current node
    printf("%d ", root->data);

    // Recur on the right subtree
    inorderTraversal(root->right);
}
// Function to perform preorder traversal
void preorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    // Visit the current node
    printf("%d ", root->data);

    // Recur on the left subtree
    preorderTraversal(root->left);

    // Recur on the right subtree
    preorderTraversal(root->right);
}

// Function to perform postorder traversal
void postorderTraversal(struct Node *node)
{
    if (node == NULL)
        return;

    // Recur on the left subtree
    postorderTraversal(node->left);

    // Recur on the right subtree
    postorderTraversal(node->right);

    // Visit the current node
    printf("%d ", node->data);
}

struct QNode
{
    struct Node *tNode;
    struct QNode *next;
};

struct QNode *front = NULL;
struct QNode *rear = NULL;
void enqueue(struct Node *tNode);
struct Node *dequeue();


void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front != NULL)
    {
        struct Node *curr = dequeue();
        printf("%d ", curr->data);
        if (curr->left != NULL)
            enqueue(curr->left);
        if (curr->right != NULL)
            enqueue(curr->right);
    }
}

struct QNode *newQNode(struct Node *tNode)
{
    struct QNode *qNode =
        (struct QNode *)malloc(sizeof(struct QNode));
    qNode->tNode = tNode;
    qNode->next = NULL;
    return qNode;
}
void enqueue(struct Node *tNode)
{
    struct QNode *qNode = newQNode(tNode);

    if (rear == NULL)
    {
        front = rear = qNode;
    }
    else
    {
        rear->next = qNode;
        rear = qNode;
    }
}
struct Node *dequeue()
{
    if (front == NULL)
        return NULL;
    struct Node *tNode = front->tNode;
    struct QNode *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    return tNode;
}

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *node =
        (struct Node *)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    //Tree Representation
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5


    printf("\n\n");
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n\n");
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n\n");
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n\n");
    printf("Level order traversal: ");
    levelOrderTraversal(root);
    printf("\n\n");
    return 0;
}
