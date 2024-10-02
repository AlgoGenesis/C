#include <stdio.h>

int isBitSet(int n, int i) {
    return (n & (1 << i)) != 0;
}

int main() {
    int n = 5; // Binary: 101
    int i = 2;

    if (isBitSet(n, i)) {
        printf("The %d-th bit is set.\n", i); // Output: The 2-th bit is set.
    } else {
        printf("The %d-th bit is not set.\n", i);
    }

    return 0;
}