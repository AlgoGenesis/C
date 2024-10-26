#include <stdio.h>

// Function to calculate binomial coefficient "n choose k"
int binomialCoeff(int n, int k) {
    int res = 1;
    // Since C(n, k) = C(n, n-k)
    if (k > n - k) 
        k = n - k;

    // Calculate value of C(n, k) as n! / (k! * (n-k)!)
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// Function to print Pascal's Triangle
void printPascalsTriangle(int rows) {
    for (int i = 0; i < rows; i++) {
        // Print leading spaces for alignment
        for (int j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }
        // Print the values in the current row
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoeff(i, j));
        }
        printf("\n"); // Move to the next row
    }
}

int main() {
    int rows;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    // Display Pascal's Triangle
    printPascalsTriangle(rows);

    return 0;
}
