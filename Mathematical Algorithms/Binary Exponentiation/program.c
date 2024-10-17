#include <stdio.h>

// Function to perform binary exponentiation
long long binaryExpo(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        // If exp is odd, multiply the base with the result
        if (exp % 2 == 1) {
            result *= base;
        }
        // Square the base
        base *= base;
        // Divide the exponent by 2
        exp /= 2;
    }
    return result;
}

int main() {
    long long base, exp;
    
    // Input base and exponent
    printf("Enter base: ");
    scanf("%lld", &base);
    printf("Enter exponent: ");
    scanf("%lld", &exp);

    // Calculate base^exp using binary exponentiation
    long long result = binaryExpo(base, exp);
    
    // Output the result
    printf("%lld^%lld = %lld\n", base, exp, result);
    
    return 0;
}
