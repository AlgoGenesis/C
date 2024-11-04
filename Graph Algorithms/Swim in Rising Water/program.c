#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int **arr;
int n;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// Function to perform BFS traversal
bool helper(int x) {
    if (arr[0][0] > x) return false;

    int **visited = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        visited[i] = (int *)calloc(n, sizeof(int));
    }

    int queue[n * n][2];
    int front = 0, rear = 0;
    queue[rear][0] = 0;
    queue[rear++][1] = 0;
    visited[0][0] = 1;

    while (front < rear) {
        int r = queue[front][0];
        int c = queue[front++][1];

        if (r == n - 1 && c == n - 1) 
        {
            for (int i = 0; i < n; i++) {
                free(visited[i]);
            }
            free(visited);
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && visited[nr][nc] == 0 && arr[nr][nc] <= x) {
                queue[rear][0] = nr;
                queue[rear++][1] = nc;
                visited[nr][nc] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(visited[i]);
    }
    free(visited);

    return false;
}

// Main function to solve the swim in water problem
int swimInWater(int **grid, int gridSize) {
    arr = grid;
    n = gridSize;
    int st = 0, end = 2505, ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (helper(mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }
    return ans;
}

// Main function
int main() {
    printf("Enter the grid size (n x n): ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the grid elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int result = swimInWater(arr, n);
    printf("Minimum time to swim to the bottom-right corner: %d\n", result);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
