#include <stdio.h>

// Function to find the maximum profit for rod cutting problem using Dynamic Programming
int rodCutting(int price[], int n) {
    // dp[i] represents the maximum value obtainable for a rod of length i
    int dp[n + 1];
    dp[0] = 0;

    // Build the dp array in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        int max_val = -1;
        // Cut the rod at every possible length and compare
        for (int j = 0; j < i; j++) {
            max_val = (price[j] + dp[i - j - 1] > max_val) ? (price[j] + dp[i - j - 1]) : max_val;
        }
        dp[i] = max_val;
    }

    return dp[n];
}

int main() {
    int length;
    printf("Enter the length of the rod: ");
    scanf("%d", &length);

    int price[length];
    printf("Enter the prices of pieces for each length from 1 to %d:\n", length);
    for (int i = 0; i < length; i++) {
        scanf("%d", &price[i]);
    }

    int max_profit = rodCutting(price, length);
    printf("Maximum profit obtainable from a rod of length %d is: %d\n", length, max_profit);

    return 0;
}
