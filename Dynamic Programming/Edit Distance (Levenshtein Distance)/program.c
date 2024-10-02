#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Create a 2D array to store distances
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the first row and column
    for (int i = 0; i <= len1; i++) dp[i][0] = i; // Deletion
    for (int j = 0; j <= len2; j++) dp[0][j] = j; // Insertion

    // Fill the dp array
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No change
            } else {
                dp[i][j] = min(dp[i - 1][j] + 1,      // Deletion
                               dp[i][j - 1] + 1,      // Insertion
                               dp[i - 1][j - 1] + 1); // Substitution
            }
        }
    }

    int distance = dp[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);

    return distance;
}

int main() {
    const char *str1 = "kitten";
    const char *str2 = "sitting";
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance: %d\n", distance);
    return 0;
}
