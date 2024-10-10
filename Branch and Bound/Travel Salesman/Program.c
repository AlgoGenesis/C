#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX 100  // Maximum number of cities

int final_path[MAX + 1];
int visited[MAX];
int final_res = INT_MAX;

// Function to copy the current path to the final path
void copyToFinal(int curr_path[], int N) {
    for (int i = 0; i < N; i++)
        final_path[i] = curr_path[i];
    final_path[N] = curr_path[0];  // Completing the tour by returning to the start
}

// Function to find the minimum edge cost ending at vertex i
int firstMin(int adj[MAX][MAX], int i, int N) {
    int min = INT_MAX;
    for (int k = 0; k < N; k++) {
        if (adj[i][k] < min && i != k) {
            min = adj[i][k];
        }
    }
    return min;
}

// Function to find the second minimum edge cost ending at vertex i
int secondMin(int adj[MAX][MAX], int i, int N) {
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < N; j++) {
        if (i == j)
            continue;

        if (adj[i][j] <= first) {
            second = first;
            first = adj[i][j];
        } else if (adj[i][j] <= second && adj[i][j] != first) {
            second = adj[i][j];
        }
    }
    return second;
}

// Recursive function to explore paths using Branch and Bound
void TSPRec(int adj[MAX][MAX], int curr_bound, int curr_weight, int level, int curr_path[], int N) {
    // Base case: if we have reached the last level
    if (level == N) {
        if (adj[curr_path[level - 1]][curr_path[0]] != 0) {
            int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];

            if (curr_res < final_res) {
                copyToFinal(curr_path, N);
                final_res = curr_res;
            }
        }
        return;
    }

    // Explore further by trying every unvisited vertex
    for (int i = 0; i < N; i++) {
        if (adj[curr_path[level - 1]][i] != 0 && visited[i] == 0) {
            int temp = curr_bound;
            curr_weight += adj[curr_path[level - 1]][i];

            if (level == 1) {
                curr_bound -= (firstMin(adj, curr_path[level - 1], N) + firstMin(adj, i, N)) / 2;
            } else {
                curr_bound -= (secondMin(adj, curr_path[level - 1], N) + firstMin(adj, i, N)) / 2;
            }

            if (curr_bound + curr_weight < final_res) {
                curr_path[level] = i;
                visited[i] = 1;

                // Recursive call for the next level
                TSPRec(adj, curr_bound, curr_weight, level + 1, curr_path, N);
            }

            // Backtrack
            curr_weight -= adj[curr_path[level - 1]][i];
            curr_bound = temp;
            memset(visited, 0, sizeof(visited));
            for (int j = 0; j <= level - 1; j++) {
                visited[curr_path[j]] = 1;
            }
        }
    }
}

// Function to initiate TSP solving
void TSP(int adj[MAX][MAX], int N) {
    int curr_path[MAX + 1];
    int curr_bound = 0;

    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++) {
        curr_bound += (firstMin(adj, i, N) + secondMin(adj, i, N));
    }

    curr_bound = (curr_bound % 2 == 1) ? curr_bound / 2 + 1 : curr_bound / 2;

    visited[0] = 1;
    curr_path[0] = 0;

    TSPRec(adj, curr_bound, 0, 1, curr_path, N);
}

// Driver code
int main() {
    int N;  // Number of cities

    printf("Enter the number of cities: ");
    scanf("%d", &N);

    int adj[MAX][MAX];

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (distance between cities, use 0 for no direct path):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Distance from city %d to city %d: ", i + 1, j + 1);
            scanf("%d", &adj[i][j]);
        }
    }

    // Solve TSP
    TSP(adj, N);

    // Output the result
    printf("Minimum cost: %d\n", final_res);
    printf("Path Taken: ");
    for (int i = 0; i <= N; i++) {
        printf("%d ", final_path[i] + 1);  // Adding 1 to display city numbers starting from 1
    }

    return 0;
}
