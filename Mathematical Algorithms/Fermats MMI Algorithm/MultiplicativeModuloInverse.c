#include <stdio.h>

// Function to compute (base^exp) % mod using binary exponentiation
long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {  // If exp is odd, multiply base with result
            result = (result * base) % mod;
        }
        exp = exp >> 1;  // Divide exp by 2
        base = (base * base) % mod;  // Square the base
    }
    return result;
}

// Function to find the modular inverse of a under modulo p
long long mod_inverse(long long a, long long p) {
    return power_mod(a, p - 2, p);  // Using Fermat's Little Theorem
}

int main() {
    long long a, p;
    
    // Input the number 'a' and the prime 'p'
    printf("Enter the number (a): ");
    scanf("%lld", &a);
    printf("Enter the prime modulus (p): ");
    scanf("%lld", &p);
    
    // Ensure 'a' and 'p' are valid
    if (a == 0 || p <= 1) {
        printf("Invalid input!\n");
        return 1;
    }
    
    // Find and display the modular inverse of 'a' under modulo 'p'
    long long inverse = mod_inverse(a, p);
    printf("The modular inverse of %lld under modulo %lld is: %lld\n", a, p, inverse);
    
    return 0;
}
