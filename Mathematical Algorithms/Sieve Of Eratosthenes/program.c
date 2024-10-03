#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* sieve(int n, int* size) {
    // Step 1: Initialize the array A
    int* A = (int*)malloc((n + 1) * sizeof(int));
    for (int p = 2; p <= n; p++) {
        A[p] = p; 
    }

    // Step 2: Mark non-prime numbers
    for (int p = 2; p <= sqrt(n); p++) {
        if (A[p] != 0) { // If p is prime
            for (int j = p * p; j <= n; j += p) {
                A[j] = 0; // Mark multiple as non-prime
            }
        }
    }

    // Step 3: Collect prime numbers into list L
    int* L = (int*)malloc((n / log(n) + 1) * sizeof(int)); // Estimate size of prime list using the Prime Number Theorem
    int i = 0;
    for (int p = 2; p <= n; p++) {
        if (A[p] != 0) {
            L[i] = A[p]; 
            i++;
        }
    }

    // Update the size of the prime numbers found
    *size = i;

    free(A);
    return L;
}

int main() {
    int n;
    printf("Enter a positive integer n > 1: ");
    scanf("%d", &n);

    // Call the sieve function
    int size = 0;
    int* primes = sieve(n, &size);

    // Print the prime numbers
    printf("Prime numbers up to %d:\n", n);
    for (int i = 0; i < size; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Free memory for the list of primes
    free(primes);
    return 0;
}
