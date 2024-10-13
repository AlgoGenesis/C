#include <stdio.h>
#include <stdlib.h>

// Function to perform Gauss-Jordan Elimination
void gaussJordan(float **a, int n) {
    int i, j, k;
    float factor;

    for (i = 0; i < n; i++) {
        // Ensure the diagonal element is non-zero
        if (a[i][i] == 0) {
            int found = 0; // Flag to check if we found a non-zero element
            for (j = i + 1; j < n; j++) {
                if (a[j][i] != 0) {
                    // Swap the rows
                    for (k = 0; k <= n; k++) {
                        float temp = a[i][k];
                        a[i][k] = a[j][k];
                        a[j][k] = temp;
                    }
                    found = 1; // Found a non-zero element to swap
                    break;
                }
            }
            if (!found) {
                printf("Error: No unique solution. The matrix may be singular or inconsistent.\n");
                return; 
            }
        }

        // Make the diagonal element 1
        factor = a[i][i];
        if (factor == 0) {
            printf("Error: Zero pivot encountered. No unique solution exists.\n");
            return; // Exit if the pivot is still zero
        }
        for (j = 0; j <= n; j++) {
            a[i][j] /= factor;
        }

        // Make other elements in the column zero
        for (j = 0; j < n; j++) {
            if (i != j) {
                factor = a[j][i];
                for (k = 0; k <= n; k++) {
                    a[j][k] -= factor * a[i][k];
                }
            }
        }
    }
}


int main() {
    int n;
    
    // User input for the size of the matrix
    printf("Enter the number of variables (size of the matrix): ");
    scanf("%d", &n);

    // Dynamically allocate memory for the augmented matrix
    float **a = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        a[i] = (float *)malloc((n + 1) * sizeof(float));
    }

    // Input the matrix
    printf("Enter the augmented matrix (coefficients followed by the constants):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Perform Gauss-Jordan elimination
    gaussJordan(a, n);
    
    printf("The solution is: \n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, a[i][n]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(a[i]); 
    }
    free(a);

    return 0;
}

