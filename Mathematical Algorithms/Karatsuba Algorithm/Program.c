#include <stdio.h>
#include <math.h>

// Function to get the number of digits in a number
int getNumDigits(int n) {
    return n < 10 ? 1 : (int)log10(n) + 1;
}

// Function to split the number
void split(int x, int *high, int *low) {
    int m = getNumDigits(x) / 2;
    int divisor = (int)pow(10, m);
    *high = x / divisor;
    *low = x % divisor;
}

// Function to perform Karatsuba multiplication
int karatsuba(int x, int y) {
    // Base case
    if (x < 10 || y < 10) {
        return x * y;
    }

    // Split the numbers
    int a, b, c, d;
    split(x, &a, &b);
    split(y, &c, &d);

    // 3 recursive calls
    int z0 = karatsuba(b, d);
    int z1 = karatsuba(a + b, c + d);
    int z2 = karatsuba(a, c);

    // Combine results
    return z2 * (int)pow(10, 2 * (getNumDigits(x) / 2)) + 
           (z1 - z2 - z0) * (int)pow(10, getNumDigits(x) / 2) + 
           z0;
}

int main() {
    int x = 1234; // First number
    int y = 5678; // Second number

    int result = karatsuba(x, y);
    printf("The product of %d and %d is: %d\n", x, y, result);

    return 0;
}