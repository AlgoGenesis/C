#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the minimum of three numbers
int min(int x, int y, int z) {
    return (x < y) ? (x < z ? x : z) : (y < z ? y : z);
}

// Function to find the Edit Distance (Levenshtein Distance) between two strings
int editDistance(char *str1, char *str2, int m, int n) {
    // Create a 2D array to store the edit distances
    int dp[m + 1][n + 1];

    // Fill the dp array in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, the only option is to insert all characters of the second string
            if (i == 0)
                dp[i][j] = j; // Insert all characters of str2 into str1

            // If second string is empty, the only option is to remove all characters of the first string
            else if (j == 0)
                dp[i][j] = i; // Remove all characters of str1

            // If last characters are the same, no cost is needed, move to the next characters
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If last characters are different, consider all three operations and find the minimum
            else
                dp[i][j] = 1 + min(dp[i][j - 1],     // Insert
                                   dp[i - 1][j],     // Remove
                                   dp[i - 1][j - 1]);// Replace
        }
    }

    return dp[m][n]; // Return the final edit distance
}

int main() {
    char str1[] = "kitten";
    char str2[] = "sitting";

    int m = strlen(str1);
    int n = strlen(str2);

    printf("Edit Distance between '%s' and '%s' is %d\n", str1, str2, editDistance(str1, str2, m, n));

    return 0;
}
