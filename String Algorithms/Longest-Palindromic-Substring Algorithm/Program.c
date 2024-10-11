#include <stdio.h>
#include <string.h>

// Function to find the longest palindromic substring
void longestPalindrome(const char* str) {
    int n = strlen(str);
    int dp[n][n];  // DP table to store results of subproblems
    memset(dp, 0, sizeof(dp));

    int maxLength = 1; // The minimum length of palindrome is 1 (single character)
    int start = 0; // To store the starting index of the longest palindrome

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            dp[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    // Check for substrings longer than 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;  // Ending index of current substring

            // If str[i] and str[j] are equal and the middle substring is a palindrome
            if (str[i] == str[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;

                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }
    }

    // Output the result
    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLength; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;  // Remove newline character
    
    longestPalindrome(str);
    
    return 0;
}
