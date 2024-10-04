#include <stdio.h>
#include <limits.h>

// Function to print the optimal parenthesis placement
void printOptimalParens(int s[][100], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

// Function to compute the matrix chain multiplication order
void matrixChainOrder(int p[], int n) {
    int m[100][100]; // m[i,j] will store the minimum number of multiplications needed for matrices Ai...Aj
    int s[100][100]; // s[i,j] will store the index at which the optimal split occurs

    // Initialize the diagonal to 0, as the cost of multiplying one matrix is 0
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // l is chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i <= n - l; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                // Cost of splitting at k
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    // Output the minimum cost
    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);

    // Output the optimal parenthesization
    printf("Optimal Parenthesization: ");
    printOptimalParens(s, 1, n - 1);
    printf("\n");
}
int main() {
    int n;

    // Input number of matrices
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[n + 1]; // Array to store matrix dimensions
    printf("Enter the dimensions of the matrices:\n");
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    // Call function to compute optimal matrix multiplication order
    matrixChainOrder(p, n + 1);

    return 0;
}
