// tsp.c

#include <stdio.h>
#include <limits.h>

#define N 4 // Number of cities

// Distance matrix
int dist[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

// DP table to store results
int dp[1 << N][N]; // 1 << N represents 2^N, all possible subsets of cities

// Function to solve TSP using Dynamic Programming and Bit Masking
int tsp(int mask, int pos) {
    // Base case: all cities have been visited
    if (mask == (1 << N) - 1) {
        return dist[pos][0]; // Return distance to the starting city
    }

    // If this subproblem has already been solved, return the stored result
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    // Initialize the result to infinity
    int ans = INT_MAX;

    // Try to go to all other cities that are not yet visited
    for (int city = 0; city < N; city++) {
        // If city is not visited in this mask
        if ((mask & (1 << city)) == 0) {
            // Calculate the new result
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = (newAns < ans) ? newAns : ans;
        }
    }

    // Store the result in the DP table and return it
    return dp[mask][pos] = ans;
}

int main() {
    // Initialize the DP table with -1 (unvisited states)
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    // Start the TSP from city 0 with only city 0 visited (mask = 1)
    int result = tsp(1, 0);

    printf("The minimum cost of the TSP tour is: %d\n", result);

    return 0;
}
