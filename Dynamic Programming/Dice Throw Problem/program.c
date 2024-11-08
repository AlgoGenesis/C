#include <stdio.h>

int countWays(int n, int m, int X) {
    int dp[n + 1][X + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= X; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= X; j++) {
            for (int k = 1; k <= m && k <= j; k++) {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    return dp[n][X];
}

int main() {
    int n = 3;  // Number of dice
    int m = 6;  // Number of faces on each die
    int X = 8;  // Desired sum
    int ways = countWays(n, m, X);
    printf("Number of ways to get sum %d with %d dice: %d\n", X, n, ways);
    return 0;
}
