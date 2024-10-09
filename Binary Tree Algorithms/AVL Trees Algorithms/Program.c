#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef struct avl_node
{
    int value;                
    struct avl_node *left;    
    struct avl_node *right;   
    int height;              
} avl_node;


avl_node *create_node(int value)
{
    avl_node *new_node = (avl_node *)malloc(sizeof(avl_node)); 
    new_node->value = value;          
    new_node->height = 1;             
    new_node->left = NULL;           
    new_node->right = NULL;           
    return new_node;                 
}


int max(int a, int b)
{
    return a > b ? a : b; // Return the greater of a or b
}

// Function to calculate the height of a node
int height(avl_node *node)
{
    if (node == NULL)
        return 0; // If node is NULL, height is 0
    else
    {
        // Recursively calculate the height of the left and right subtrees
        int left_height = height(node->left);
        int right_height = height(node->right);
        return max(left_height, right_height) + 1; // Height is max of left and right heights + 1
    }
}

// Function to calculate the balance factor of a node
int get_balance_factor(avl_node *node)
{
    if (node == NULL)
        return 0; // Balance factor is 0 for NULL nodes
    return height(node->left) - height(node->right); // Balance factor = left height - right height
}

// Left-Left rotation (single rotation)
avl_node *rotate_left(avl_node *node)
{
    avl_node *right_node = node->right; // Store the right child
    node->right = right_node->left;      // Perform rotation
    right_node->left = node;              // Child becomes new root
    // Update heights of the rotated nodes
    node->height = max(height(node->right), height(node->left)) + 1;
    right_node->height = max(height(right_node->right), height(right_node->left)) + 1;
    return right_node; // Return new root
}

// Right-Right rotation (single rotation)
avl_node *rotate_right(avl_node *node)
{
    avl_node *left_node = node->left; // Store the left child
    node->left = left_node->right;    // Perform rotation
    left_node->right = node;          // Child becomes new root
    // Update heights of the rotated nodes
    node->height = max(height(node->right), height(node->left)) + 1;
    left_node->height = max(height(left_node->right), height(left_node->left)) + 1;
    return left_node; // Return new root
}

// Function to insert a value into the AVL tree
avl_node *insert_value(avl_node *root, int value)
{
    // If the tree is empty, create a new node
    if (root == NULL)
    {
        return create_node(value);
    }

    // Insert recursively in the appropriate subtree
    if (value < root->value)
    {
        root->left = insert_value(root->left, value); // Insert in left subtree
    }
    else if (value > root->value)
    {
        root->right = insert_value(root->right, value); // Insert in right subtree
    }
    else
    {
        return root; // Duplicate values are not allowed
    }

    // Update the height of the ancestor node
    root->height = max(height(root->right), height(root->left)) + 1;

    // Get the balance factor of this ancestor node
    int balance_factor = get_balance_factor(root);

    // Perform rotations if the node becomes unbalanced
    // Left heavy
    if (balance_factor > 1)
    {
        // Left-Right case
        if (get_balance_factor(root->left) < 0)
        {
            root->left = rotate_left(root->left); // Perform left rotation on left child
        }
        return rotate_right(root); // Perform right rotation on current node
    }
    // Right heavy
    else if (balance_factor < -1)
    {
        // Right-Left case
        if (get_balance_factor(root->right) > 0)
        {
            root->right = rotate_right(root->right); // Perform right rotation on right child
        }
        return rotate_left(root); // Perform left rotation on current node
    }

    return root; // Return the (potentially) new root of the subtree
}

// Function to search for a value in the AVL tree
void search_value(avl_node *root, int value)
{
    while (root)
    {
        // Navigate through the tree to find the value
        if (root->value > value)
        {
            root = root->left; // Go left
        }
        else if (root->value < value)
        {
            root = root->right; // Go right
        }
        else
        {
            printf("%d found.\n", value); // Value found
            return;
        }
    }
    printf("%d not found.\n", value); // Value not found
}

// Function to find the inorder successor of a given node
avl_node *successor(avl_node *node)
{
    // Start from the right subtree
    avl_node *successor = node->right;
    // Keep going left to find the minimum value in the right subtree
    while (successor->left)
    {
        successor = successor->left;
    }
    return successor; // Return the inorder successor
}

// Function to delete a value from the AVL tree
avl_node *delete_value(avl_node *root, int value, int *is_deleted)
{
    // Base case: we have not found the required node
    if (root == NULL)
    {
        return root; // Value not found, return NULL
    }
    // Navigate through the tree to find the value
    if (value < root->value)
    {
        root->left = delete_value(root->left, value, is_deleted); // Go left
    }
    else if (value > root->value)
    {
        root->right = delete_value(root->right, value, is_deleted); // Go right
    }
    else // Value found
    {
        (*is_deleted) = 1; // Set flag indicating successful deletion
        // Node with only one child or no child
        if (root->left == NULL || root->right == NULL)
        {
            avl_node *child = root->left ? root->left : root->right; // Get the non-null child
            if (child == NULL)
            {
                root = NULL; // No children, delete the node
            }
            else
            {
                root = child; // One child, replace root with child
                free(child);  // Free the old node
            }
        }
        else // Node with two children
        {
            // Find inorder successor of root
            avl_node *succ = successor(root);
            // Copy the successor's value to the root
            root->value = succ->value;
            // Delete the successor from the right subtree
            root->right = delete_value(root->right, succ->value, is_deleted);
        }
    }

    // If the tree has only one node, return it
    if (root == NULL)
    {
        return root; // Tree is now empty
    }

    // Update the height of the current node
    root->height = max(height(root->left), height(root->right)) + 1;

    // Check balance and perform rotations if necessary
    int balance_factor = get_balance_factor(root);
    if (balance_factor > 1) // Left heavy
    {
        // Perform rotations
        if (get_balance_factor(root->left) < 0) // Left-Right case
        {
            root->left = rotate_left(root->left);
        }
        return rotate_right(root); // Left-Left case
    }
    else if (balance_factor < -1) // Right heavy
    {
        if (get_balance_factor(root->right) > 0) // Right-Left case
        {
            root->right = rotate_right(root->right);
        }
        return rotate_left(root); // Right-Right case
    }
    return root; // Return the (potentially) new root of the subtree
}

// Function to perform inorder traversal of the AVL tree
void inorder(avl_node *root)
{
    if (root)
    {
        inorder(root->left); // Traverse left subtree
        // Print the node value and its height
        printf("node val: %d | height: %d ", root->value, root->height);
        inorder(root->right); // Traverse right subtree
    }
}

// Main function to interact with the AVL tree
int main()
{
    avl_node *root = NULL; // Initialize the root of the AVL tree to NULL
    printf("i for insertion\nd for deletion\ns for search\no for inorder display\nq for quitting\n");

    while (1)
    {
        char x; 
        scanf("%c", &x); 
        if (x == 'i') 
        {
            int value;
            printf("Enter the key you want to insert: ");
            scanf("%d", &value);
            root = insert_value(root, value); // Insert the value
        }
        else if (x == 'd') 
        {
            int value;
            printf("Enter the key you want to delete: ");
            scanf("%d", &value);
            int is_deleted = 0; // Flag to track deletion success
            root = delete_value(root, value, &is_deleted); // Delete the value
            if (is_deleted)
                printf("Deletion of %d was successful.\n", value);
            else
                printf("Deletion of %d wasn't successful.\n", value);
        }
        else if (x == 's') 
        {
            int value;
            printf("Enter the key you want to look-up: ");
            scanf("%d", &value);
            search_value(root, value); // Search for the value
        }
        else if (x == 'o') 
        {
            inorder(root); // Display the inorder traversal
            printf("\n");
        }
        else if (x == 'q') 
        {
            printf("Exiting...\n");
            break;
        }
    }
    return 0; 
}
