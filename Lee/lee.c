#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int x, y;
} Point;

int queue[MAX * MAX][2];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

void enqueue(int x, int y) {
    if (rear == MAX * MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear][0] = x;
    queue[rear][1] = y;
}

void dequeue(int *x, int *y) {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    *x = queue[front][0];
    *y = queue[front][1];
    front++;
    if (front > rear) {
        front = rear = -1;  // Reset the queue
    }
}

int isValid(int x, int y, int grid[MAX][MAX], int visited[MAX][MAX], int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 0 && !visited[x][y]);
}

void leeAlgorithm(int grid[MAX][MAX], int startX, int startY, int endX, int endY, int n, int m) {
    int visited[MAX][MAX] = {0};
    int distance[MAX][MAX] = {0};
    
    enqueue(startX, startY);
    visited[startX][startY] = 1;

    // Directions for movement: right, left, down, up
    int dirX[] = {0, 0, 1, -1};
    int dirY[] = {1, -1, 0, 0};

    while (!isEmpty()) {
        int x, y;
        dequeue(&x, &y);
        
        // Check if we reached the destination
        if (x == endX && y == endY) {
            printf("Shortest path found with distance: %d\n", distance[x][y]);
            return;
        }

        // Explore all possible movements
        for (int i = 0; i < 4; i++) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            if (isValid(newX, newY, grid, visited, n, m)) {
                visited[newX][newY] = 1;
                distance[newX][newY] = distance[x][y] + 1; // Correctly calculate distance
                enqueue(newX, newY);
            }
        }
    }

    printf("No path found from source to destination.\n");
}

int main() {
    int n, m;
    int grid[MAX][MAX];

    printf("Enter the dimensions of the grid (rows and columns): ");
    scanf("%d %d", &n, &m);

    printf("Enter the grid (0 for free cell, 1 for obstacle):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int startX, startY, endX, endY;
    printf("Enter the start point (x y): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter the end point (x y): ");
    scanf("%d %d", &endX, &endY);

    leeAlgorithm(grid, startX, startY, endX, endY, n, m);

    return 0;
}
