#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Define the structure for the tree node (BST)
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new list node
struct ListNode* createListNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new tree node
struct TreeNode* createTreeNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the size of the linked list
int getListSize(struct ListNode* head) {
    int size = 0;
    while (head) {
        size++;
        head = head->next;
    }
    return size;
}

// Function to convert the linked list to a balanced BST
struct TreeNode* sortedListToBSTHelper(struct ListNode** headRef, int size) {
    if (size <= 0) {
        return NULL;
    }

    // Recursively build the left subtree
    struct TreeNode* left = sortedListToBSTHelper(headRef, size / 2);

    // The middle node will be the root of the current subtree
    struct TreeNode* root = createTreeNode((*headRef)->val);
    root->left = left;

    // Move the head pointer to the next node in the list
    *headRef = (*headRef)->next;

    // Recursively build the right subtree
    root->right = sortedListToBSTHelper(headRef, size - size / 2 - 1);

    return root;
}

// Function to convert the sorted linked list to a balanced BST
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int size = getListSize(head);
    return sortedListToBSTHelper(&head, size);
}

// In-order traversal of the binary search tree (for testing)
void inorderTraversal(struct TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

// Helper function to create a sorted linked list
struct ListNode* createLinkedList(int arr[], int size) {
    struct ListNode* head = NULL;
    struct ListNode* temp = NULL;
    for (int i = 0; i < size; i++) {
        struct ListNode* newNode = createListNode(arr[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

int main() {
    // Example sorted linked list: [-10, -3, 0, 5, 9]
    int arr[] = {-10, -3, 0, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Create the linked list from the array
    struct ListNode* head = createLinkedList(arr, size);
    
    // Convert the sorted linked list to a balanced BST
    struct TreeNode* root = sortedListToBST(head);

    // Print the in-order traversal of the tree
    printf("In-order traversal of the balanced BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

