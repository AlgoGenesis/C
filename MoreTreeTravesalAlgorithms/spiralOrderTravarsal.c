//In this type of Tree Traversal, first level will be printed left to right and then second level right to left and third level left to right and so on.
//This is also known as Zig-Zag Order Traversal.

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


struct Stack
{
    int top;
    int capacity;
    struct Node **array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (struct Node **)malloc(stack->capacity * sizeof(struct Node *));
    return stack;
}


int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}


void push(struct Stack *stack, struct Node *node)
{
    stack->array[++stack->top] = node;
}


struct Node *pop(struct Stack *stack)
{
    return stack->array[stack->top--];
}


void spiralOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

  
    struct Stack *stack1 = createStack(100); 
    struct Stack *stack2 = createStack(100); 

   
    push(stack1, root);

    
    while (!isEmpty(stack1) || !isEmpty(stack2))
    {

        
        while (!isEmpty(stack1))
        {
            struct Node *temp = pop(stack1);
            printf("%d ", temp->data);

            
            if (temp->left)
                push(stack2, temp->left);
            if (temp->right)
                push(stack2, temp->right);
        }

        
        while (!isEmpty(stack2))
        {
            struct Node *temp = pop(stack2);
            printf("%d ", temp->data);

            
            if (temp->right)
                push(stack1, temp->right);
            if (temp->left)
                push(stack1, temp->left);
        }
    }
}


int main()
{
    // Create a binary tree
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(12);
    root->right->right->right = newNode(13);
    root->right->left->right = newNode(67);
    root->right->left->left = newNode(56);
    root->left->left->left = newNode(14);
    root->left->left->right = newNode(15);
    root->left->right->right = newNode(17);
    root->left->right->left = newNode(16);

    printf("Spiral Order Traversal: ");
    spiralOrderTraversal(root);

    return 0;
}

// The Output of this code will be: 1 3 2 4 5 6 7 13 12 67 56 17 16 15 14