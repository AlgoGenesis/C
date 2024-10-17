#include <stdio.h>
#include <stdlib.h>

struct node
{
  int element;
  struct node *left;
  struct node *right;
};

struct node *createNode(int val)
{
  struct node *Node = (struct node *)malloc(sizeof(struct node));
  Node->element = val;
  Node->left = NULL;
  Node->right = NULL;
  return Node;
}

void traversePostorder(struct node *root)
{
  if (root == NULL)
    return;
  traversePostorder(root->left);
  traversePostorder(root->right);
  printf("%d ", root->element);
}

struct node *insertNode(struct node *root, int val)
{
  if (root == NULL)
  {
    return createNode(val);
  }
  if (val < root->element)
  {
    root->left = insertNode(root->left, val);
  }
  else
  {
    root->right = insertNode(root->right, val);
  }
  return root;
}

int main()
{
  struct node *root = NULL;
  int n, value;

  printf("Enter the number of the  nodes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Enter value for node %d: ", i + 1);
    scanf("%d", &value);
    root = insertNode(root, value);
  }

  printf("\nThe Postorder traversal of the given binary tree is:\n");
  traversePostorder(root);
  printf("\n");

  return 0;
}
