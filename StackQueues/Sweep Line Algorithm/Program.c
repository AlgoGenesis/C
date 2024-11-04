#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x, y;
} Point;

// Comparison function for qsort() to sort points by x, then y coordinates
int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    if (p1->x != p2->x) 
        return p1->x - p2->x;
    return p1->y - p2->y;
}

// Cross product of vectors OA and OB. A positive cross product indicates a left turn
int cross_product(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Function to compute the convex hull using Sweep Line Algorithm
void convex_hull(Point *points, int n, Point *hull, int *hull_size) {
    qsort(points, n, sizeof(Point), compare);

    int i, k = 0;

    // Build the lower hull
    for (i = 0; i < n; i++) {
        while (k >= 2 && cross_product(hull[k - 2], hull[k - 1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }

    // Build the upper hull
    int t = k + 1;
    for (i = n - 2; i >= 0; i--) {
        while (k >= t && cross_product(hull[k - 2], hull[k - 1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }

    *hull_size = k - 1;  // The last point is the same as the first point, so exclude it
}

int main() {
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);

    Point hull[2 * n];
    int hull_size;

    convex_hull(points, n, hull, &hull_size);

    printf("Convex Hull:\n");
    for (int i = 0; i < hull_size; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }

    return 0;
}
