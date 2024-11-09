#include <stdio.h>
#include <stdlib.h>

// Circular array structure
struct CircularArray {
    int *arr;       // Pointer to the dynamically allocated array
    int head;       // Points to the start of the array
    int tail;       // Points to the end of the array
    int count;      // Tracks the number of elements
    int size;       // Size of the circular array (user-defined)
};

// Initialize the circular array
void initialize(struct CircularArray *ca, int size) {
    ca->arr = (int *)malloc(size * sizeof(int));
    ca->size = size;
    ca->head = 0;
    ca->tail = 0;
    ca->count = 0;
}

// Insert an element into the circular array
int insert(struct CircularArray *ca, int value) {
    if (ca->count == ca->size) {
        printf("Circular array is full!\n");
        return -1;
    }
    ca->arr[ca->tail] = value;
    ca->tail = (ca->tail + 1) % ca->size;
    ca->count++;
    return 0;
}

// Retrieve an element from the circular array
int retrieve(struct CircularArray *ca) {
    if (ca->count == 0) {
        printf("Circular array is empty!\n");
        return -1;
    }
    int value = ca->arr[ca->head];
    ca->head = (ca->head + 1) % ca->size;
    ca->count--;
    return value;
}

// Display elements in the circular array
void display(struct CircularArray *ca) {
    if (ca->count == 0) {
        printf("Circular array is empty!\n");
        return;
    }
    int i = ca->head;
    for (int j = 0; j < ca->count; j++) {
        printf("%d ", ca->arr[i]);
        i = (i + 1) % ca->size;
    }
    printf("\n");
}

// Free the dynamically allocated memory for the array
void cleanup(struct CircularArray *ca) {
    free(ca->arr);
}

int main() {
    struct CircularArray ca;
    int size, choice, value;

    printf("Enter the size of the circular array: ");
    scanf("%d", &size);
    initialize(&ca, size);

    while (1) {
        printf("\n1. Insert\n2. Retrieve\n3. Display\n4. Exit\nChoose an operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&ca, value);
                break;
            case 2:
                value = retrieve(&ca);
                if (value != -1) {
                    printf("Retrieved value: %d\n", value);
                }
                break;
            case 3:
                printf("Circular Array elements: ");
                display(&ca);
                break;
            case 4:
                cleanup(&ca);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
