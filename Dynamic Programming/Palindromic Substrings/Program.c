#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to count the number of palindromic substrings
int countPalindromicSubstrings(char* s) {
    int n = strlen(s);
    int count = 0;
    
    // Create a 2D table to store whether substrings are palindromic
    bool dp[n][n];
    
    // Initialize the dp table
    for (int i = 0; i < n; i++) {
        dp[i][i] = true; // Every single character is a palindrome
        count++;
    }

    // Check for palindromes of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            count++;
        } else {
            dp[i][i + 1] = false;
        }
    }

    // Check for palindromes of length greater than 2
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1; // Ending index
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                count++;
            } else {
                dp[i][j] = false;
            }
        }
    }

    return count;
}

int main() {
    char s[1000];
    printf("Enter a string: ");
    scanf("%s", s);

    int result = countPalindromicSubstrings(s);
    printf("Total palindromic substrings: %d\n", result);

    return 0;
}
