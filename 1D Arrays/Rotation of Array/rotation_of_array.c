#include <stdio.h>

// Fucntion to rotate the Array with required position and direction
void rotateArray(int arr[], int n, int positions, char direction) {
    int temp[n];

    if (direction == 'L' || direction == 'l') {
        // Left rotation
        for (int i = 0; i < n; i++) {
            temp[i] = arr[(i + positions) % n];
        }
    } else if (direction == 'R' || direction == 'r') {
        // Right rotation
        for (int i = 0; i < n; i++) {
            temp[i] = arr[(i - positions + n) % n];
        }
    } else {
        printf("Invalid direction! Use 'L' for left or 'R' for right.\n");
        return;
    }

    // Copy temp array back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

// Fucntion to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, positions;
    char direction;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of positions to rotate: ");
    scanf("%d", &positions);

    printf("Enter the direction (L for left, R for right): ");
    scanf(" %c", &direction);

    // Normalize positions to handle larger values than the array size
    positions = positions % n;

    // Before Rotation
    printf("Array before rotation:\n");
    printArray(arr, n);

    rotateArray(arr, n, positions, direction);

    // After Rotation
    printf("Array after rotation:\n");
    printArray(arr, n);

    return 0;
}
