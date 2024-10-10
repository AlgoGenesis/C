#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int max(int a, int b) {
return (a > b) ? a : b;
}
unsigned long long karatsuba(unsigned long long x, unsigned long long y) {
if (x < 10 || y < 10) {
return x * y;
}
int n = max((int)log10(x) + 1, (int)log10(y) + 1);
int m = n / 2;
unsigned long long pow10m = pow(10, m);
unsigned long long a = x / pow10m;
unsigned long long b = x % pow10m;
unsigned long long c = y / pow10m;
unsigned long long d = y % pow10m;
unsigned long long ac = karatsuba(a, c);
unsigned long long bd = karatsuba(b, d);
unsigned long long ab_cd = karatsuba(a + b, c + d) - ac - bd;
return ac * pow(10, 2 * m) + ab_cd * pow(10, m) + bd;
}
int main() {
unsigned long long x, y;
printf("Enter the first number: ");
if (scanf("%llu", &x) != 1) {
printf("Invalid input for the first number.\n");
exit(1);
}
printf("Enter the second number: ");
if (scanf("%llu", &y) != 1) {
	printf("Invalid input for the second number.\n");
	exit(1);
	}
unsigned long long result = karatsuba(x, y);
printf("Karatsuba multiplication of %llu and %llu is %llu\n", x, y, result);
return 0;
	}

