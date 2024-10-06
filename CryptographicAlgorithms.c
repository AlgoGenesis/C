#include <stdio.h>

// Function to compute GCD using Euclidean algorithm
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to compute (base^exponent) % modulus using binary exponentiation
long long powerMod(long long base, long long exponent, long long modulus) {
    if (modulus == 1)
        return 0;
    long long result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent & 1) // If exponent is odd
            result = (result * base) % modulus;
        exponent = exponent >> 1; // Divide exponent by 2
        base = (base * base) % modulus;
    }
    return result;
}

// Extended Euclidean Algorithm to find modular inverse
long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as Euclidean algorithm
        m = a % m;
        a = t;

        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {
    // Step 1: Choose two prime numbers p and q
    long long p = 61;
    long long q = 53;

    // Step 2: Compute n = p * q
    long long n = p * q;

    // Step 3: Compute φ(n) = (p-1)*(q-1)
    long long phi = (p - 1) * (q - 1);

    // Step 4: Choose e such that 1 < e < phi and gcd(e, phi) == 1
    long long e = 17;
    if (gcd(e, phi) != 1) {
        printf("e and phi(n) are not coprime. Choose a different e.\n");
        return 1;
    }

    // Step 5: Compute d, the modular inverse of e mod phi(n)
    long long d = modInverse(e, phi);
    if ((e * d) % phi != 1) {
        printf("Modular inverse not found. Choose a different e.\n");
        return 1;
    }

    // Display the keys
    printf("RSA Key Generation:\n");
    printf("p = %lld, q = %lld\n", p, q);
    printf("n = p * q = %lld\n", n);
    printf("phi(n) = (p-1)*(q-1) = %lld\n", phi);
    printf("Public Key (e, n) = (%lld, %lld)\n", e, n);
    printf("Private Key (d, n) = (%lld, %lld)\n\n", d, n);

    // Example: Encrypting and Decrypting a message
    // Let's take a plaintext message m, where m < n
    long long m = 65; // Example plaintext

    // Encryption: c = m^e mod n
    long long c = powerMod(m, e, n);
    printf("Plaintext (m) = %lld\n", m);
    printf("Encrypted Ciphertext (c) = %lld\n", c);

    // Decryption: m = c^d mod n
    long long decrypted = powerMod(c, d, n);
    printf("Decrypted Message (m) = %lld\n", decrypted);

    return 0;
}
