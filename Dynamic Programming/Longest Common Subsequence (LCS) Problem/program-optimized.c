#include <stdio.h>
#include <string.h>

// Function to find the length of the Longest Common Subsequence
int lcs(char *X, char *Y, int m, int n) {
    // Determine the smaller dimension to minimize space usage
    if (m < n) {
        char *temp = X;
        X = Y;
        Y = temp;
        int temp_size = m;
        m = n;
        n = temp_size;
    }

    // Only two rows are needed for space optimization
    int prev[n + 1];
    int curr[n + 1];
    
    // Initialize the arrays
    memset(prev, 0, sizeof(prev));
    memset(curr, 0, sizeof(curr));

    // Build the LCS array in a bottom-up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                curr[j] = prev[j - 1] + 1;
            else
                curr[j] = (prev[j] > curr[j - 1]) ? prev[j] : curr[j];
        }

        // Swap rows for the next iteration
        memcpy(prev, curr, sizeof(curr));
    }

    // The length of LCS is now in the last cell of `prev` array
    return prev[n];
}

// Driver code
int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Length of LCS is %d\n", lcs(X, Y, m, n));

    return 0;
}
