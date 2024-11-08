#include <stdio.h>

#define MOD 1000000007

int numTilings(int n) {
    // Edge cases
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;

    long long dp[n + 1];
    dp[0] = 1; // 1 way to tile a 2 x 0 board
    dp[1] = 1; // 1 way to tile a 2 x 1 board
    dp[2] = 2; // 2 ways to tile a 2 x 2 board

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + 2 * dp[i - 3]) % MOD;
    }

    return dp[n];
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int result = numTilings(n);
    printf("Number of ways to tile a 2 x %d board: %d\n", n, result);

    return 0;
}