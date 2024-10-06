#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

// Function to print the distance matrix
void printMatrix(int** matrix, int m, int n) {
    printf("\nDistance Matrix:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate Levenshtein distance
int levenshteinDistance(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);
    
    // Create a matrix to store the distances
    int** d = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        d[i] = (int*)malloc((n + 1) * sizeof(int));
    }
    
    // Initialize first row and column
    for (int i = 0; i <= m; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        d[0][j] = j;
    }
    
    // Fill the rest of the matrix
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (str1[i-1] == str2[j-1]) {
                d[i][j] = d[i-1][j-1];  // Characters match
            } else {
                d[i][j] = min(
                    d[i-1][j] + 1,      // Deletion
                    d[i][j-1] + 1,      // Insertion
                    d[i-1][j-1] + 1     // Substitution
                );
            }
        }
    }
    
    // Print the distance matrix
    printMatrix(d, m, n);
    
    // Store the result
    int result = d[m][n];
    
    // Free the allocated memory
    for (int i = 0; i <= m; i++) {
        free(d[i]);
    }
    free(d);
    
    return result;
}

int main() {
    char str1[] = "kitten";
    char str2[] = "sitting";
    
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    
    int distance = levenshteinDistance(str1, str2);
    
    printf("\nLevenshtein Distance: %d\n", distance);
    
    return 0;
}