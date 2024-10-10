#include <stdio.h>

// Function to implement the extended Euclidean algorithm
int extendedGCD(int a, int b, int *x, int *y) {
    // Base case: if b == 0, the gcd is a, and we set x = 1, y = 0
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    // Recursive call with swapped values
    int x1, y1; // Temporary variables to store results of recursion
    int gcd = extendedGCD(b, a % b, &x1, &y1);

    // Update x and y using the results from the recursive call
    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

// Function to find the multiplicative inverse of 'a' modulo 'n'
int modInverse(int a, int n) {
    int x, y;
    int gcd = extendedGCD(a, n, &x, &y);

    // If gcd is not 1, then inverse doesn't exist
    if (gcd != 1) {
        printf("Multiplicative inverse does not exist since gcd(%d, %d) != 1\n", a, n);
        return -1;
    }

    // The multiplicative inverse is x modulo n
    // We need to handle negative values of x by making it positive
    int result = (x % n + n) % n;
    return result;
}

int main() {
    int a, n;

    // Input number and modulus
    printf("Enter the number (a): ");
    scanf("%d", &a);
    printf("Enter the modulus (n): ");
    scanf("%d", &n);

    // Find the multiplicative inverse
    int inverse = modInverse(a, n);
    if (inverse != -1) {
        printf("The multiplicative inverse of %d modulo %d is: %d\n", a, n, inverse);
    }

    return 0;
}
