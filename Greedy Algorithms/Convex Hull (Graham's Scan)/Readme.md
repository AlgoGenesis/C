# Convex Hull Algorithm (Graham's Scan)

# Description

This program implements Graham's Scan algorithm to solve the convex hull problem. Given a set of points on a 2D plane, the algorithm determines the smallest convex polygon that can enclose all the points.

# Structures

Point:
A structure to represent a 2D point with x and y coordinates.

Members:
int x: The x-coordinate of the point.
int y: The y-coordinate of the point.

# Function

1. int orientation(Point p, Point q, Point r):
   - Determines the orientation of the triplet (p, q, r).
   - Returns:
   ~ 0 if the points are collinear.
   ~ A positive value if the points make a clockwise turn.
   ~ A negative value if the points make a counterclockwise turn.

2. int compare(const void a, const void b)**:
   - Compares two points based on their polar angles with respect to the base point.
   - Used for sorting points by their polar angles in ascending order.

# Main Function:

Details:

- Prompts the user to input the number of points (n).
- Dynamically allocates memory for an array of Point structures.
- For each point, the user inputs the x and y coordinates, which are
  stored in the points array.
- Identifies the point with the lowest y-coordinate (the base point),
  which acts as the pivot for sorting.
- Sorts the remaining points based on their polar angles with respect to
  the base point using qsort() and the compare() function.
- Initializes a stack to store the points on the convex hull.
- Iterates over the sorted points:
  ~If a point makes a right turn (clockwise), it is removed from the stack.
  ~Points making a left turn (counterclockwise) are added to the stack.
- Prints the points that form the convex hull in counterclockwise order.
- Frees the dynamically allocated memory for the points array before
  exiting.

# Memory Management

- Dynamic Memory Allocation
- Freeing Memory


### Time Complexity:
- Sorting step: \(O(n \log n)\)
- Constructing the hull: \(O(n)\)
- Overall complexity: \(O(n \log n)\)