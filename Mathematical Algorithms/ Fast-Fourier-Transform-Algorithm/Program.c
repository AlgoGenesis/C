#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define PI 3.14159265358979323846

// Function to perform the FFT
void fft(complex double *X, int N) {
    if (N <= 1) return;

    // Split into even and odd
    complex double *X_even = malloc(N/2 * sizeof(complex double));
    complex double *X_odd = malloc(N/2 * sizeof(complex double));
    
    for (int i = 0; i < N/2; i++) {
        X_even[i] = X[i*2];
        X_odd[i] = X[i*2 + 1];
    }

    // Recursive calls
    fft(X_even, N/2);
    fft(X_odd, N/2);

    // Combine the results
    for (int i = 0; i < N/2; i++) {
        complex double t = cexp(-2.0 * I * PI * i / N) * X_odd[i];
        X[i] = X_even[i] + t;
        X[i + N/2] = X_even[i] - t;
    }

    free(X_even);
    free(X_odd);
}

int main() {
    int N;

    // Input number of points (must be power of 2)
    printf("Enter number of points (N should be a power of 2): ");
    scanf("%d", &N);

    // Allocate memory for input array
    complex double *X = malloc(N * sizeof(complex double));

    // Input data points
    printf("Enter real values of data points:\n");
    for (int i = 0; i < N; i++) {
        double real;
        printf("X[%d] = ", i);
        scanf("%lf", &real);
        X[i] = real + 0.0 * I;  // Setting imaginary part to 0
    }

    // Perform FFT
    fft(X, N);

    // Output the result
    printf("FFT results:\n");
    for (int i = 0; i < N; i++) {
        printf("X[%d] = %.5f + %.5fi\n", i, creal(X[i]), cimag(X[i]));
    }

    free(X);
    return 0;
}
