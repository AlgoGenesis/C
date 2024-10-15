#include <stdio.h>

// Function to print Pascal's Triangle
void printPascal(int n) {
    int arr[n][n];

    // Iterate through every line and print the corresponding elements
    for (int line = 0; line < n; line++) {
        // Initialize the first and last elements of every row to 1
        for (int i = 0; i <= line; i++) {
            // The first and last values in every row are 1
            if (i == 0 || i == line)
                arr[line][i] = 1;
            else // Other values are the sum of the two values above it
                arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];

            printf("%d ", arr[line][i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n);
    printPascal(n);
    return 0;
}
