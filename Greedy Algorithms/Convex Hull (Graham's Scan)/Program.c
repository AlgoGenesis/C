#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x, y;
};

// To find the next-to-top in the stack
struct Point nextToTop(struct Point stack[], int *stackSize) {
    return stack[(*stackSize) - 2];
}

// To swap two points
void swap(struct Point* p1, struct Point* p2) {
    struct Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// To find orientation of three points p, q, r
// Returns:
// 0 -> p, q, r are collinear
// 1 -> clockwise
// 2 -> counterclockwise
int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;           // collinear
    return (val > 0) ? 1 : 2;          // clockwise or counterclockwise
}

// To find the square of the distance between two points p1 and p2
int distSq(struct Point p1, struct Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Used by qsort() to sort points with respect to the first point
// Sorts based on polar angle with respect to the base point
struct Point p0;   // base point (global for sorting)

int compare(const void *vp1, const void *vp2) {
    struct Point *p1 = (struct Point *)vp1;
    struct Point *p2 = (struct Point *)vp2;

    // Find the orientation of the ordered triplet (p0, p1, p2)
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

// Main function that returns the convex hull of a set of n points
void convexHull(struct Point points[], int n) {
    // Find the point with the lowest y-coordinate (pivot)
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < ymin) || (points[i].y == ymin && points[i].x < points[min].x)) {
            ymin = points[i].y;
            min = i;
        }
    }

    // Place the pivot point at the first position
    swap(&points[0], &points[min]);

    // Sort remaining points based on polar angle with respect to the pivot
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(struct Point), compare);

    // Remove collinear points
    int m = 1; // Initialize the size of the modified array
    for (int i = 1; i < n; i++) {
        // Keep removing points while the angle formed by the point i and the last point is same
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        points[m] = points[i];
        m++; // Updated size
    }

    // If the modified array has fewer than 3 points, there is no convex hull
    if (m < 3) {
        printf("Convex Hull cannot be formed.\n");
        return;
    }

    // Create an empty stack and push first three points
    struct Point stack[m];
    int stackSize = 0;
    stack[stackSize++] = points[0];
    stack[stackSize++] = points[1];
    stack[stackSize++] = points[2];

    // Process the remaining points
    for (int i = 3; i < m; i++) {
        // Keep removing points from stack if the current point makes a clockwise turn
        while (stackSize > 1 && orientation(nextToTop(stack, &stackSize), stack[stackSize - 1], points[i]) != 2)
            stackSize--; // pop
        stack[stackSize++] = points[i]; // push
    }

    // Print the convex hull
    printf("Points in Convex Hull are:\n");
    for (int i = 0; i < stackSize; i++)
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    struct Point points[n];
    printf("Enter the points (x y) format:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    convexHull(points, n);

    return 0;
}
