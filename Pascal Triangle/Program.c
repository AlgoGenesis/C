#include <stdio.h>
#include <stdlib.h>

// Function to print Pascal's Triangle
void printPascal(int n) {
    int *arr = (int*)malloc(n * sizeof(int));

    // Iterate through every line
    for (int line = 0; line < n; line++) {
        // Initialize the last element in this row
        arr[line] = 1;
        
        // Update and print elements in reverse order to avoid overwriting
        for (int i = line - 1; i > 0; i--) {
            arr[i] = arr[i] + arr[i - 1];
        }

        // Print the current row
        for (int i = 0; i <= line; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    free(arr);
}

int main() {
    int n;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of rows must be positive.\n");
        return 1;
    }

    printPascal(n);
    return 0;
}
