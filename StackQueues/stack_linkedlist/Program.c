#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Function to add an element to the top of the stack.
void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow!\n");
        return;
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", val);
}

// Function to remove the top element from the stack.
void pop() {
    if (top == NULL) {
        printf("Stack underflow!\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped from stack.\n", temp->data);
    top = top->next;
    free(temp);
}

// Function to display all elements of the stack.
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to run the menu-driven program.
int main() {
    int choice, value;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
