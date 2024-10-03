#include <stdio.h>

int Euclid(int m, int n) {
    // Computes gcd(m, n) by Euclid's algorithm
    while (n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int main() {
    int m, n;
    printf("Enter two nonnegative integers: ");
    scanf("%d %d", &m, &n);
    int gcd = Euclid(m, n);
    printf("Greatest common divisor of %d and %d is: %d\n", m, n, gcd);
    return 0;
}
