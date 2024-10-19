#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/**
 * @brief Structure to hold matrix dimensions and elements
 */
typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

/**
 * @brief Create a new matrix with given dimensions
 * @param rows Number of rows
 * @param cols Number of columns
 * @return Matrix structure or NULL if allocation fails
 */
Matrix* createMatrix(int rows, int cols) {
    // Input validation
    if (rows <= 0 || cols <= 0) {
        return NULL;
    }

    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    if (!matrix) {
        return NULL;
    }

    matrix->rows = rows;
    matrix->cols = cols;
    
    // Allocate memory for rows
    matrix->data = (int**)malloc(rows * sizeof(int*));
    if (!matrix->data) {
        free(matrix);
        return NULL;
    }

    // Allocate memory for columns
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*)malloc(cols * sizeof(int));
        if (!matrix->data[i]) {
            // Clean up previously allocated memory
            for (int j = 0; j < i; j++) {
                free(matrix->data[j]);
            }
            free(matrix->data);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

/**
 * @brief Free the memory allocated for the matrix
 * @param matrix Pointer to the Matrix structure
 */
void destroyMatrix(Matrix* matrix) {
    if (!matrix) {
        return;
    }

    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

/**
 * @brief Traverse the matrix in spiral order and store results in an array
 * @param matrix Input matrix
 * @param result Array to store the spiral order traversal
 * @param resultSize Pointer to store the size of result array
 * @return true if successful, false otherwise
 */
bool spiralTraversal(const Matrix* matrix, int* result, int* resultSize) {
    // Input validation
    if (!matrix || !result || !resultSize || 
        matrix->rows <= 0 || matrix->cols <= 0) {
        return false;
    }

    int top = 0;
    int bottom = matrix->rows - 1;
    int left = 0;
    int right = matrix->cols - 1;
    int index = 0;

    *resultSize = matrix->rows * matrix->cols;

    while (top <= bottom && left <= right) {
        // Traverse right: Process top row
        for (int i = left; i <= right; i++) {
            result[index++] = matrix->data[top][i];
        }
        top++;

        // Traverse down: Process rightmost column
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix->data[i][right];
        }
        right--;

        // Check if there are more rows to process
        if (top <= bottom) {
            // Traverse left: Process bottom row
            for (int i = right; i >= left; i--) {
                result[index++] = matrix->data[bottom][i];
            }
            bottom--;
        }

        // Check if there are more columns to process
        if (left <= right) {
            // Traverse up: Process leftmost column
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix->data[i][left];
            }
            left++;
        }
    }

    // Verify that all elements were processed
    assert(index == *resultSize);
    return true;
}

/**
 * @brief Print the matrix in a readable format
 * @param matrix Input matrix
 */
void printMatrix(const Matrix* matrix) {
    if (!matrix) {
        printf("Invalid matrix\n");
        return;
    }

    printf("Matrix (%dx%d):\n", matrix->rows, matrix->cols);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%3d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Print array elements in a single line
 * @param arr Array to print
 * @param size Size of the array
 */
void printArray(const int* arr, int size) {
    if (!arr || size <= 0) {
        printf("Invalid array\n");
        return;
    }

    printf("Spiral Order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Example usage of spiral matrix traversal
 */
int main() {
    // Test Case 1: 3x3 matrix
    Matrix* matrix1 = createMatrix(3, 3);
    if (!matrix1) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize matrix with test data
    int value = 1;
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            matrix1->data[i][j] = value++;
        }
    }

    // Print original matrix
    printMatrix(matrix1);

    // Perform spiral traversal
    int resultSize;
    int* result = (int*)malloc(matrix1->rows * matrix1->cols * sizeof(int));
    if (!result) {
        printf("Memory allocation failed for result array\n");
        destroyMatrix(matrix1);
        return 1;
    }

    if (spiralTraversal(matrix1, result, &resultSize)) {
        printArray(result, resultSize);
    } else {
        printf("Spiral traversal failed\n");
    }

    // Clean up
    free(result);
    destroyMatrix(matrix1);

    // Test Case 2: 4x3 matrix (non-square)
    Matrix* matrix2 = createMatrix(4, 3);
    if (!matrix2) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize matrix with test data
    value = 1;
    for (int i = 0; i < matrix2->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            matrix2->data[i][j] = value++;
        }
    }

    // Print original matrix
    printMatrix(matrix2);

    // Perform spiral traversal
    result = (int*)malloc(matrix2->rows * matrix2->cols * sizeof(int));
    if (!result) {
        printf("Memory allocation failed for result array\n");
        destroyMatrix(matrix2);
        return 1;
    }

    if (spiralTraversal(matrix2, result, &resultSize)) {
        printArray(result, resultSize);
    } else {
        printf("Spiral traversal failed\n");
    }

    // Clean up
    free(result);
    destroyMatrix(matrix2);

    return 0;
}