#include <stdio.h>

int isPowerOfTwo(int n) {
    // A number is a power of 2 if it is greater than 0 and
    // (n & (n - 1)) is 0
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int n;

    // Example inputs
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPowerOfTwo(n)) {
        printf("%d is a power of 2.\n", n);
    } else {
        printf("%d is not a power of 2.\n", n);
    }

    return 0;
}
