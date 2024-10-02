#include <stdio.h>

// Function to perform binary exponentiation
long long binary_exponentiation(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        // If the current exponent bit is set, multiply the result by base
        if (exp % 2 == 1) {
            result *= base;
        }
        // Square the base
        base *= base;
        // Right shift the exponent
        exp /= 2;
    }
    return result;
}

int main() {
    long long base, exp;
    
    // Input base and exponent
    printf("Enter base and exponent: ");
    scanf("%lld %lld", &base, &exp);
    
    // Perform binary exponentiation
    long long result = binary_exponentiation(base, exp);
    
    // Output the result
    printf("%lld^%lld = %lld\n", base, exp, result);
    
    return 0;
}
