# Graham's Scan Algorithm in C

This repository contains an implementation of **Graham's Scan Algorithm** in the C programming language. Graham's Scan is an algorithm used to find the **Convex Hull** of a given set of points. A convex hull is the smallest convex polygon that can enclose all the points.

## Algorithm

The Graham's Scan Algorithm is a **divide-and-conquer** approach to computing the convex hull. It starts by selecting the point with the lowest y-coordinate (and leftmost if there's a tie), sorts the remaining points by polar angle with respect to this point, and then uses a stack to keep only the points that form the convex boundary.

### Steps

1. **Find the starting point** (lowest y-coordinate).
2. **Sort points** based on the polar angle from the starting point.
3. **Iterate through sorted points** and construct the hull by maintaining a stack to track the vertices of the convex polygon.

### Code Overview

- **`Point` struct**: Used to represent each point in 2D space.
- **Functions**: Includes helper functions like `orientation` (to check turn direction), `distSq` (to calculate distance), and `compare` (to help with sorting).
- **`convexHull` function**: Main function that calculates the convex hull and prints the points on the convex boundary.

### Input and Output

The program is preloaded with a sample set of points. To change the points, modify the `points` array in `main()`.

#### Sample Input
```c
Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};


