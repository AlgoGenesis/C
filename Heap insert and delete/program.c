#include <stdio.h>

#define MAX_SIZE 50

int heap[MAX_SIZE], heapSize = 0;

// Function to insert an element into the heap
int insertHeap(int heap[], int heapSize, int value) {
    if (heapSize >= MAX_SIZE - 1) {
        printf("Heap is full. Cannot insert %d.\n", value);
        return heapSize;  // Return unchanged size
    }

    // Insert the new value at the end of the heap
    heapSize++;
    heap[heapSize] = value;

    // Heapify up
    int i = heapSize;
    while (i > 1) {
        int parent = i / 2;
        if (heap[parent] < heap[i]) {
            // Swap parent and current node
            int temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;  // Move up the tree
        } else {
            break;  // The heap property is satisfied
        }
    }
    return heapSize;  // Return new heap size
}

// Function to delete the root of the heap
int deleteRoot(int heap[], int heapSize) {
    if (heapSize == 0) {
        printf("Heap is empty. Cannot delete from an empty heap.\n");
        return heapSize;  // Return unchanged size
    }

    // Replace the root with the last element
    heap[1] = heap[heapSize];  // Move last element to root
    heapSize--;  // Decrease the size of the heap

    // Heapify down
    int ptr = 1;  // Start from the root
    while (ptr <= heapSize / 2) {  // Only need to check non-leaf nodes
        int left = 2 * ptr;
        int right = 2 * ptr + 1;
        int largerChild = left;  // Assume left child is larger

        // Check if the right child exists and is larger
        if (right <= heapSize && heap[right] > heap[left]) {
            largerChild = right;
        }

        // If the parent is smaller than the larger child, swap
        if (heap[ptr] < heap[largerChild]) {
            int temp = heap[ptr];
            heap[ptr] = heap[largerChild];
            heap[largerChild] = temp;
            ptr = largerChild;  // Move down the tree
        } else {
            break;  // The heap property is satisfied
        }
    }
    printf("Root node deleted\n");
    return heapSize;  // Return new heap size
}

// Function to display the heap
void displayHeap(int heap[], int heapSize) {
    if (heapSize == 0) {
        printf("Heap is empty.\n");
    } else {
        printf("The heap is:");
        for (int j = 1; j <= heapSize; j++) {
            printf(" %d", heap[j]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\n*** MAIN MENU ***");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to be inserted in the heap: ");
                scanf("%d", &value);
                heapSize = insertHeap(heap, heapSize, value);
                break;
            case 2:
                heapSize = deleteRoot(heap, heapSize);
                break;
            case 3:
                displayHeap(heap, heapSize);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
