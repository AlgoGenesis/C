#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); // Input the integer N

    // Edge case: when N is 0, directly print 0
    if (N == 0) {
        printf("0\n");
        return 0;
    }

    // Array to hold binary digits (assuming max 10 bits for N <= 1000)
    char binary[10];
    int index = 0;

    // Loop to convert decimal to binary
    while (N > 0) {
        binary[index++] = (N % 2) + '0'; // Store the remainder (binary digit) as a character
        N /= 2; // Update N to be the quotient
    }

    // Print the binary digits in reverse order
    for (int i = index - 1; i >= 0; --i) {
        printf("%c", binary[i]);
    }
    printf("\n"); // Print a newline character at the end

    return 0;
}
