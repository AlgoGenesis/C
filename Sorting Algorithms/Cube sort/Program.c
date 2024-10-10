#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x, y, z; // Coordinates in 3D space
} Point;

// Comparison function for sorting

int compare(const void *a, const void *b) {
    Point *pointA = (Point *)a;
    Point *pointB = (Point *)b;
    if (pointA->x != pointB->x)
        return (pointA->x > pointB->x) ? 1 : -1;
    if (pointA->y != pointB->y)
        return (pointA->y > pointB->y) ? 1 : -1;
    return (pointA->z > pointB->z) ? 1 : -1;
}

// Cube Sort Function
void cubeSort(Point *points, int n) {
    qsort(points, n, sizeof(Point), compare);
}

int main() {
    Point points[] = {
        {1.0, 2.0, 3.0},
        {0.5, 0.5, 0.5},
        {1.5, 1.0, 1.0},
        {0.0, 2.5, 1.0},
        {1.0, 1.0, 0.0}
    };
    
    int n = sizeof(points) / sizeof(points[0]);

    printf("Points before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("(%f, %f, %f)\n", points[i].x, points[i].y, points[i].z);
    }

    cubeSort(points, n);

    printf("\nPoints after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("(%f, %f, %f)\n", points[i].x, points[i].y, points[i].z);
    }

    return 0;
}
