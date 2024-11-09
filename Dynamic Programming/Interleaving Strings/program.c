#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isInterleave(char* A, char* B, char* C) {
    int n = strlen(A);
    int m = strlen(B);
    int lenC = strlen(C);

    if (n + m != lenC) {
        return false;
    }

    bool dp[n + 1][m + 1];

    dp[0][0] = true;  // Empty A and B to form empty C is true

    for (int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j - 1] && (B[j - 1] == C[j - 1]);
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] && (A[i - 1] == C[i - 1]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i - 1][j] && A[i - 1] == C[i + j - 1]) ||
                       (dp[i][j - 1] && B[j - 1] == C[i + j - 1]);
        }
    }

    return dp[n][m];
}

int main() {
    char A[] = "aab";
    char B[] = "axy";
    char C[] = "aaxaby";

    if (isInterleave(A, B, C)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
