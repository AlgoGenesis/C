#include <stdio.h>
#include <stdlib.h>

// Structure to store the coordinates of a cell in the grid
typedef struct {
    int x, y;
} Cell;

// Structure for the queue used in BFS
typedef struct {
    Cell *data;
    int front, rear, size;
} Queue;

// Initialize a queue
Queue* createQueue(int size) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (Cell *)malloc(size * sizeof(Cell));
    queue->front = 0;
    queue->rear = 0;
    queue->size = size;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == queue->rear;
}

// Enqueue a cell to the queue
void enqueue(Queue *queue, Cell cell) {
    queue->data[queue->rear++] = cell;
}

// Dequeue a cell from the queue
Cell dequeue(Queue *queue) {
    return queue->data[queue->front++];
}

// Directions for the 4 neighboring cells (up, down, left, right)
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Function to check if a cell is within the grid bounds and contains a fresh orange
int isValid(int x, int y, int rows, int cols, int grid[rows][cols]) {
    return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1);
}

// Function to find the minimum time to rot all oranges
int minTimeToRot(int rows, int cols, int grid[rows][cols]) {
    Queue *queue = createQueue(rows * cols);
    int freshCount = 0;
    
    // Enqueue all rotten oranges and count fresh oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                enqueue(queue, (Cell){i, j});
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }
    
    // If there are no fresh oranges, return 0
    if (freshCount == 0) {
        return 0;
    }
    
    int minutes = 0;
    
    // Perform BFS to rot all fresh oranges
    while (!isEmpty(queue)) {
        int size = queue->rear - queue->front;
        int rottingOccurred = 0;
        
        // Process all rotten oranges for the current minute
        for (int i = 0; i < size; i++) {
            Cell current = dequeue(queue);
            
            for (int d = 0; d < 4; d++) {
                int newX = current.x + directions[d][0];
                int newY = current.y + directions[d][1];
                
                // If the neighboring cell is a fresh orange, rot it
                if (isValid(newX, newY, rows, cols, grid)) {
                    grid[newX][newY] = 2;
                    enqueue(queue, (Cell){newX, newY});
                    freshCount--;
                    rottingOccurred = 1;
                }
            }
        }
        
        // If any fresh oranges rotted in this minute, increment the time
        if (rottingOccurred) {
            minutes++;
        }
    }
    
    // If there are still fresh oranges left, return -1
    return freshCount == 0 ? minutes : -1;
}

int main() {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int grid[rows][cols];
    printf("Enter the grid (0 for empty, 1 for fresh orange, 2 for rotten orange):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    int result = minTimeToRot(rows, cols, grid);
    if (result == -1) {
        printf("All fresh oranges cannot rot.\n");
    } else {
        printf("Minimum time to rot all oranges: %d minutes\n", result);
    }
    
    return 0;
}
