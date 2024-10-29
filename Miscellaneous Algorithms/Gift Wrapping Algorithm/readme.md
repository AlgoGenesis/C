### Gift Wrapping Algorithm (Jarvis March)

**Overview**

The Gift Wrapping Algorithm, also known as Jarvis March, is a straightforward algorithm used to find the convex hull of a set of points in a two-dimensional plane. The algorithm derives its name from the concept of "wrapping" a piece of string around the outermost points, similar to how one might wrap a gift. This method is particularly intuitive and visual, making it easier to understand for those learning computational geometry.

#### How It Works

1. **Initialization**: 
   - Start by identifying the leftmost point in the set of points. This point is guaranteed to be part of the convex hull because it has no other points to its left.

2. **Iterative Wrapping**:
   - Use a loop to keep track of the current point on the convex hull. Initially, this is the leftmost point.
   - In each iteration, consider all other points and determine which point forms the smallest angle with the current point. This is done using the orientation of the triplet formed by the current point and each of the other points.
   - Continue this process until you return to the starting point, completing the convex hull.

3. **Output**: 
   - The points identified during the wrapping process form the vertices of the convex hull.

![Screenshot 2024-10-29 133946](https://github.com/user-attachments/assets/9fc7a6e4-c882-42a5-a8b4-55d29ca6b017)

### Pseudocode

Here’s a simplified pseudocode for the Gift Wrapping Algorithm:

```plaintext
function giftWrap(points):
    hull = []
    leftmost = findLeftmostPoint(points)
    current = leftmost

    repeat:
        hull.append(current)
        nextPoint = points[0]

        for point in points:
            if orientation(current, nextPoint, point) == 2:
                nextPoint = point
        
        current = nextPoint

    until current == leftmost

    return hull
```

### Time Complexity

The time complexity of the Gift Wrapping Algorithm is \(O(nh)\), where \(n\) is the number of points in the input set and \(h\) is the number of points in the convex hull. This complexity arises because for each point in the hull, the algorithm potentially examines all other points to determine the next point in the hull.

### Importance of the Gift Wrapping Algorithm

1. **Simplicity**:
   - The Gift Wrapping Algorithm is easy to understand and implement, making it a great educational tool for teaching computational geometry and algorithm design.

2. **Visual Representation**:
   - The wrapping analogy provides an intuitive understanding of how the convex hull is formed, which can be helpful for beginners and students.

3. **Geometric Applications**:
   - Convex hulls are fundamental in various geometric applications, such as shape analysis, computer graphics, and spatial data analysis.

4. **Collision Detection**:
   - In computer graphics and physics simulations, the convex hull can be used to create bounding shapes around complex objects for efficient collision detection.

5. **Data Analysis**:
   - The convex hull can help identify outliers in datasets and is used in clustering algorithms.

6. **Robustness**:
   - The algorithm works well in practice for small to moderate-sized datasets, providing a straightforward approach to computing the convex hull without complex data structures.

7. **Foundation for Other Algorithms**:
   - Understanding the Gift Wrapping Algorithm provides a foundation for studying more advanced convex hull algorithms, such as Graham's Scan and Quickhull.
