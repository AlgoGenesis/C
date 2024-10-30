#include <stdio.h>

void diagonalBoundarySpiral(int arr[][100], int rows, int cols) {
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    
    while (top <= bottom && left <= right) {
        // Top-left to bottom-right diagonal
        for (int i = top, j = left; i <= bottom && j <= right; i++, j++) {
            printf("%d ", arr[i][j]);
        }
        top++;  // Move top boundary down

        // Top-right to bottom-left diagonal
        for (int i = top, j = right; i <= bottom && j >= left; i++, j--) {
            printf("%d ", arr[i][j]);
        }
        right--;  // Move right boundary left

        if (top <= bottom) {
            // Bottom-right to top-left diagonal
            for (int i = bottom, j = right; i >= top && j >= left; i--, j--) {
                printf("%d ", arr[i][j]);
            }
            bottom--;  // Move bottom boundary up
        }

        if (left <= right) {
            // Bottom-left to top-right diagonal
            for (int i = bottom, j = left; i >= top && j <= right; i--, j++) {
                printf("%d ", arr[i][j]);
            }
            left++;  // Move left boundary right
        }
    }
}

int main() {
    int arr[100][100], rows, cols;

    // Input dimensions of the 2D array
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input elements of the 2D array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Perform diagonal boundary spiral traversal
    printf("Diagonal Boundary Spiral Traversal: ");
    diagonalBoundarySpiral(arr, rows, cols);

    return 0;
}
