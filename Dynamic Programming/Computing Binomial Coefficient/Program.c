#include <stdio.h>
#include<stdlib.h>

int binomialCoeff(int n, int k, int t[100][100]) {
    // If the value is already calculated, return it
    if (t[n][k] != -1)
        return t[n][k];

    // Base cases: C(n, 0) = 1 and C(n, n) = 1
    if (k == 0 || k == n) {
        t[n][k] = 1;
        return t[n][k];
    }

    // Recursive case: C(n, k) = C(n-1, k-1) + C(n-1, k)
    t[n][k] = binomialCoeff(n-1, k-1, t) + binomialCoeff(n-1, k, t);
    
    return t[n][k];
}

int main() {
    int n, k;
    int t[100][100];

    printf("Enter n and k for C(n, k):\n");
    scanf("%d %d", &n, &k);

    // Initialize the table with -1 (indicating uncalculated values)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            t[i][j] = -1;
        }
    }

    // Compute the binomial coefficient
    int result = binomialCoeff(n, k, t);

    printf("C(%d, %d) = %d\n", n, k, result);

    return 0;
}
