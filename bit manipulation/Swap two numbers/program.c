#include <stdio.h>

void swap(int *a, int *b) {
    // Swap using addition and subtraction
    *a = *a + *b; // Step 1
    *b = *a - *b; // Step 2
    *a = *a - *b; // Step 3
}

int main() {
    int x, y;

    // Example input
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    printf("Before swapping: x = %d, y = %d\n", x, y);
    
    swap(&x, &y); // Call the swap function

    printf("After swapping: x = %d, y = %d\n", x, y);
    
    return 0;
}