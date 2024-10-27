#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITER 1000   // Maximum number of iterations
#define TOLERANCE 1e-6  // Convergence tolerance

// Function to compute the dot product of two vectors
double dotProduct(double *a, double *b, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }
    return result;
}

// Soft thresholding operator
double softThreshold(double rho, double lambda) {
    if (rho < -lambda) {
        return rho + lambda;
    } else if (rho > lambda) {
        return rho - lambda;
    } else {
        return 0;
    }
}

// Coordinate Descent Algorithm for Lasso Regression
void lassoRegression(double **X, double *y, double *beta, int n, int d, double lambda) {
    double *residual = (double *)malloc(n * sizeof(double));
    double rho;
    int iter = 0;
    
    // Initialize beta coefficients to 0
    for (int j = 0; j < d; j++) {
        beta[j] = 0;
    }

    while (iter < MAX_ITER) {
        int converged = 1;

        // For each feature j
        for (int j = 0; j < d; j++) {
            // Calculate the residual (y - X * beta) + X_j * beta_j
            for (int i = 0; i < n; i++) {
                residual[i] = y[i] - dotProduct(X[i], beta, d) + X[i][j] * beta[j];
            }

            // Compute rho (partial derivative w.r.t beta_j)
            rho = dotProduct(X[j], residual, n);

            // Update beta_j using soft-thresholding
            double newBeta_j = softThreshold(rho, lambda);

            // Check for convergence
            if (fabs(beta[j] - newBeta_j) > TOLERANCE) {
                converged = 0;
            }

            // Update beta_j
            beta[j] = newBeta_j;
        }

        if (converged) {
            break;
        }

        iter++;
    }

    free(residual);
}

int main() {
    // Sample dataset (4 data points, 3 features)
    int n = 4; // Number of samples
    int d = 3; // Number of features
    double X[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    double y[4] = {14, 32, 50, 68}; // Target variable

    // Regularization parameter (lambda)
    double lambda = 0.1;

    // Memory allocation for beta (coefficients)
    double *beta = (double *)malloc(d * sizeof(double));

    // Convert 2D array to pointer array (for passing to function)
    double **X_ptr = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        X_ptr[i] = X[i];
    }

    // Run Lasso Regression
    lassoRegression(X_ptr, y, beta, n, d, lambda);

    // Output the resulting coefficients
    printf("Lasso Regression Coefficients:\n");
    for (int j = 0; j < d; j++) {
        printf("Beta[%d] = %.5f\n", j, beta[j]);
    }

    // Free allocated memory
    free(beta);
    free(X_ptr);

    return 0;
}
