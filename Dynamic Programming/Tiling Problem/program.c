#include <stdio.h>

// Function to calculate the number of ways to tile a 2xN board
int tilingProblem(int n) {
    if (n == 1) return 1; // Only one way to place a tile vertically
    if (n == 2) return 2; // Two ways: two vertical tiles or two horizontal tiles

    int dp[n + 1]; // Array to store the number of ways for each subproblem
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    printf("Enter the length of the board (N): ");
    scanf("%d", &n);

    int ways = tilingProblem(n);
    printf("Number of ways to tile a 2x%d board is: %d\n", n, ways);

    return 0;
}
