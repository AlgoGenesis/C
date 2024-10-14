#include <stdio.h>
#include <math.h>

// Function to calculate the number of digits in a number
int getSize(int num) {
    int size = 0;
    while (num != 0) {
        num /= 10;
        size++;
    }
    return size;
}

// Karatsuba function to multiply two numbers
long karatsuba(int x, int y) {
    // Base case: if the numbers are small enough, use regular multiplication
    if (x < 10 || y < 10) {
        return x * y;
    }

    // Calculate the size of the numbers
    int n = fmax(getSize(x), getSize(y));
    int half = n / 2;

    // Split the numbers into two parts
    int a = x / pow(10, half);
    int b = x % (int)pow(10, half);
    int c = y / pow(10, half);
    int d = y % (int)pow(10, half);

    // Recursively calculate ac, bd, and (a+b)*(c+d)
    long ac = karatsuba(a, c);
    long bd = karatsuba(b, d);
    long ad_bc = karatsuba(a + b, c + d) - ac - bd;

    // Combine the results
    return ac * pow(10, 2 * half) + (ad_bc * pow(10, half)) + bd;
}

int main() {
    int x, y;

    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &x, &y);

    long result = karatsuba(x, y);
    printf("Product: %ld\n", result);

    return 0;
}
