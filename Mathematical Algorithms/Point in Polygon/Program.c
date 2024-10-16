#include <stdio.h>

struct Point {
    int x, y;
};

// Function to check if the point q lies on the line segment 'p1' to 'p2'
int onSegment(struct Point p1, struct Point p2, struct Point q) {
    return (q.x <= (p1.x > p2.x ? p1.x : p2.x) && q.x >= (p1.x < p2.x ? p1.x : p2.x) &&
            q.y <= (p1.y > p2.y ? p1.y : p2.y) && q.y >= (p1.y < p2.y ? p1.y : p2.y));
}

// Function to determine the orientation of the triplet (p, q, r)
// Returns:
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or counterclockwise
}

// Function to check if the line segment 'p1q1' and 'p2q2' intersect
int doIntersect(struct Point p1, struct Point q1, struct Point p2, struct Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return 1; // They intersect

    // Special Cases
    if (o1 == 0 && onSegment(p1, q1, p2)) return 1;
    if (o2 == 0 && onSegment(p1, q1, q2)) return 1;
    if (o3 == 0 && onSegment(p2, q2, p1)) return 1;
    if (o4 == 0 && onSegment(p2, q2, q1)) return 1;

    return 0; // Doesn't intersect
}

// Function to check if a point lies inside a polygon
int isInside(struct Point polygon[], int n, struct Point p) {
    if (n < 3) return 0; // A polygon must have at least 3 vertices

    // Create a point for the ray
    struct Point extreme = {10000, p.y}; // A point far away

    int count = 0, i = 0;
    do {
        int next = (i + 1) % n;

        // Check if the line segment from 'p' to 'extreme' intersects with the edge
        if (doIntersect(polygon[i], polygon[next], p, extreme)) {
            // If the point is collinear with the segment, check if it lies on the segment
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return onSegment(polygon[i], polygon[next], p);
            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd
    return count % 2 == 1;
}

int main() {
    struct Point polygon[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}}; // A square
    int n = sizeof(polygon) / sizeof(polygon[0]);

    struct Point p; // Point to check
    printf("Enter the coordinates of the point (x y): ");
    scanf("%d %d", &p.x, &p.y);

    if (isInside(polygon, n, p))
        printf("The point (%d, %d) is inside the polygon.\n", p.x, p.y);
    else
        printf("The point (%d, %d) is outside the polygon.\n", p.x, p.y);

    return 0;
}
