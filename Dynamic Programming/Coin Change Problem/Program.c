#include <stdio.h>

// Function to find the number of ways to make change for a given amount
int coinChange(int coins[], int numCoins, int amount) {
    int dp[amount + 1]; // Array to store the number of ways to make change
    for (int i = 0; i <= amount; i++) {
        dp[i] = 0; // Initialize the dp array
    }
    dp[0] = 1; // Base case: One way to make zero amount

    // Iterate through each coin
    for (int i = 0; i < numCoins; i++) {
        // Update the dp array for amounts that can include the current coin
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount]; // Return the number of ways to make change for the given amount
}

int main() {
    int coins[] = {1, 2, 5}; // Coin denominations
    int amount = 5; // Target amount
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    int result = coinChange(coins, numCoins, amount);
    printf("Number of ways to make change for %d: %d\n", amount, result);

    return 0;
}
