#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if a string matches a pattern using DP
bool isMatch(const char *text, const char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);

    // DP table where dp[i][j] is true if text[0..i-1] matches pattern[0..j-1]
    bool dp[textLen + 1][patternLen + 1];

    // Initialize the DP table
    memset(dp, false, sizeof(dp));
    dp[0][0] = true; // Empty pattern matches empty text

    // Handle patterns like a*, a*b*, a*b*c* where '*' can match zero elements
    for (int j = 1; j <= patternLen; j++) {
        if (pattern[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= textLen; i++) {
        for (int j = 1; j <= patternLen; j++) {
            if (pattern[j - 1] == '.' || pattern[j - 1] == text[i - 1]) {
                // If current characters match or pattern has '.', inherit the result
                dp[i][j] = dp[i - 1][j - 1];
            } else if (pattern[j - 1] == '*') {
                // '*' can match zero of the preceding element
                dp[i][j] = dp[i][j - 2];
                // Or '*' can match one or more of the preceding element
                if (pattern[j - 2] == '.' || pattern[j - 2] == text[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }

    // Final answer
    return dp[textLen][patternLen];
}

int main() {
    const char *text = "aab";
    const char *pattern = "c*a*b";

    if (isMatch(text, pattern)) {
        printf("The pattern matches the text.\n");
    } else {
        printf("The pattern does not match the text.\n");
    }

    return 0;
}
