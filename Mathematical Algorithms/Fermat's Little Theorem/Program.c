#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform modular exponentiation
long long power(long long x, unsigned int y, long long p) {
    long long result = 1;  // Initialize result

    // Update x if it is more than or equal to p
    x = x % p;  

    if (x == 0) return 0; // In case x is divisible by p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) {
            result = (result * x) % p;
        }
        // y must be even now
        y = y >> 1; // y = y / 2
        x = (x * x) % p; // Change x to x^2
    }
    return result;
}

// Function to check if n is prime using Fermat's Little Theorem
int isPrime(int n, int k) {
    // Handle base cases
    if (n <= 1) return 0; // Not prime
    if (n <= 3) return 1; // 2 and 3 are prime

    // Test k times
    for (int i = 0; i < k; i++) {
        // Generate a random number in [2, n-2]
        int a = 2 + rand() % (n - 4);
        
        // If a^(n-1) % n is not 1, then n is not prime
        if (power(a, n - 1, n) != 1) {
            return 0;
        }
    }
    return 1; // n is probably prime
}

int main() {
    int n, k;

    // Seed random number generator
    srand(time(NULL));

    // Get user input
    printf("Enter a number to check if it's prime: ");
    scanf("%d", &n);
    printf("Enter the number of iterations for accuracy: ");
    scanf("%d", &k);

    // Check if n is prime
    if (isPrime(n, k))
        printf("%d is probably prime.\n", n);
    else
        printf("%d is not prime.\n", n);

    return 0;
}
