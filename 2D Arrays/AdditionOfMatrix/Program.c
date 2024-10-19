#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    // Input the number of rows and columns with validation
    printf("Enter the number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid input for rows!\n");
        return 1;
    }

    printf("Enter the number of columns: ");
    if (scanf("%d", &cols) != 1 || cols <= 0) {
        printf("Invalid input for columns!\n");
        return 1;
    }

    // Dynamic memory allocation for arrays
    int **array1 = (int **)malloc(rows * sizeof(int *));
    int **array2 = (int **)malloc(rows * sizeof(int *));
    int **result = (int **)malloc(rows * sizeof(int *));
    
    for (int i = 0; i < rows; i++) {
        array1[i] = (int *)malloc(cols * sizeof(int));
        array2[i] = (int *)malloc(cols * sizeof(int));
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    // Input elements for the first array
    printf("Enter elements of the first array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element at [%d][%d]: ", i, j);
            if (scanf("%d", &array1[i][j]) != 1) {
                printf("Invalid input for array element!\n");
                return 1;
            }
        }
    }

    // Input elements for the second array
    printf("Enter elements of the second array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element at [%d][%d]: ", i, j);
            if (scanf("%d", &array2[i][j]) != 1) {
                printf("Invalid input for array element!\n");
                return 1;
            }
        }
    }

    // Perform element-wise addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = array1[i][j] + array2[i][j];
        }
    }

    // Print the result array
    printf("Resulting array after addition:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(array1[i]);
        free(array2[i]);
        free(result[i]);
    }
    free(array1);
    free(array2);
    free(result);

    return 0;
}
