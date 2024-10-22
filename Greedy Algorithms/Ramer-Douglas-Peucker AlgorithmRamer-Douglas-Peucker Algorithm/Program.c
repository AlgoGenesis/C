#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double perpendicularDistance(Point p, Point start, Point end) {
    double area = fabs((end.y - start.y) * p.x - (end.x - start.x) * p.y + end.x * start.y - end.y * start.x);
    double base = sqrt(pow(end.y - start.y, 2) + pow(end.x - start.x, 2));
    return area / base;
}

void ramerDouglasPeucker(Point* points, int start, int end, double epsilon, int* resultIndices, int* resultCount) {
    if (end <= start + 1) {
        return;
    }

    double maxDistance = 0;
    int index = 0;

    for (int i = start + 1; i < end; i++) {
        double distance = perpendicularDistance(points[i], points[start], points[end]);
        if (distance > maxDistance) {
            maxDistance = distance;
            index = i;
        }
    }

    if (maxDistance > epsilon) {
        resultIndices[(*resultCount)++] = index;
        ramerDouglasPeucker(points, start, index, epsilon, resultIndices, resultCount);
        ramerDouglasPeucker(points, index, end, epsilon, resultIndices, resultCount);
    }
}

void simplify(Point* points, int pointCount, double epsilon) {
    int* resultIndices = (int*)malloc(pointCount * sizeof(int));
    int resultCount = 0;

    resultIndices[resultCount++] = 0; // Always include the first point
    ramerDouglasPeucker(points, 0, pointCount - 1, epsilon, resultIndices, &resultCount);
    resultIndices[resultCount++] = pointCount - 1; // Always include the last point

    printf("Simplified Points:\n");
    for (int i = 0; i < resultCount; i++) {
        printf("Point %d: (%.2f, %.2f)\n", resultIndices[i], points[resultIndices[i]].x, points[resultIndices[i]].y);
    }

    free(resultIndices);
}

int main() {
    Point points[] = {
        {0, 0},
        {1, 1},
        {2, 0},
        {3, 1},
        {4, 0},
        {5, 1},
        {6, 0}
    };
    int pointCount = sizeof(points) / sizeof(points[0]);
    double epsilon = 0.5; // Set tolerance

    simplify(points, pointCount, epsilon);

    return 0;
}
