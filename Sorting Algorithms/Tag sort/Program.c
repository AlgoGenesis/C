#include <stdio.h>

void tagSort(int arr[], int size) {
    int i, j;
    int tag[size];  // Array to store tags (indexes)

    // Initialize the tag array
    for (i = 0; i < size; i++) {
        tag[i] = i;
    }

    // Sort the tags based on the values in the original array
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[tag[i]] > arr[tag[j]]) {
                int temp = tag[i];
                tag[i] = tag[j];
                tag[j] = temp;
            }
        }
    }

    // Print the sorted array using the tag array
    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[tag[i]]);
    }
    printf("\n");
}

int main() {
    int size;

    // User input for the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    // User input for the elements of the array
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call the tag sort function
    tagSort(arr, size);

    return 0;
}
