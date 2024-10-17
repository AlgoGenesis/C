#include <stdio.h>

struct Point {
    int x;
    int y;
};

// Function to calculate the orientation of three points
// 0 -> Collinear, 1 -> Clockwise, 2 -> Counterclockwise
int calculateOrientation(struct Point p, struct Point q, struct Point r) {
    int value = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (value == 0) return 0;  // Collinear
    return (value > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to check if point q lies on the line segment pr
int isOnSegment(struct Point p, struct Point q, struct Point r) {
    return (q.x <= (r.x > p.x ? r.x : p.x) && q.x >= (r.x < p.x ? r.x : p.x) &&
            q.y <= (r.y > p.y ? r.y : p.y) && q.y >= (r.y < p.y ? r.y : p.y));
}

// Function to check if two line segments intersect
int areSegmentsIntersecting(struct Point p1, struct Point q1, struct Point p2, struct Point q2) {
    int o1 = calculateOrientation(p1, q1, p2);
    int o2 = calculateOrientation(p1, q1, q2);
    int o3 = calculateOrientation(p2, q2, p1);
    int o4 = calculateOrientation(p2, q2, q1);

    // General case: segments intersect
    if (o1 != o2 && o3 != o4) {
        return 1; // Intersect
    }

    // Special cases: check for collinearity
    if (o1 == 0 && isOnSegment(p1, p2, q1)) return 1; // p2 lies on p1q1
    if (o2 == 0 && isOnSegment(p1, q2, q1)) return 1; // q2 lies on p1q1
    if (o3 == 0 && isOnSegment(p2, p1, q2)) return 1; // p1 lies on p2q2
    if (o4 == 0 && isOnSegment(p2, q1, q2)) return 1; // q1 lies on p2q2

    return 0; // No intersection
}

int main() {
    struct Point start1, end1, start2, end2;

    // Input for the first line segment
    printf("Enter the coordinates of the first line segment (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &start1.x, &start1.y, &end1.x, &end1.y);

    // Input for the second line segment
    printf("Enter the coordinates of the second line segment (x3 y3 x4 y4): ");
    scanf("%d %d %d %d", &start2.x, &start2.y, &end2.x, &end2.y);

    // Check for intersection
    if (areSegmentsIntersecting(start1, end1, start2, end2)) {
        printf("The line segments intersect.\n");
    } else {
        printf("The line segments do not intersect.\n");
    }

    return 0;
}
