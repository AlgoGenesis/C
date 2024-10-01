#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications
int matrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;

    // Initialize the diagonal of the matrix to 0 (single matrix case)
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                // Calculate q = cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1]; // Return the minimum cost for multiplying all matrices
}

// Driver code
int main() {
    int arr[] = {40, 20, 30, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications is %d\n", matrixChainOrder(arr, size));

    return 0;
}
