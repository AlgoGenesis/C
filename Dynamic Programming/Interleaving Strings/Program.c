#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isInterleave(char *A, char *B, char *C) {
    int lenA = strlen(A);
    int lenB = strlen(B);
    int lenC = strlen(C);

    // If lengths don't match, return false
    if (lenA + lenB != lenC) {
        return false;
    }

    // Create a DP table
    bool dp[lenA + 1][lenB + 1];
    memset(dp, false, sizeof(dp)); // Initialize the DP table to false
    dp[0][0] = true; // Base case

    // Fill the first row
    for (int j = 1; j <= lenB; j++) {
        dp[0][j] = dp[0][j - 1] && (B[j - 1] == C[j - 1]);
    }

    // Fill the first column
    for (int i = 1; i <= lenA; i++) {
        dp[i][0] = dp[i - 1][0] && (A[i - 1] == C[i - 1]);
    }

    // Fill the rest of the DP table
    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            dp[i][j] = (dp[i - 1][j] && (A[i - 1] == C[i + j - 1])) ||
                       (dp[i][j - 1] && (B[j - 1] == C[i + j - 1]));
        }
    }

    return dp[lenA][lenB];
}

int main() {
    char A[] = "aabcc";
    char B[] = "dbbca";
    char C[] = "aadbbcbcac";

    if (isInterleave(A, B, C)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}