#include <stdio.h>
#include <stdlib.h>

// Structure of a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if patternList is a sublist of mainList
int isSublist(struct Node* mainList, struct Node* patternList) {
    struct Node *mainPtr, *patternPtr;

    // Traverse the main list
    while (mainList != NULL) {
        // Initialize pointers for pattern and main list
        mainPtr = mainList;
        patternPtr = patternList;

        // Traverse both lists while they match
        while (mainPtr != NULL && patternPtr != NULL && mainPtr->data == patternPtr->data) {
            mainPtr = mainPtr->next;
            patternPtr = patternPtr->next;
        }

        // If patternPtr reaches NULL, all nodes of patternList have matched
        if (patternPtr == NULL) {
            return 1;  // Pattern list found as a sublist
        }

        // Move to the next node in mainList
        mainList = mainList->next;
    }

    return 0;  // Pattern list is not a sublist
}

// Utility function to print a linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the sublist search algorithm
int main() {
    // Create the main linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* mainList = createNode(1);
    mainList->next = createNode(2);
    mainList->next->next = createNode(3);
    mainList->next->next->next = createNode(4);
    mainList->next->next->next->next = createNode(5);

    // Create the pattern linked list: 3 -> 4
    struct Node* patternList = createNode(3);
    patternList->next = createNode(4);

    // Print the main list and the pattern list
    printf("Main List: ");
    printList(mainList);
    printf("Pattern List: ");
    printList(patternList);

    // Check if patternList is a sublist of mainList
    if (isSublist(mainList, patternList)) {
        printf("Pattern list is a sublist of the main list.\n");
    } else {
        printf("Pattern list is not a sublist of the main list.\n");
    }

    return 0;
}

