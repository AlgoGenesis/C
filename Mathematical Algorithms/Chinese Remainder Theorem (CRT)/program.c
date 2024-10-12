#include <stdio.h>

// Function to find GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular multiplicative inverse of a under modulo m
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // No modular inverse exists
}

// Function to solve the system of congruences using CRT
int chineseRemainder(int num[], int rem[], int k) {
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    int result = 0;

    for (int i = 0; i < k; i++) {
        int ni = prod / num[i];
        int xi = modInverse(ni, num[i]);
        if (xi == -1) {
            printf("Inverse doesn't exist for modulus %d\n", num[i]);
            return -1;
        }
        result += rem[i] * xi * ni;
    }

    return result % prod;
}

int main() {
    int num[] = {3, 4, 5}; // Moduli
    int rem[] = {2, 3, 1}; // Remainders
    int k = sizeof(num) / sizeof(num[0]);

    int result = chineseRemainder(num, rem, k);

    if (result != -1) {
        printf("The solution is x ≡ %d (mod %d)\n", result, num[0] * num[1] * num[2]);
    }

    return 0;
}
