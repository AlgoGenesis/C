#include <stdio.h>

// Function to calculate GCD using the Euclidean algorithm
int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM using the GCD
int findLCM(int a, int b) {
    return (a / findGCD(a, b)) * b;
}

int main() {
    int n1, n2, lcm;

    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);

    lcm = findLCM(n1, n2);

    printf("The LCM of %d and %d is %d.\n", n1, n2, lcm);

    return 0;
}
