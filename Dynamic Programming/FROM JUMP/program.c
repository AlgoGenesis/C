#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minEnergy(int n, int height[]) {
    int dp[n];  // Array to store the minimum energy for each stair
    dp[0] = 0;  // Starting point, so no energy required to be at the first stair

    // Fill the dp array from stair 1 to stair n-1
    for (int i = 1; i < n; i++) {
        int oneStep = dp[i - 1] + abs(height[i] - height[i - 1]);
        int twoStep = (i > 1) ? dp[i - 2] + abs(height[i] - height[i - 2]) : oneStep;

        dp[i] = min(oneStep, twoStep);  // Take the minimum of the two options
    }

    return dp[n - 1];  // Minimum energy required to reach the last stair
}

int main() {
    int n = 4;
    int height[] = {10, 20, 30, 10};

    int result = minEnergy(n, height);
    printf("Minimum energy required: %d\n", result);

    return 0;
}
