# Point in Polygon Algorithm

## Description

This program implements the Point in Polygon algorithm using the ray-casting method. It determines whether a given point lies inside, outside, or on the boundary of a polygon defined by its vertices.

## Structures

**Point**:
A structure to represent a point in 2D space.

Members:
- `int x`: The x-coordinate of the point.
- `int y`: The y-coordinate of the point.

## Functions

1. **int onSegment(struct Point p1, struct Point p2, struct Point q)**:
   - Checks if the point `q` lies on the line segment from `p1` to `p2`.
   - Returns:
     - 1 if the point lies on the segment.
     - 0 otherwise.

2. **int orientation(struct Point p, struct Point q, struct Point r)**:
   - Determines the orientation of the triplet (p, q, r).
   - Returns:
     - 0 if p, q, and r are collinear.
     - 1 if they are in a clockwise orientation.
     - 2 if they are in a counterclockwise orientation.

3. **int doIntersect(struct Point p1, struct Point p1, struct Point p2, struct Point q2)**:
   - Checks if the line segment `p1q1` and `p2q2` intersect.
   - Returns:
     - 1 if they intersect.
     - 0 if they do not.

4. **int isInside(struct Point polygon[], int n, struct Point p)**:
   - Checks if the point `p` lies inside the polygon defined by its vertices.
   - Returns:
     - 1 if the point is inside the polygon.
     - 0 if the point is outside.

## Main Function:

Details:
- Defines a polygon (a square in this case) with its vertices.
- Prompts the user to enter the coordinates of the point to check.
- Calls the `isInside` function to determine the position of the point relative to the polygon.
- Outputs whether the point is inside or outside the polygon.

## Usage

1. Compile the program using a C compiler (e.g., `gcc point_in_polygon.c -o point_in_polygon`).
2. Run the program (`./point_in_polygon`).
3. Follow the prompt to enter the coordinates of the point.
4. The program will output whether the point is inside or outside the polygon.

## Time Complexity

- The time complexity of the algorithm is \(O(n)\), where \(n\) is the number of vertices in the polygon. 
- This complexity arises because, in the worst case, the algorithm checks for intersections with each edge of the polygon.

## Example

- **Input**: 
Enter the coordinates of the point (x y): 4 4


- **Output**: 
The point (4, 4) is inside the polygon.


