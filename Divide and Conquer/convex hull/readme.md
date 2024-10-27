### Convex Hull Using Divide and Conquer Algorithm

This C program implements a **divide-and-conquer** algorithm to find the convex hull of a set of 2D points. The convex hull is the smallest polygon that encloses all the given points, and this algorithm efficiently divides the problem into smaller subproblems, solves them, and combines the results.

---

### Features

**Input:**
- The program takes an array of 2D points as input.

**Algorithm:**
- It uses a recursive divide-and-conquer approach. The points are divided into smaller subsets, the convex hull is computed for each subset, and the results are merged.

**Output:**
- The program prints the points that form the convex hull in sorted order.

---

### Code Structure

**Struct Definition:**
- `Pair`: A structure to hold the x (`first`) and y (`second`) coordinates of a point.

**Functions:**
1. **quad(Pair p):**  
   Determines which quadrant a point lies in, relative to the center of the polygon. Used for sorting points.

2. **orientation(Pair a, Pair b, Pair c):**  
   Determines the orientation of three points (collinear, clockwise, or counterclockwise).

3. **compare(const void *p1, const void *q1):**  
   A custom comparator function used for sorting points based on their quadrants and polar angles.

4. **merger(Pair *a, int n1, Pair *b, int n2, int *ret_size):**  
   Merges two convex hulls into one. This is done by identifying the upper and lower tangents that join the two hulls without crossing any other points.

5. **bruteHull(Pair *a, int n, int *ret_size):**  
   A brute-force algorithm to compute the convex hull when the number of points is small (base case).

6. **divide(Pair *a, int n, int *ret_size):**  
   Recursively divides the set of points into smaller subsets, computes their convex hulls, and merges them.

**Main Function:**
- The entry point of the program where a predefined set of points is given. The program then calls the `divide` function and prints the points that form the convex hull.

---

This program provides a clear demonstration of how the divide-and-conquer approach can be applied to geometric problems like finding the convex hull. The recursive division, combined with sorting and merging, efficiently finds the smallest polygon that encloses the given points.
