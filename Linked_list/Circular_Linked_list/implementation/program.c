#include <stdio.h>
#include <stdlib.h>

// Definition of a structure to represent a node in the circular linked list
struct Node {
    int data;               // Integer data to store the value in the node
    struct Node* next;      // Pointer to the next node in the list
};

// Function to display the elements of the circular linked list
void display(struct Node* head) {
    struct Node* temp = head;

    if (head != NULL) {
        do {
            printf(" %d -> ", temp->data);  // Print the data of the current node
            temp = temp->next;           // Move to the next node
        } while (temp != head);           // Stop when we come back to the head
        printf("(Back to head)\n");
        
    }
}

int main() {
    // Pointers to the nodes in the circular linked list
    struct Node* first;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // Allocate memory for four nodes in the circular linked list
    first = (struct Node*)malloc(sizeof(struct Node));    // First node
    second = (struct Node*)malloc(sizeof(struct Node));   // Second node
    third = (struct Node*)malloc(sizeof(struct Node));    // Third node
    fourth = (struct Node*)malloc(sizeof(struct Node));   // Fourth node

    // Assign data to each node
    first->data = 5;        // Assign 5 to the first node
    second->data = 10;      // Assign 10 to the second node
    third->data = 15;       // Assign 15 to the third node
    fourth->data = 20;      // Assign 20 to the fourth node

    // Link the nodes to form a circular linked list
    first->next = second;   // First node points to second
    second->next = third;   // Second node points to third
    third->next = fourth;   // Third node points to fourth
    fourth->next = first;   // Fourth node points back to the first node (circular)

    // Call the display function to print the circular linked list
    display(first);

    return 0;  // Return 0 to indicate successful execution
}
