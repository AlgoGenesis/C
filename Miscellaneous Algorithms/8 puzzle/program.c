#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define MAX 100000

// To store the x and y positions for the blank tile (0)
typedef struct {
    int x, y;
} Position;

// Node to store each state of the puzzle
typedef struct Node {
    int puzzle[N][N];
    Position blank;
    struct Node* parent;
} Node;

// A queue to store nodes for BFS
typedef struct {
    Node* nodes[MAX];
    int front, rear;
} Queue;

Queue queue;

// Goal state of the puzzle
int goal[N][N] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

// Directions for moving the blank tile (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Initialize the queue
void initQueue() {
    queue.front = 0;
    queue.rear = 0;
}

// Check if the queue is empty
int isEmpty() {
    return queue.front == queue.rear;
}

// Enqueue a node
void enqueue(Node* node) {
    queue.nodes[queue.rear++] = node;
}

// Dequeue a node
Node* dequeue() {
    return queue.nodes[queue.front++];
}

// Check if two puzzles are equal
int isGoal(int puzzle[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (puzzle[i][j] != goal[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// Print the puzzle
void printPuzzle(int puzzle[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Check if the given position is valid
int isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Create a new node for the puzzle state
Node* createNode(int puzzle[N][N], Position blank, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    memcpy(newNode->puzzle, puzzle, sizeof(newNode->puzzle));
    newNode->blank = blank;
    newNode->parent = parent;
    return newNode;
}

// BFS to solve the 8-puzzle problem
void solve(int start[N][N]) {
    initQueue();
    Position blank;

    // Find the blank position in the start state
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (start[i][j] == 0) {
                blank.x = i;
                blank.y = j;
            }
        }
    }

    Node* root = createNode(start, blank, NULL);
    enqueue(root);

    while (!isEmpty()) {
        Node* current = dequeue();
        if (isGoal(current->puzzle)) {
            printf("Solution found:\n");
            printPuzzle(current->puzzle);
            return;
        }

        // Try moving the blank tile in all possible directions
        for (int i = 0; i < 4; i++) {
            int newX = current->blank.x + dx[i];
            int newY = current->blank.y + dy[i];

            if (isValid(newX, newY)) {
                int newPuzzle[N][N];
                memcpy(newPuzzle, current->puzzle, sizeof(newPuzzle));

                // Swap the blank with the adjacent tile
                newPuzzle[current->blank.x][current->blank.y] = newPuzzle[newX][newY];
                newPuzzle[newX][newY] = 0;

                Position newBlank = {newX, newY};
                Node* newNode = createNode(newPuzzle, newBlank, current);
                enqueue(newNode);
            }
        }
    }

    printf("No solution found.\n");
}

int main() {
    int start[N][N] = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}
    };

    printf("Initial state:\n");
    printPuzzle(start);
    solve(start);

    return 0;
}
