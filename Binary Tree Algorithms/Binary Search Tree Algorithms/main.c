#include <stdio.h>
#include <stdlib.h>


typedef struct bst_node
{
    int key;                      
    struct bst_node *left;       
    struct bst_node *right;      
} bst_node;


bst_node *create_node(int key)
{

    bst_node *new_node = (bst_node *)malloc(sizeof(bst_node));
    new_node->key = key;          
    new_node->left = NULL;        
    new_node->right = NULL;       
    return new_node;              
}

// Function to insert a new key into the BST
void insertion(bst_node **root, int key)
{
    bst_node *temp = *root; // Start with the root of the tree
    // If tree is empty, create the root node
    if (temp == NULL)
    {
        bst_node *new_root = create_node(key);
        (*root) = new_root; // Set the root to the new node
        return;
    }
    
    bst_node *parent = temp; // Keep track of the parent node
    while (temp)
    {
        // Navigate through the tree to find the correct position
        if (temp->key > key)
        {
            parent = temp;
            temp = temp->left; // Go left
        }
        else if (temp->key < key)
        {
            parent = temp;
            temp = temp->right; // Go right
        }
        else
        {
            // Duplicate keys are not allowed in this BST
            return;
        }
    }
    
    // Create a new node and link it to the parent
    bst_node *new_node = create_node(key);
    if (parent->key > key)
    {
        parent->left = new_node; // Insert as left child
    }
    else
    {
        parent->right = new_node; // Insert as right child
    }
    printf("Insertion of %d is complete.\n", key);
}

// Function to search for a key in the BST
void search(bst_node *root, int key)
{
    while (root)
    {
        // Navigate through the tree to find the key
        if (root->key > key)
        {
            root = root->left; // Go left
        }
        else if (root->key < key)
        {
            root = root->right; // Go right
        }
        else
        {
            printf("%d found.\n", key); // Key found
            return;
        }
    }
    printf("%d not found.\n", key); // Key not found
}

// Function to perform inorder traversal of the BST
void inorder(bst_node *root)
{
    if (root)
    {
        inorder(root->left);        // Traverse left subtree
        printf("%d ", root->key);  // Visit the node
        inorder(root->right);       // Traverse right subtree
    }
}

// Function to find the inorder successor of a node
bst_node *successor(bst_node *node)
{
    node = node->right; // Move to the right child
    // Find the leftmost node in the right subtree
    while (node != NULL && node->left != NULL)
    {
        node = node->left;
    }
    return node; // Return the inorder successor
}

// Function to delete a key from the BST
bst_node *deletion(bst_node *root, int key, int *flag)
{
    // Base case: if the tree is empty
    if (root == NULL)
    {
        return root;
    }
    
    // Navigate the tree to find the node to delete
    if (root->key > key)
    {
        root->left = deletion(root->left, key, flag);
    }
    else if (root->key < key)
    {
        root->right = deletion(root->right, key, flag);
    }
    else
    {
        (*flag) = 1; // Key found, set flag
        // Node with only one child or no child
        if (root->left == NULL)
        {
            bst_node *temp = root->right; // Get the right child
            free(root); // Free the current node
            return temp; // Return the right child
        }
        if (root->right == NULL)
        {
            bst_node *temp = root->left; // Get the left child
            free(root); // Free the current node
            return temp; // Return the left child
        }
        // Node with two children: get the inorder successor
        bst_node *succ = successor(root);
        root->key = succ->key; // Replace key with successor's key
        root->right = deletion(root->right, succ->key, flag); // Delete the successor
    }
    return root; // Return the modified tree
}

// Main function to interact with the user
int main()
{
    bst_node *root = NULL; // Initialize the root of the BST
    printf("i for insertion\nd for deletion\ns for search\no for inorder display\nq for quitting\n");

    while (1)
    {
        char x; // Variable to store user choice
        scanf("%c", &x); // Read user input (space before %c to ignore whitespace)
        
        // Handle insertion
        if (x == 'i')
        {
            int n;
            printf("Enter the key you want to insert: ");
            scanf("%d", &n);
            insertion(&root, n); // Call insertion function
        }
        // Handle deletion
        else if (x == 'd')
        {
            int n;
            printf("Enter the key you want to delete: ");
            scanf("%d", &n);
            int flag = 0; // Flag to check if deletion was successful
            root = deletion(root, n, &flag); // Call deletion function
            if (flag == 1)
                printf("Deletion of %d was successful.\n", n);
            else
                printf("Deletion of %d wasn't successful.\n", n);
        }
        // Handle search
        else if (x == 's')
        {
            int n;
            printf("Enter the key you want to look-up: ");
            scanf("%d", &n);
            search(root, n); // Call search function
        }
        // Handle inorder display
        else if (x == 'o')
        {
            inorder(root); // Call inorder function
            printf("\n");
        }
        // Handle exit
        else if (x == 'q')
        {
            printf("Exiting...\n");
            break; // Exit the loop
        }
    }
    return 0; // Exit the program
}
