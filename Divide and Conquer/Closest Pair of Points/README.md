# Closest Pair of Points Algorithm

## Problem Description

The **Closest Pair of Points** problem involves finding the pair of points in a 2D plane that are closest to each other based on Euclidean distance.

### Euclidean Distance Formula

The distance between two points \(P1(x_1, y_1)\) and \(P2(x_2, y_2)\) is given by:

\[
d(P1, P2) = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}
\]

### Approaches to Solve the Problem

#### 1. Brute Force

- **Time Complexity**: \(O(n^2)\)
- **Method**: Compute the distance between every pair of points and return the minimum.

#### 2. Divide and Conquer (Efficient)

- **Time Complexity**: \(O(n \log n)\)
- **Method**:
  1. Sort the points by their x-coordinates.
  2. Divide the points into two halves.
  3. Recursively find the closest pairs in each half.
  4. Check for the closest pair across the dividing line (strip).
  5. Return the minimum distance found.

## Algorithm Explanation (Divide and Conquer)

1. **Divide the points** into two halves based on their x-coordinates.
2. **Recursively solve** the problem for each half.
3. **Combine the results** by checking if any pair of points lies closer across the dividing line. Only points within a distance of the smallest found distance from the dividing line need to be checked.
4. Return the minimum of:
   - The closest pair in the left half.
   - The closest pair in the right half.
   - The closest pair across the dividing line (strip).
