#include <stdio.h>

int main() {
    int number, i;

    // Prompt the user to enter a number
    printf("Enter a number to generate its multiplication table: ");
    scanf("%d", &number);

    // Generate and print the multiplication table
    printf("Multiplication Table of %d:\n", number);
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", number, i, number * i);
    }

    return 0;
}