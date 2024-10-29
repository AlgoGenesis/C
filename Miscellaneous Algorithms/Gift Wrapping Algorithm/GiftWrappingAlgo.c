// Gift Wrapping Algo

#include <stdio.h>

// Structure to represent a point
typedef struct {
    int x, y;
} Point;

// Function to find the orientation of the triplet (p, q, r)
// Returns 0 if collinear, 1 if clockwise, and 2 if counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1 : 2; // clock or counter-clock wise
}

// Function to find the leftmost point
Point findLeftmostPoint(Point points[], int n) {
    Point leftmost = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].x < leftmost.x) {
            leftmost = points[i];
        }
    }
    return leftmost;
}

// Gift Wrapping Algorithm (Jarvis March)
void giftWrap(Point points[], int n) {
    if (n < 3) {
        printf("Convex hull is not possible with less than 3 points.\n");
        return;
    }

    // Initialize result (the convex hull)
    Point hull[n];
    int hullIndex = 0;

    // Find the leftmost point
    Point current = findLeftmostPoint(points, n);
    do {
        hull[hullIndex++] = current; // Add current point to the hull

        // Search for a point 'next' such that orientation(current, next, points[i]) is counterclockwise
        Point next = points[0];
        for (int i = 1; i < n; i++) {
            if (orientation(current, next, points[i]) == 2) {
                next = points[i];
            }
        }

        current = next; // Set next point as current
    } while (current.x != hull[0].x || current.y != hull[0].y); // Loop until we reach the start point

    // Print the convex hull
    printf("Convex Hull:\n");
    for (int i = 0; i < hullIndex; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

// Main function
int main() {
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    
    giftWrap(points, n);

    return 0;
}
