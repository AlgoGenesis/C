#include <stdio.h>

#define MAX 100

typedef struct {
    int value;
    int priority;
} PriorityQueueElement;

PriorityQueueElement pq[MAX];
int size = 0;

// Function to insert an element with a given priority
void insert(int value, int priority) {
    if (size >= MAX) {
        printf("Priority Queue is full!\n");
        return;
    }
    pq[size].value = value;
    pq[size].priority = priority;
    size++;
}

// Function to find the index of the highest priority element
int findHighestPriority() {
    int highestPriorityIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i].priority > pq[highestPriorityIndex].priority) {
            highestPriorityIndex = i;
        }
    }
    return highestPriorityIndex;
}

// Function to remove and return the highest priority element
int removeHighestPriority() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    int index = findHighestPriority();
    int value = pq[index].value;

    // Shift elements to fill the removed element's spot
    for (int i = index; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;

    return value;
}

// Function to display the priority queue
void display() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < size; i++) {
        printf("Value: %d, Priority: %d\n", pq[i].value, pq[i].priority);
    }
}

int main() {
    int choice, value, priority;

    while (1) {
        printf("\nPriority Queue Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Remove highest priority element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter priority: ");
                scanf("%d", &priority);
                insert(value, priority);
                break;
            case 2:
                value = removeHighestPriority();
                if (value != -1) {
                    printf("Removed element with highest priority: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
