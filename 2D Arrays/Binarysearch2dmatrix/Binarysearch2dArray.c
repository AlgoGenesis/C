#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* matrix, int rows, int cols, int target) {
    int left = 0;
    int right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid];

        if (midValue == target) {
            return 1;  // Element found
        }
        else if (midValue < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return 0;  // Element not found
}

int main() {
    int rows, cols;

    // User-defined dimensions for the matrix
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the matrix
    int* matrix = (int*)malloc(rows * cols * sizeof(int));
    if (matrix == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements into the matrix
    printf("Enter the elements of the matrix in sorted order:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i * cols + j]);
        }
    }

    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    if (binarySearch(matrix, rows, cols, target)) {
        printf("Element %d found in the matrix.\n", target);
    } else {
        printf("Element %d not found in the matrix.\n", target);
    }

    // Free allocated memory
    free(matrix);

    return 0;
}
