#include <stdio.h>
#include <string.h>

// Function to find the minimum of three values
int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

// Function to compute the edit distance between two strings
int editDistance(char str1[], char str2[], int m, int n) {
    // Create a DP table to store results of subproblems
    int dp[m + 1][n + 1];

    // Fill dp[][] in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If str1 is empty, all characters of str2 need to be inserted
            if (i == 0)
                dp[i][j] = j;
            
            // If str2 is empty, all characters of str1 need to be removed
            else if (j == 0)
                dp[i][j] = i;
            
            // If the characters are the same, no operation is required
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            
            // If characters are different, consider all operations and take the minimum
            else
                dp[i][j] = 1 + min(dp[i - 1][j],      // Remove
                                   dp[i][j - 1],      // Insert
                                   dp[i - 1][j - 1]); // Replace
        }
    }

    // Return the result from the bottom-right corner of the table
    return dp[m][n];
}

int main() {
    char str1[] = "sunday";
    char str2[] = "saturday";

    printf("Minimum number of operations to convert %s to %s is: %d\n", 
           str1, str2, editDistance(str1, str2, strlen(str1), strlen(str2)));

    return 0;
}