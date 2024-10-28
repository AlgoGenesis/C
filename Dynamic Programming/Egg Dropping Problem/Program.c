#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of attempts needed to find the critical floor
int eggDrop(int eggs, int floors) {
    // dp[i][j] will represent the minimum number of attempts needed for i eggs and j floors
    int dp[eggs + 1][floors + 1];

    // If there are no floors, zero attempts are needed
    for (int i = 0; i <= eggs; i++) {
        dp[i][0] = 0;
    }

    // If there is one floor, one attempt is needed
    for (int j = 0; j <= floors; j++) {
        dp[1][j] = j;
    }

    // Fill the dp table using the optimal substructure property
    for (int i = 2; i <= eggs; i++) {
        for (int j = 1; j <= floors; j++) {
            dp[i][j] = INT_MAX; // Initialize with a large number

            // Try dropping an egg from each floor and choose the minimum of the worst-case scenarios
            for (int x = 1; x <= j; x++) {
                int res = 1 + (dp[i - 1][x - 1] > dp[i][j - x] ? dp[i - 1][x - 1] : dp[i][j - x]);
                dp[i][j] = dp[i][j] < res ? dp[i][j] : res;
            }
        }
    }

    return dp[eggs][floors];
}

int main() {
    int eggs, floors;
    printf("Enter the number of eggs: ");
    scanf("%d", &eggs);
    printf("Enter the number of floors: ");
    scanf("%d", &floors);

    int minAttempts = eggDrop(eggs, floors);
    printf("Minimum number of attempts needed: %d\n", minAttempts);

    return 0;
}
