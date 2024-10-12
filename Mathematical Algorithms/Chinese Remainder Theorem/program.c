#include <stdio.h>

// Function to find the GCD of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Extended Euclidean algorithm to find the modular inverse
int extendedGCD(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1; // To store results of recursive call
    int gcd = extendedGCD(b, a % b, &x1, &y1);
    
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

// Function to find the modular inverse of a with respect to m
int modInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, &x, &y);
    if (g != 1) {
        return -1; // Inverse doesn't exist
    }
    return (x % m + m) % m; // Ensure the result is positive
}

// Function to find the solution to the system of congruences
int chineseRemainder(int num[], int rem[], int k, int *prod) {
    *prod = 1;
    for (int i = 0; i < k; i++) {
        *prod *= num[i];
    }

    int result = 0;
    for (int i = 0; i < k; i++) {
        int pp = *prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % (*prod);
}

int main() {
    int k;

    // Input number of equations
    printf("Enter the number of equations: ");
    scanf("%d", &k);

    int num[k];  // Array for moduli
    int rem[k];  // Array for remainders

    // Input moduli and remainders
    printf("Enter the moduli:\n");
    for (int i = 0; i < k; i++) {
        scanf("%d", &num[i]);
    }

    printf("Enter the remainders:\n");
    for (int i = 0; i < k; i++) {
        scanf("%d", &rem[i]);
    }

    // Check if the moduli are pairwise coprime
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (gcd(num[i], num[j]) != 1) {
                printf("The moduli must be pairwise coprime.\n");
                return 1;
            }
        }
    }

    int prod; // Declare prod here
    // Solve the system of congruences
    int result = chineseRemainder(num, rem, k, &prod);
    printf("The solution is x ≡ %d (mod %d)\n", result, prod); // Now prod is defined

    return 0;
}
