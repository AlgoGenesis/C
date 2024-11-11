#include <stdio.h>
#include <string.h>

#define MAX_DICE 100
#define MAX_SUM 1000
#define FACES 6  // Number of faces on each die, can be adjusted as needed

// DP table to store the number of ways to get each sum with a given number of dice
int dp[MAX_DICE + 1][MAX_SUM + 1];

int diceRollSum(int n, int target) {
    // Initialize the DP table with zeros
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;  // Base case: 1 way to get sum 0 with 0 dice
    
    for (int i = 1; i <= n; i++) {  // For each dice count
        for (int j = 1; j <= target; j++) {  // For each possible sum
            dp[i][j] = 0;
            for (int face = 1; face <= FACES; face++) {  // For each face value
                if (j - face >= 0) {  // Ensure sum is non-negative
                    dp[i][j] += dp[i - 1][j - face];
                }
            }
        }
    }
    
    return dp[n][target];
}

int main() {
    int n, target;
    printf("Enter number of dice: ");
    scanf("%d", &n);
    printf("Enter target sum: ");
    scanf("%d", &target);

    int result = diceRollSum(n, target);
    printf("Number of ways to reach the target sum %d with %d dice: %d\n", target, n, result);

    return 0;
}
