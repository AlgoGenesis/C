#include <stdio.h>

int sumNaturalNumbers(int n) {
    if (n == 0) {  // base case
        return 0;
    }
    return n + sumNaturalNumbers(n - 1); // recursive call
}

int main() {
    int n;
    printf("Enter a natural number: ");
    scanf("%d", &n);
    if (n < 0) { 
        printf("Not a natural number.\n");
    } else {
        printf("The sum of the first %d natural numbers is: %d\n", n, sumNaturalNumbers(n));
    }
    return 0;
}