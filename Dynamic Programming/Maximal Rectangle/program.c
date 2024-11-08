#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrix == NULL || matrixSize == 0 || matrixColSize[0] == 0) {
        return 0;
    }
    
    int m = matrixSize;
    int n = matrixColSize[0];

    int* heights = (int*)calloc(n, sizeof(int));
    int* leftBoundaries = (int*)calloc(n, sizeof(int));
    int* rightBoundaries = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        rightBoundaries[i] = n;
    }

    int maxRectangle = 0;

    for (int i = 0; i < m; i++) {
        int left = 0;
        int right = n;

        updateHeightsAndLeftBoundaries(matrix[i], heights, leftBoundaries, n, &left);

        updateRightBoundaries(matrix[i], rightBoundaries, n, &right);

        maxRectangle = calculateMaxRectangle(heights, leftBoundaries, rightBoundaries, n, maxRectangle);
    }

    free(heights);
    free(leftBoundaries);
    free(rightBoundaries);

    return maxRectangle;
}

void updateHeightsAndLeftBoundaries(char* row, int* heights, int* leftBoundaries, int n, int* left) {
    for (int j = 0; j < n; j++) {
        if (row[j] == '1') {
            heights[j]++;
            leftBoundaries[j] = leftBoundaries[j] > *left ? leftBoundaries[j] : *left;
        } else {
            heights[j] = 0;
            leftBoundaries[j] = 0;
            *left = j + 1;
        }
    }
}

void updateRightBoundaries(char* row, int* rightBoundaries, int n, int* right) {
    for (int j = n - 1; j >= 0; j--) {
        if (row[j] == '1') {
            rightBoundaries[j] = rightBoundaries[j] < *right ? rightBoundaries[j] : *right;
        } else {
            rightBoundaries[j] = n;
            *right = j;
        }
    }
}

int calculateMaxRectangle(int* heights, int* leftBoundaries, int* rightBoundaries, int n, int maxRectangle) {
    for (int j = 0; j < n; j++) {
        int width = rightBoundaries[j] - leftBoundaries[j];
        int area = heights[j] * width;
        maxRectangle = maxRectangle > area ? maxRectangle : area;
    }
    return maxRectangle;
}
