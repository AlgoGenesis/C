# Convex Hull Implementation Using Sweep Line Algorithm

## Description

The **convex hull** of a set of 2D points is the smallest convex boundary that can enclose all given points. This C program computes the convex hull using **Sweep Line Algorithm**, which is an efficient method with \(O(n \log n)\) complexity, where \(n\) is the number of input points. The algorithm relies on sorting points and then constructing the hull by checking for convexity using the cross product.

In this implementation:

- **Sorting** arranges the points by their x-coordinates, and by y-coordinates for points with the same x-coordinate.
- **Cross Product** helps in determining the orientation of three points to ensure convexity.
- **Lower and Upper Hull Construction** builds the convex hull boundary in two stages, covering the points from left to right and from right to left.

## Problem Definition

The goal is to compute the convex hull of a set of 2D points using a **sweep line** approach in conjunction with the monotone chain technique. This implementation performs the following operations:

1. **Sort** the points by x and y coordinates.
2. **Build the Lower Hull**: Iterate from left to right, adding points to the lower hull.
3. **Build the Upper Hull**: Iterate from right to left, adding points to the upper hull.
4. **Check Convexity**: Use the cross product to verify if the new point maintains the convex shape. If not, backtrack by removing the last point from the hull.

### Key Operations:

- **Sorting**: Orders points to simplify the convex hull construction process.
- **Cross Product**: Determines if three points make a left or right turn, ensuring the hull remains convex.
- **Lower and Upper Hull Construction**: Ensures all points on the convex boundary are included.

## Algorithm Review

### 1. Sorting:
- Sort the points by x-coordinate, and by y-coordinate if x values are the same.
- This ordering enables a structured left-to-right and right-to-left traversal.

### 2. Building the Lower Hull:
- For each point in the sorted list, check if adding it maintains convexity by using the cross product.
- If adding a point creates a "right turn" (or a concave angle), backtrack by removing the last added point.

### 3. Building the Upper Hull:
- Repeat the process for the sorted list in reverse to form the upper half of the hull.

### 4. Cross Product:
- The cross product of vectors \( \overrightarrow{OA} \) and \( \overrightarrow{OB} \) tells us if points O, A, and B make a left turn (positive), a right turn (negative), or are collinear (zero).
- Only points creating left turns are included in the hull.

## Time Complexity

- **Sorting**: \(O(n \log n)\)
- **Convex Hull Construction**: \(O(n)\), as each point is added and removed at most once.
- **Overall Complexity**: \(O(n \log n)\)

## Example

Given the input points:

```plaintext
{ (0, 3), (2, 2), (1, 1), (2, 1), (3, 0), (0, 0), (3, 3) }
```

The output convex hull will be:

```plaintext
(0, 0)
(3, 0)
(3, 3)
(0, 3)
```

These points represent the convex boundary around the given set of points in counter-clockwise order.
## Explanation of the Code

1. **Struct Definition**: A `Point` structure is defined to store `x` and `y` coordinates.

2. **Sorting Function**:
   - `compare` sorts the points by x, and then by y if x-coordinates are the same.

3. **Cross Product Function**:
   - The `cross_product` function checks the orientation of three points, returning a positive value for a left turn.

4. **Convex Hull Construction**:
   - The `convex_hull` function first sorts the points and then builds the lower and upper hulls.
   - The result is stored in the `hull` array, with `hull_size` representing the number of vertices in the hull.

5. **Main Function**:
   - Initializes points and calls `convex_hull` to compute and print the convex hull vertices.

