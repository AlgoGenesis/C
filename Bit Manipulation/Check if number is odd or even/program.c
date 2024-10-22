#include <stdio.h>

// Function to check if a number is odd or even using bit manipulation
void checkOddEven(int num) {
    if (num & 1) {
        printf("%d is Odd\n", num);
    } else {
        printf("%d is Even\n", num);
    }
}

int main() {
    int number;

    // Taking input from the user
    printf("Enter a number: ");
    scanf("%d", &number);

    // Checking if the number is odd or even
    checkOddEven(number);

    return 0;
}
