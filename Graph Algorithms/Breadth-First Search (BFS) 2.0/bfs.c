#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];
int graph[MAX][MAX], n;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int value = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return value;
    }
}

void bfs(int start) {
    enqueue(start);
    visited[start] = 1;

    while (front != -1) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    // Example graph input
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(start);
    return 0;
}
