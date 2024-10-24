#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 1e9

struct Point {
    int x, y;
};

// A utility function to find the next-to-top in a stack
struct Point nextToTop(struct Point stack[], int *top) {
    return stack[*top - 1];
}

// Function to swap two points
void swap(struct Point *p1, struct Point *p2) {
    struct Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Function to find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;  // collinear
    return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

// Function to sort points with respect to polar angle with base point
int compare(const void *vp1, const void *vp2) {
    struct Point *p1 = (struct Point *)vp1;
    struct Point *p2 = (struct Point *)vp2;

    int o = orientation(p1[0], *p1, *p2);
    if (o == 0)
        return (abs(p1[0].x - p2->x) <= abs(p1[0].x - p1->x)) ? -1 : 1;
    return (o == 2) ? -1 : 1;
}

// Function to compute convex hull
void convexHull(struct Point points[], int n) {
    // Find the lowest point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < ymin || (points[i].y == ymin && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }

    // Swap the lowest point with the first point
    swap(&points[0], &points[min]);

    // Sort points based on polar angle with base point
    qsort(&points[1], n - 1, sizeof(struct Point), compare);

    // Initialize stack to store the convex hull
    struct Point stack[n];
    int top = 0;
    stack[top++] = points[0];
    stack[top++] = points[1];

    // Process remaining points
    for (int i = 2; i < n; i++) {
        while (top > 1 && orientation(nextToTop(stack, &top), stack[top - 1], points[i]) != 2)
            top--;
        stack[top++] = points[i];
    }

    // Print the convex hull points
    for (int i = 0; i < top; i++)
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
}

int main() {
    struct Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
