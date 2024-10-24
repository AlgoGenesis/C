#include <stdio.h>
#include <stdlib.h>

// Structure to represent a building
struct Building {
    int left;   // Left x-coordinate
    int right;  // Right x-coordinate
    int height; // Height of the building
};

// Structure to represent a skyline point (x, height)
struct Point {
    int x;      // x-coordinate
    int height; // height at that x
};

// Function to merge two skylines
struct Point* mergeSkylines(struct Point* leftSkyline, int leftSize, struct Point* rightSkyline, int rightSize, int* mergedSize) {
    int leftIndex = 0, rightIndex = 0;
    int currentLeftHeight = 0, currentRightHeight = 0;
    int maxHeight = 0;
    *mergedSize = 0;
    struct Point* mergedSkyline = (struct Point*)malloc((leftSize + rightSize) * sizeof(struct Point));

    while (leftIndex < leftSize && rightIndex < rightSize) {
        int x = 0;

        if (leftSkyline[leftIndex].x < rightSkyline[rightIndex].x) {
            x = leftSkyline[leftIndex].x;
            currentLeftHeight = leftSkyline[leftIndex].height;
            leftIndex++;
        } else if (leftSkyline[leftIndex].x > rightSkyline[rightIndex].x) {
            x = rightSkyline[rightIndex].x;
            currentRightHeight = rightSkyline[rightIndex].height;
            rightIndex++;
        } else {
            x = leftSkyline[leftIndex].x;
            currentLeftHeight = leftSkyline[leftIndex].height;
            currentRightHeight = rightSkyline[rightIndex].height;
            leftIndex++;
            rightIndex++;
        }

        maxHeight = currentLeftHeight > currentRightHeight ? currentLeftHeight : currentRightHeight;

        if (*mergedSize == 0 || mergedSkyline[*mergedSize - 1].height != maxHeight) {
            mergedSkyline[*mergedSize].x = x;
            mergedSkyline[*mergedSize].height = maxHeight;
            (*mergedSize)++;
        }
    }

    while (leftIndex < leftSize) {
        mergedSkyline[*mergedSize] = leftSkyline[leftIndex];
        (*mergedSize)++;
        leftIndex++;
    }

    while (rightIndex < rightSize) {
        mergedSkyline[*mergedSize] = rightSkyline[rightIndex];
        (*mergedSize)++;
        rightIndex++;
    }

    return mergedSkyline;
}

// Recursive function to find the skyline for a set of buildings
struct Point* findSkyline(struct Building* buildings, int start, int end, int* skylineSize) {
    if (start == end) {
        struct Point* skyline = (struct Point*)malloc(2 * sizeof(struct Point));
        skyline[0].x = buildings[start].left;
        skyline[0].height = buildings[start].height;
        skyline[1].x = buildings[start].right;
        skyline[1].height = 0;
        *skylineSize = 2;
        return skyline;
    }

    int mid = (start + end) / 2;
    int leftSize = 0, rightSize = 0;
    struct Point* leftSkyline = findSkyline(buildings, start, mid, &leftSize);
    struct Point* rightSkyline = findSkyline(buildings, mid + 1, end, &rightSize);

    return mergeSkylines(leftSkyline, leftSize, rightSkyline, rightSize, skylineSize);
}

int main() {
    int n;

    // Ask the user for the number of buildings
    printf("Enter the number of buildings: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the buildings
    struct Building* buildings = (struct Building*)malloc(n * sizeof(struct Building));

    // Input the details for each building
    for (int i = 0; i < n; i++) {
        printf("Enter left x-coordinate, right x-coordinate, and height for building %d: ", i + 1);
        scanf("%d %d %d", &buildings[i].left, &buildings[i].right, &buildings[i].height);
    }

    int skylineSize = 0;

    // Find the skyline for the given buildings
    struct Point* skyline = findSkyline(buildings, 0, n - 1, &skylineSize);

    // Print the resulting skyline
    printf("Skyline:\n");
    for (int i = 0; i < skylineSize; i++) {
        printf("(%d, %d)\n", skyline[i].x, skyline[i].height);
    }

    // Free the allocated memory
    free(skyline);
    free(buildings);

    return 0;
}
