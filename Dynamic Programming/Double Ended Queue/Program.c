#include <stdio.h>
#include <stdbool.h>

#define N 5 // Maximum size of the deque

typedef struct Deque {
    int items[N];
    int front;
    int rear;
} Deque;

// Function to initialize the deque
void initialize(Deque* deque) {
    deque->front = -1;
    deque->rear = 0;
}

// Function to check if the deque is full
bool isFull(Deque* deque) {
    return ((deque->front == 0 && deque->rear == N - 1) || (deque->front == deque->rear + 1));
}

// Function to check if the deque is empty
bool isEmpty(Deque* deque) {
    return (deque->front == -1);
}

// Function to insert an element at the front of the deque
void insertFront(Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Overflow: Cannot insert %d at front\n", value);
        return;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = N - 1;
    } else {
        deque->front--;
    }
    deque->items[deque->front] = value;
}

// Function to insert an element at the rear of the deque
void insertRear(Deque* deque, int value) {
    if (isFull(deque)) {
        printf("Overflow: Cannot insert %d at rear\n", value);
        return;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == N - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    deque->items[deque->rear] = value;
}

// Function to delete an element from the front of the deque
void deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Underflow: Cannot delete from front\n");
        return;
    }
    int deletedValue = deque->items[deque->front];
    printf("Deleted from front: %d\n", deletedValue);
    
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == N - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
}

// Function to delete an element from the rear of the deque
void deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Underflow: Cannot delete from rear\n");
        return;
    }
    int deletedValue = deque->items[deque->rear];
    printf("Deleted from rear: %d\n", deletedValue);
    
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = N - 1;
    } else {
        deque->rear--;
    }
}

// Function to display the elements of the deque
void display(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    
    printf("Deque elements: ");
    if (deque->rear >= deque->front) {
        for (int i = deque->front; i <= deque->rear; i++) {
            printf("%d ", deque->items[i]);
        }
    } else {
        for (int i = deque->front; i < N; i++) {
            printf("%d ", deque->items[i]);
        }
        for (int i = 0; i <= deque->rear; i++) {
            printf("%d ", deque->items[i]);
        }
    }
    printf("\n");
}

// Main function to demonstrate the deque operations
int main() {
    Deque deque;
    initialize(&deque);

    insertRear(&deque, 10);
    insertRear(&deque, 20);
    insertFront(&deque, 5);
    insertFront(&deque, 1);
    display(&deque); // Should display: 1 5 10 20

    deleteFront(&deque);
    display(&deque); // Should display: 5 10 20

    deleteRear(&deque);
    display(&deque); // Should display: 5 10

    insertRear(&deque, 30);
    display(&deque); // Should display: 5