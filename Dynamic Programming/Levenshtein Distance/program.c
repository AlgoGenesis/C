#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate the minimum of three values
int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

// Function to calculate Levenshtein distance
int levenshteinDistance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // Create a 2D array to store distances
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize base cases
    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i; // Distance of any first string to an empty second string
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j; // Distance of any second string to an empty first string
    }

    // Fill the dp array
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match, no cost
            } else {
                dp[i][j] = min(
                    dp[i - 1][j] + 1,     // Deletion
                    dp[i][j - 1] + 1,     // Insertion
                    dp[i - 1][j - 1] + 1  // Substitution
                );
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
    const char *s1 = "kitten";
    const char *s2 = "sitting";

    printf("Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, levenshteinDistance(s1, s2));

    return 0;
}
