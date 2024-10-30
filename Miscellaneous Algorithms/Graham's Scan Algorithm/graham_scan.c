#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    int x, y;
} Point;

Point p0;

// Function to swap two points
void swap(Point *p1, Point *p2) {
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Function to return the next-to-top point in stack
Point nextToTop(Point stack[], int *top) {
    return stack[*top - 1];
}

// Function to calculate the square of the Euclidean distance
int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Orientation function: 0 = collinear, 1 = clockwise, 2 = counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Comparison function for qsort
int compare(const void *vp1, const void *vp2) {
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
    return (o == 2) ? -1 : 1;
}

// Function to find the convex hull of a set of points
void convexHull(Point points[], int n) {
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < ymin) || (ymin == points[i].y && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }
    swap(&points[0], &points[min]);
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    Point stack[n];
    int top = -1;
    stack[++top] = points[0];
    stack[++top] = points[1];
    stack[++top] = points[2];

    for (int i = 3; i < n; i++) {
        while (orientation(nextToTop(stack, &top), stack[top], points[i]) != 2)
            top--;
        stack[++top] = points[i];
    }

    printf("Points in the Convex Hull:\n");
    for (int i = 0; i <= top; i++)
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
}

int main() {
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
