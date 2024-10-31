#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    double x, y;
} Point;

typedef struct Segment {
    Point start, end;
} Segment;

// Utility function to determine the orientation of three points
int orientation(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    return (val == 0) ? 0 : (val > 0) ? 1 : 2;
}

// Function to check if two line segments intersect
int doIntersect(Segment s1, Segment s2) {
    int o1 = orientation(s1.start, s1.end, s2.start);
    int o2 = orientation(s1.start, s1.end, s2.end);
    int o3 = orientation(s2.start, s2.end, s1.start);
    int o4 = orientation(s2.start, s2.end, s1.end);

    if (o1 != o2 && o3 != o4) return 1;
    return 0;
}

// Event handler to find all intersections
void findIntersections(Segment segments[], int n) {
    printf("Intersections:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (doIntersect(segments[i], segments[j])) {
                printf("Intersection between segment %d and segment %d\n", i + 1, j + 1);
            }
        }
    }
}

int main() {
    Segment segments[] = {
        {{1, 1}, {4, 4}},
        {{1, 8}, {2, 4}},
        {{3, 3}, {4, 1}},
        {{4, 0}, {4, 5}}
    };

    int n = sizeof(segments) / sizeof(segments[0]);
    findIntersections(segments, n);

    return 0;
}
