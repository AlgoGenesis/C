// Deque: Key Concepts
// Definition:

// A deque (double-ended queue) is a linear data structure that allows insertion and deletion of elements from both ends (front and rear), following a First In First Out (FIFO) principle, but with greater flexibility.

// Implementation:

// Can be implemented using arrays or linked lists.
// Uses two pointers (front and rear) to manage the ends of the deque.
// Advantages:

// Flexibility in managing data, allowing efficient access and modifications at both ends.
// Suitable for applications that require quick access to both the front and rear elements.
// Disadvantages:

// Complexity in implementation compared to simple queues or stacks, especially with circular deques.
// Requires careful handling of pointers to avoid confusion between empty and full states.
// Applications:

// Task scheduling (e.g., in operating systems).
// Undo mechanisms in applications (like text editors).
// Sliding window problems in algorithms.
// Managing buffers in data streams.
// Complexity:

// Time Complexity:
// Insert Front: O(1)
// Insert Rear: O(1)
// Delete Front: O(1)
// Delete Rear: O(1)
// Peek Front: O(1)
// Peek Rear: O(1)
// Space Complexity: O(n) for n elements in the deque.


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 5 // Maximum size of the deque

struct Deque {
    int items[MAX];
    int front;
    int rear;
};

// Function to initialize the deque
void initializeDeque(struct Deque* d) {
    assert(d != NULL);
    d->front = -1;
    d->rear = -1; // Deque is empty
}

// Function to check if the deque is full
int isFull(struct Deque* d) {
    return (d->front == (d->rear + 1) % MAX);
}

// Function to check if the deque is empty
int isEmpty(struct Deque* d) {
    return (d->front == -1);
}

// Function to insert an element at the front
void insertFront(struct Deque* d, int value) {
    assert(d != NULL);
    if (isFull(d)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(d)) {
        d->front = d->rear = 0; // Initialize front and rear
    } else {
        d->front = (d->front - 1 + MAX) % MAX; // Circular decrement
    }
    d->items[d->front] = value; // Add the value
    printf("Inserted at front: %d\n", value);
}

// Function to insert an element at the rear
void insertRear(struct Deque* d, int value) {
    assert(d != NULL);
    if (isFull(d)) {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(d)) {
        d->front = d->rear = 0; // Initialize front and rear
    } else {
        d->rear = (d->rear + 1) % MAX; // Circular increment
    }
    d->items[d->rear] = value; // Add the value
    printf("Inserted at rear: %d\n", value);
}

// Function to delete an element from the front
int deleteFront(struct Deque* d) {
    assert(d != NULL);
    if (isEmpty(d)) {
        printf("Deque is empty!\n");
        return -1; // Indicating the deque is empty
    }
    int value = d->items[d->front];
    if (d->front == d->rear) {
        d->front = -1; // Deque is now empty
        d->rear = -1;
    } else {
        d->front = (d->front + 1) % MAX; // Circular increment
    }
    return value; // Return deleted value
}

// Function to delete an element from the rear
int deleteRear(struct Deque* d) {
    assert(d != NULL);
    if (isEmpty(d)) {
        printf("Deque is empty!\n");
        return -1; // Indicating the deque is empty
    }
    int value = d->items[d->rear];
    if (d->front == d->rear) {
        d->front = -1; // Deque is now empty
        d->rear = -1;
    } else {
        d->rear = (d->rear - 1 + MAX) % MAX; // Circular decrement
    }
    return value; // Return deleted value
}

// Function to display the deque
void display(struct Deque* d) {
    assert(d != NULL);
    if (isEmpty(d)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = d->front;
    while (1) {
        printf("%d ", d->items[i]);
        if (i == d->rear) {
            break;
        }
        i = (i + 1) % MAX; // Circular increment
    }
    printf("\n");
}

int main() {
    struct Deque d;
    initializeDeque(&d);
    int choice, value;

    do {
        printf("\nDeque Menu:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert at front: ");
                scanf("%d", &value);
                insertFront(&d, value);
                break;
            case 2:
                printf("Enter a value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&d, value);
                break;
            case 3:
                value = deleteFront(&d);
                if (value != -1) {
                    printf("Deleted from front: %d\n", value);
                }
                break;
            case 4:
                value = deleteRear(&d);
                if (value != -1) {
                    printf("Deleted from rear: %d\n", value);
                }
                break;
            case 5:
                display(&d);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
