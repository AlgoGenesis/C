#include <stdio.h>
#include <stdlib.h>

#define MAX 4 // Maximum number of elements in a node

// Node structure for Unrolled Linked List
typedef struct Node {
    int count;          // Number of elements in the node
    int arr[MAX];      // Array to hold elements
    struct Node* next;  // Pointer to the next node
} Node;

// Unrolled Linked List structure
typedef struct {
    Node* head; // Head pointer for the list
} UnrolledLinkedList;

// Function to create a new node
Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->count = 0; // Initialize count
    newNode->next = NULL; // Initialize next pointer
    return newNode;
}

// Function to initialize the Unrolled Linked List
UnrolledLinkedList* createList() {
    UnrolledLinkedList* list = (UnrolledLinkedList*)malloc(sizeof(UnrolledLinkedList));
    list->head = NULL; // Initially, the list is empty
    return list;
}

// Function to insert an element at the end of the list
void insert(UnrolledLinkedList* list, int value) {
    if (!list->head) {
        // If the list is empty, create a new node
        list->head = createNode();
        list->head->arr[0] = value;
        list->head->count = 1;
        return;
    }

    Node* current = list->head;

    // Traverse to the last node
    while (current->next) {
        current = current->next;
    }

    // If the last node has space, add the element
    if (current->count < MAX) {
        current->arr[current->count] = value;
        current->count++;
    } else {
        // Create a new node
        Node* newNode = createNode();
        // Move half of the elements to the new node
        for (int i = 0; i < MAX / 2; i++) {
            newNode->arr[i] = current->arr[MAX / 2 + i];
        }
        newNode->count = MAX / 2;

        current->count = MAX / 2; // Update the old node's count

        // Insert the new element in the appropriate node
        if (value < newNode->arr[0]) {
            // Insert at the beginning of the new node
            newNode->arr[0] = value;
            newNode->count++;
        } else {
            // Insert at the end of the current node
            current->arr[current->count] = value;
            current->count++;
        }

        current->next = newNode; // Link the new node
    }
}

// Function to delete an element from the list
void removeElement(UnrolledLinkedList* list, int value) {
    Node* current = list->head;
    Node* prev = NULL;

    // Traverse through the list to find the element
    while (current) {
        for (int i = 0; i < current->count; i++) {
            if (current->arr[i] == value) {
                // Shift elements left to delete the found element
                for (int j = i; j < current->count - 1; j++) {
                    current->arr[j] = current->arr[j + 1];
                }
                current->count--;

                // Handle underflow and merging of nodes if necessary
                if (current->count < MAX / 2 && prev) {
                    // Merge with previous node
                    for (int j = prev->count; j < MAX && j < prev->count + current->count; j++) {
                        prev->arr[j] = current->arr[j - prev->count];
                    }
                    prev->count += current->count;
                    prev->next = current->next; // Link the previous node to the next node
                    free(current); // Free memory
                }
                return; // Element removed
            }
        }
        prev = current;
        current = current->next; // Move to the next node
    }
    printf("Element not found: %d\n", value); // Element not found
}

// Function to display the list
void display(UnrolledLinkedList* list) {
    Node* current = list->head;
    while (current) {
        for (int i = 0; i < current->count; i++) {
            printf("%d ", current->arr[i]);
        }
        printf("| "); // Separator for nodes
        current = current->next; // Move to the next node
    }
    printf("\n");
}

// Main function to demonstrate the Unrolled Linked List
int main() {
    UnrolledLinkedList* ull = createList();

    insert(ull, 10);
    insert(ull, 20);
    insert(ull, 30);
    insert(ull, 40);
    insert(ull, 50); // This will cause a split

    printf("List after insertions: ");
    display(ull);

    removeElement(ull, 20);
    printf("List after removing 20: ");
    display(ull);

    removeElement(ull, 50);
    printf("List after removing 50: ");
    display(ull);

    removeElement(ull, 10);
    printf("List after removing 10: ");
    display(ull);

    // Free the allocated memory
    // (Freeing the whole list is omitted for brevity; add a cleanup function if necessary)

    return 0;
}
