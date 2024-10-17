#include <stdio.h>
#include <string.h>

// Function to find the shortest common supersequence
char* shortestSupersequence(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);

    // DP table for storing the length of the LCS
    int dp[n + 1][m + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    // To store the result supersequence
    static char result[1000];
    int index = 0;

    // Start from the bottom-right corner of the DP table
    int i = n, j = m;
    while (i > 0 && j > 0) {
        // If characters are the same, it's part of LCS
        if (s1[i - 1] == s2[j - 1]) {
            result[index++] = s1[i - 1];
            i--;
            j--;
        }
        // Otherwise, move in the direction of the larger value
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            result[index++] = s1[i - 1];
            i--;
        } else {
            result[index++] = s2[j - 1];
            j--;
        }
    }

    // Add remaining characters of s1 and s2
    while (i > 0) {
        result[index++] = s1[i - 1];
        i--;
    }
    while (j > 0) {
        result[index++] = s2[j - 1];
        j--;
    }

    // Reverse the result string
    result[index] = '\0';
    for (int k = 0; k < index / 2; k++) {
        char temp = result[k];
        result[k] = result[index - k - 1];
        result[index - k - 1] = temp;
    }

    return result;
}

int main() {
    char s1[] = "brute";
    char s2[] = "groot";

    printf("The Shortest Common Supersequence is: %s\n", shortestSupersequence(s1, s2));
    return 0;
}
