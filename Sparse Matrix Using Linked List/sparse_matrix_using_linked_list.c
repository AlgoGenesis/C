// Sparse Matrix Using Linked List

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node 
{
    int row;
    int col;
    int value;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int row, int col, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node into the linked list
void insertNode(struct Node** head, int row, int col, int value) 
{
    struct Node* newNode = createNode(row, col, value);
    if (*head == NULL) 
    {
        *head = newNode;
    }
    else 
    {
        struct Node* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the sparse matrix
void displaySparseMatrix(struct Node* head, int rows, int cols)
{
    struct Node* temp = head;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (temp != NULL && temp->row == i && temp->col == j) 
            {
                printf("%d ", temp->value);
                temp = temp->next;
            }
            else 
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function to free the linked list memory
void freeList(struct Node* head) 
{
    struct Node* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() 
{
    int rows, cols;
    
    // Head of the linked list
    struct Node* sparseMatrix = NULL;
    
    // Input the number of rows and columns of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Input the elements of the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            int value;
            printf("Element at (%d, %d): ", i, j);
            scanf("%d", &value);
            // Insert only non-zero elements into the linked list
            if (value != 0) 
            {
                insertNode(&sparseMatrix, i, j, value);
            }
        }
    }

    // Display the sparse matrix
    printf("\nSparse Matrix Representation:\n");
    displaySparseMatrix(sparseMatrix, rows, cols);

    // Free the linked list memory
    freeList(sparseMatrix);

    return 0;
}
