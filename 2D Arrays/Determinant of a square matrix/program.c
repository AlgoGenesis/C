#include <stdio.h>
#include <math.h>

#define MAX 10  // LET Maximum size of the matrix

// Function declarations
int determinant_recursive(int matrix[MAX][MAX], int n);
int determinant_gaussian_elimination(int matrix[MAX][MAX], int n);
void lu_decomposition(int matrix[MAX][MAX], int n, int *determinant);

int main() {
    int matrix[MAX][MAX], n, i, j, choice;
    
    // Input matrix size
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Choose method to calculate determinant
    printf("\nChoose the method to calculate determinant:\n");
    printf("1. Recursive (Laplace Expansion)\n");
    printf("2. Gaussian Elimination\n");
    printf("3. LU Decomposition\n");
    scanf("%d", &choice);

    int det = 0;
    switch (choice) {
        case 1:
            det = determinant_recursive(matrix, n);
            printf("Determinant (Recursive) = %d\n", det);
            break;
        case 2:
            det = determinant_gaussian_elimination(matrix, n);
            printf("Determinant (Gaussian Elimination) = %d\n", det);
            break;
        case 3:
            lu_decomposition(matrix, n, &det);
            printf("Determinant (LU Decomposition) = %d\n", det);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

/* Function to calculate determinant using recursive method (Laplace expansion)
 * Time complexity: O(n!) */
int determinant_recursive(int matrix[MAX][MAX], int n) {
    int det = 0;

    // Base case: if matrix size is 1, determinant is the single element
    if (n == 1)
        return matrix[0][0];

    int submatrix[MAX][MAX];  // To hold the submatrix
    int sign = 1;  // To alternate the sign (+, -)

    // Loop over each element in the first row
    for (int i = 0; i < n; i++) {
        // Get submatrix by excluding the first row and current column
        int subi = 0;
        for (int row = 1; row < n; row++) {
            int subj = 0;
            for (int col = 0; col < n; col++) {
                if (col == i)
                    continue;
                submatrix[subi][subj] = matrix[row][col];
                subj++;
            }
            subi++;
        }
        // Recursive call to determinant of submatrix
        det += sign * matrix[0][i] * determinant_recursive(submatrix, n - 1);
        sign = -sign;  // Alternate the sign
    }

    return det;
}

/*  determinant using Gaussian elimination method
 *  O(n^3) */
int determinant_gaussian_elimination(int matrix[MAX][MAX], int n) {
    int temp[MAX][MAX];
    int i, j, k, sign = 1, det = 1;

    // Copy the matrix to avoid modifying the original matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            temp[i][j] = matrix[i][j];
        }
    }

    // Gaussian Elimination to convert matrix into upper triangular form
    for (i = 0; i < n; i++) {
        if (temp[i][i] == 0) {
            // Swap rows if diagonal element is zero
            for (j = i + 1; j < n; j++) {
                if (temp[j][i] != 0) {
                    for (k = 0; k < n; k++) {
                        int swap = temp[i][k];
                        temp[i][k] = temp[j][k];
                        temp[j][k] = swap;
                    }
                    sign *= -1;  // Adjust sign for row swap
                    break;
                }
            }
        }

        // If matrix is singular, determinant is zero
        if (temp[i][i] == 0)
            return 0;

        // Eliminate the elements below the diagonal
        for (j = i + 1; j < n; j++) {
            double factor = (double)temp[j][i] / temp[i][i];
            for (k = 0; k < n; k++) {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }

    // Determinant is the product of the diagonal elements
    for (i = 0; i < n; i++) {
        det *= temp[i][i];
    }

    return sign * det;
}

/*  determinant using LU decomposition method
 O(n^3) */
void lu_decomposition(int matrix[MAX][MAX], int n, int *determinant) {
    int lower[MAX][MAX], upper[MAX][MAX];
    int i, j, k;

    // Initialize lower and upper matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            lower[i][j] = 0;
            upper[i][j] = 0;
        }
    }

    // LU decomposition
    for (i = 0; i < n; i++) {
        // Upper triangular matrix
        for (k = i; k < n; k++) {
            int sum = 0;
            for (j = 0; j < i; j++) {
                sum += lower[i][j] * upper[j][k];
            }
            upper[i][k] = matrix[i][k] - sum;
        }

        // Lower triangular matrix
        for (k = i; k < n; k++) {
            if (i == k)
                lower[i][i] = 1;  // Diagonal elements of lower triangular matrix are 1
            else {
                int sum = 0;
                for (j = 0; j < i; j++) {
                    sum += lower[k][j] * upper[j][i];
                }
                lower[k][i] = (matrix[k][i] - sum) / upper[i][i];
            }
        }
    }

    // Calculate determinant as product of diagonals of upper matrix
    *determinant = 1;
    for (i = 0; i < n; i++) {
        *determinant *= upper[i][i];
    }
}
