#include <stdio.h>

// Function to calculate factorial modulo m
unsigned long long factorial_mod(unsigned long long n, unsigned long long mod) {
    unsigned long long result = 1;
    for (unsigned long long i = 2; i <= n; i++) {
        result = (result * i) % mod;
    }
    return result;
}

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

// Function to check if a prime number is a Wilson prime
int is_wilson_prime(int p) {
    if (!is_prime(p)) {
        return 0; // If the number is not prime, return false
    }
    
    // Calculate (p-1)! % (p*p)
    unsigned long long fact_mod = factorial_mod(p - 1, p * p);
    
    // Wilson prime condition: (p-1)! ≡ -1 (mod p^2)
    return (fact_mod == p * p - 1);
}

int main() {
    int p;
    printf("Enter a prime number to check if it is a Wilson prime: ");
    scanf("%d", &p);

    if (is_wilson_prime(p)) {
        printf("%d is a Wilson prime.\n", p);
    } else {
        printf("%d is not a Wilson prime.\n", p);
    }

    return 0;
}
