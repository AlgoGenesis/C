#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100 // Number of samples
#define M 10  // Number of features

// Function to calculate the mean of each feature
void calculate_mean(double data[N][M], double mean[M]) {
    for (int j = 0; j < M; j++) {
        mean[j] = 0;
        for (int i = 0; i < N; i++) {
            mean[j] += data[i][j];
        }
        mean[j] /= N;
    }
}

// Function to standardize the data
void standardize_data(double data[N][M], double mean[M], double stddev[M], double standardized[N][M]) {
    for (int j = 0; j < M; j++) {
        stddev[j] = 0;
        for (int i = 0; i < N; i++) {
            standardized[i][j] = data[i][j] - mean[j];
            stddev[j] += standardized[i][j] * standardized[i][j];
        }
        stddev[j] = sqrt(stddev[j] / N);
        for (int i = 0; i < N; i++) {
            standardized[i][j] /= stddev[j];
        }
    }
}

// Function to compute the covariance matrix
void compute_covariance_matrix(double standardized[N][M], double covariance[M][M]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            covariance[i][j] = 0;
            for (int k = 0; k < N; k++) {
                covariance[i][j] += standardized[k][i] * standardized[k][j];
            }
            covariance[i][j] /= (N - 1);
        }
    }
}

// Function to compute eigenvalues and eigenvectors (placeholder for actual implementation)
void compute_eigenvalues_and_eigenvectors(double covariance[M][M], double eigenvalues[M], double eigenvectors[M][M]) {
    // This part requires a numerical library for eigenvalue decomposition
    // Placeholder: You may use libraries like LAPACK or implement your own algorithm.
}

// Function to project data onto the principal components
void project_data(double standardized[N][M], double eigenvectors[M][M], double projected[N][M], int k) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < k; j++) {
            projected[i][j] = 0;
            for (int l = 0; l < M; l++) {
                projected[i][j] += standardized[i][l] * eigenvectors[l][j];
            }
        }
    }
}

int main() {
    double data[N][M]; // Input data
    double mean[M], stddev[M];
    double standardized[N][M];
    double covariance[M][M];
    double eigenvalues[M];
    double eigenvectors[M][M];
    double projected[N][M]; // Projected data

    // Initialize your data here (data[N][M])

    calculate_mean(data, mean);
    standardize_data(data, mean, stddev, standardized);
    compute_covariance_matrix(standardized, covariance);
    compute_eigenvalues_and_eigenvectors(covariance, eigenvalues, eigenvectors);

    int k = 2; // Number of principal components to keep
    project_data(standardized, eigenvectors, projected, k);

    // Output the projected data
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < k; j++) {
            printf("%lf ", projected[i][j]);
        }
        printf("\n");
    }

    return 0;
}
