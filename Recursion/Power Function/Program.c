#include <stdio.h>

// Function to calculate power using binary exponentiation
int power(int base, int exp) {
    if (exp == 0) return 1;  // Base case: any number raised to 0 is 1

    int halfPower = power(base, exp / 2);  // Recursively calculate half the power

    // If exponent is even
    if (exp % 2 == 0) {
        return halfPower * halfPower;
    }
    
    // If exponent is odd
    else {
        return base * halfPower * halfPower;
    }
}

int main() {
    int base, exp;

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exp);

    int result = power(base, exp);
    printf("%d^%d = %d\n", base, exp, result);

    return 0;
}