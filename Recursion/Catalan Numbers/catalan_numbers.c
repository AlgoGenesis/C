#include <stdio.h>

// Recursive function to calculate the nth Catalan number
unsigned long catalan_recursive(int n) {
    if (n <= 1) {
        return 1;
    }

    unsigned long result = 0;
    for (int i = 0; i < n; i++) {
        result += catalan_recursive(i) * catalan_recursive(n - 1 - i);
    }
    return result;
}

int main() {
    int n;

    printf("Enter the number of Catalan numbers to generate: ");
    scanf("%d", &n);

    printf("Catalan Numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%lu ", catalan_recursive(i));
    }
    printf("\n");

    return 0;
}
