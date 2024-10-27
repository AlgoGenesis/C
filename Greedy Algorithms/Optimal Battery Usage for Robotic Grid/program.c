#include <stdio.h>

#define MAX_SIZE 10 // Maximum grid size

// Function to display the grid
void displayGrid(int grid[MAX_SIZE][MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to find the optimal path
int optimizePath(int grid[MAX_SIZE][MAX_SIZE], int size, int x, int y)
{
    // Base case: If robot reaches the bottom-right corner
    if (x == size - 1 && y == size - 1)
    {
        printf("Reached destination at (%d, %d)\n", x, y);
        return 1; // Return 1 to indicate a valid path found
    }

    // Move right if possible
    if (y + 1 < size)
    {
        printf("Moving to (%d, %d)\n", x, y + 1);
        if (optimizePath(grid, size, x, y + 1))
        {
            return 1; // Return 1 if path is found
        }
    }

    // Move down if possible
    if (x + 1 < size)
    {
        printf("Moving to (%d, %d)\n", x + 1, y);
        if (optimizePath(grid, size, x + 1, y))
        {
            return 1; // Return 1 if path is found
        }
    }

    return 0; // Return 0 if no path is found
}

int main()
{
    int grid[MAX_SIZE][MAX_SIZE];
    int size;

    // Get grid size from user
    printf("Enter grid size (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Validate grid size
    if (size <= 0 || size > MAX_SIZE)
    {
        printf("Invalid grid size!\n");
        return 1;
    }

    // Get grid values from user
    printf("Enter grid values (0 for free, 1 for obstacle):\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    // Display the grid
    printf("Grid:\n");
    displayGrid(grid, size);

    // Check if the start or end point is blocked
    if (grid[0][0] == 1 || grid[size - 1][size - 1] == 1)
    {
        printf("Start or destination is blocked!\n");
        return 1;
    }

    // Start optimizing path from (0, 0)
    printf("Starting optimization from (0, 0):\n");
    if (!optimizePath(grid, size, 0, 0))
    {
        printf("No valid path found.\n");
    }

    return 0;
}
