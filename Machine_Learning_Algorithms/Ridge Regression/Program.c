#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to transpose a matrix
void transpose(double **matrix, double **transposeMatrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposeMatrix[j][i] = matrix[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(double **matrixA, double **matrixB, double **result, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to add regularization term (lambda * Identity matrix) to matrix
void addRegularization(double **matrix, double lambda, int size) {
    for (int i = 0; i < size; i++) {
        matrix[i][i] += lambda;
    }
}

// Function to invert a matrix using Gauss-Jordan elimination
int invertMatrix(double **matrix, double **inverse, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inverse[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < size; i++) {
        double diagElement = matrix[i][i];
        if (fabs(diagElement) < 1e-10) {
            return -1; // Matrix is singular
        }

        for (int j = 0; j < size; j++) {
            matrix[i][j] /= diagElement;
            inverse[i][j] /= diagElement;
        }

        for (int k = 0; k < size; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < size; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                    inverse[k][j] -= factor * inverse[i][j];
                }
            }
        }
    }

    return 0;
}

// Ridge Regression function to calculate beta coefficients
void ridgeRegression(double **X, double *y, double *beta, int n, int d, double lambda) {
    // Step 1: Transpose X
    double **XT = (double **)malloc(d * sizeof(double *));
    for (int i = 0; i < d; i++) {
        XT[i] = (double *)malloc(n * sizeof(double));
    }
    transpose(X, XT, n, d);

    // Step 2: Calculate X^T * X
    double **XTX = (double **)malloc(d * sizeof(double *));
    for (int i = 0; i < d; i++) {
        XTX[i] = (double *)malloc(d * sizeof(double));
    }
    multiplyMatrices(XT, X, XTX, d, n, d);

    // Step 3: Add regularization term (lambda * I) to X^T * X
    addRegularization(XTX, lambda, d);

    // Step 4: Invert X^T * X + lambda * I
    double **XTX_inv = (double **)malloc(d * sizeof(double *));
    for (int i = 0; i < d; i++) {
        XTX_inv[i] = (double *)malloc(d * sizeof(double));
    }
    if (invertMatrix(XTX, XTX_inv, d) != 0) {
        printf("Matrix inversion failed, singular matrix.\n");
        return;
    }

    // Step 5: Calculate X^T * y
    double **XTy = (double **)malloc(d * sizeof(double *));
    for (int i = 0; i < d; i++) {
        XTy[i] = (double *)malloc(1 * sizeof(double));
        XTy[i][0] = 0;
        for (int j = 0; j < n; j++) {
            XTy[i][0] += XT[i][j] * y[j];
        }
    }

    // Step 6: Multiply inverse(X^T * X + lambda * I) with X^T * y
    double **betaMatrix = (double **)malloc(d * sizeof(double *));
    for (int i = 0; i < d; i++) {
        betaMatrix[i] = (double *)malloc(1 * sizeof(double));
    }
    multiplyMatrices(XTX_inv, XTy, betaMatrix, d, d, 1);

    // Step 7: Store the result in beta
    for (int i = 0; i < d; i++) {
        beta[i] = betaMatrix[i][0];
    }

    // Freeing memory
    for (int i = 0; i < d; i++) {
        free(XT[i]);
        free(XTX[i]);
        free(XTX_inv[i]);
        free(XTy[i]);
        free(betaMatrix[i]);
    }
    free(XT);
    free(XTX);
    free(XTX_inv);
    free(XTy);
    free(betaMatrix);
}

int main() {
    int n = 5;  // Number of data points
    int d = 3;  // Number of features

    // Example data for X and y
    double **X = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        X[i] = (double *)malloc(d * sizeof(double));
    }

    // Sample data points
    X[0][0] = 1; X[0][1] = 2; X[0][2] = 3;
    X[1][0] = 2; X[1][1] = 3; X[1][2] = 4;
    X[2][0] = 3; X[2][1] = 4; X[2][2] = 5;
    X[3][0] = 4; X[3][1] = 5; X[3][2] = 6;
    X[4][0] = 5; X[4][1] = 6; X[4][2] = 7;

    double y[] = {1, 2, 3, 4, 5};  // Target values

    double lambda = 0.1;  // Regularization parameter
    double beta[d];  // To store the computed coefficients

    // Perform Ridge Regression
    ridgeRegression(X, y, beta, n, d, lambda);

    // Output the coefficients
    printf("Computed coefficients (beta values):\n");
    for (int i = 0; i < d; i++) {
        printf("Beta[%d] = %.4f\n", i, beta[i]);
    }

    // Freeing memory
    for (int i = 0; i < n; i++) {
        free(X[i]);
    }
    free(X);

    return 0;
}
