# Line Intersection Algorithm

## Description

This program implements a line intersection algorithm to determine whether two line segments intersect. It uses geometric principles to check for intersection based on the endpoints of the segments.

## Structures

1. **Point**:
   - A structure to represent a 2D point with x and y coordinates.

   Members:
   - `int x`: The x-coordinate of the point.
   - `int y`: The y-coordinate of the point.

## Functions

1. **int orientation(Point p, Point q, Point r)**:
   - Determines the orientation of the triplet (p, q, r).
   - Returns:
     - 0 if the points are collinear.
     - A positive value if the points make a clockwise turn.
     - A negative value if the points make a counterclockwise turn.

2. **int onSegment(Point p, Point q, Point r)**:
   - Checks if point q lies on the line segment pr.
   - Returns:
     - 1 if q lies on the segment.
     - 0 otherwise.

3. **int doIntersect(Point p1, Point q1, Point p2, Point q2)**:
   - Determines if the line segments p1q1 and p2q2 intersect.
   - Returns:
     - 1 if the segments intersect.
     - 0 otherwise.

## Main Function:

### Details:

- Prompts the user to enter the coordinates of the first line segment (x1, y1, x2, y2).
- Prompts the user to enter the coordinates of the second line segment (x3, y3, x4, y4).
- Calls the `doIntersect` function to determine if the segments intersect.
- Prints whether the line segments intersect or not.

## Time Complexity:

- The algorithm runs in \(O(1)\) time since it performs a constant number of calculations regardless of the input size.

## Usage:

1. Compile the program using a C compiler (e.g., `gcc line_intersection.c -o line_intersection`).
2. Run the program (`./line_intersection`).
3. Follow the prompts to enter the coordinates of the line segments.
4. The program will output whether the segments intersect.

## Example:

### Input:
Enter the coordinates of the first line segment (x1 y1 x2 y2): 1 1 2 2
Enter the coordinates of the second line segment (x3 y3 x4 y4): 3 3 4 4

### Output:
The line segments do not intersect.
