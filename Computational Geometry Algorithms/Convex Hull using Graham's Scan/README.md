# Convex Hull Algorithm using Graham's Scan

The Convex Hull is a fundamental problem in computational geometry. It refers to the smallest convex boundary that can enclose a set of points in a plane. One common method to solve this problem is **Graham's Scan**, which works by sorting the points based on their polar angle and processing them to find the vertices of the convex hull.

## Algorithm Explanation

### Steps:
1. **Find the Base Point**: Identify the point with the smallest y-coordinate (break ties with the smallest x-coordinate). This will be the starting point of the convex hull.
2. **Sort Points by Polar Angle**: Sort the remaining points based on the angle they form with the base point. This is done using the orientation function.
3. **Process Points**: Push points to a stack and make sure that every turn between the top points of the stack is counterclockwise. If a clockwise turn is encountered, pop the top point from the stack.

### Pseudo Code:
1. Start with the point with the smallest y-coordinate.
2. Sort the remaining points by polar angle relative to the starting point.
3. Traverse through the points, and for each point:
   - If the point causes a clockwise turn, remove the last point from the convex hull.
   - Add the current point to the convex hull.


Time Complexity:
Sorting the points based on polar angle: O(n log n).
Traversing through the points: O(n).
Total complexity: O(n log n).

Example Output:

Convex Hull:
(0, 0)
(3, 1)
(4, 4)
(0, 3)




## C Implementation

```c
#include <stdio.h>
#include <stdlib.h>
...

int main() {
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
