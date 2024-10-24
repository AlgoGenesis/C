The **Convex Hull** problem is a fundamental problem in computational geometry, where given a set of points in a 2D plane, the goal is to find the smallest convex polygon that contains all the points. This polygon is called the **convex hull** of the points.

### **Convex Hull Definition**

A **convex hull** is the smallest convex shape (polygon) that encloses all the points such that any line segment joining two points inside the convex hull lies entirely inside the convex polygon.

### **Applications of Convex Hull:**

-   **Computer Graphics**: For collision detection, image processing, and shape analysis.
-   **Geographical Information Systems (GIS)**: To outline boundaries, e.g., of countries or regions.
-   **Robotics and AI**: Pathfinding and obstacle avoidance.
-   **Pattern Recognition**: Clustering of data points and outlier detection.

### **Algorithm for Convex Hull:**

Two popular algorithms to solve the convex hull problem are **Graham's Scan** and **Jarvis March** (also known as the Gift Wrapping algorithm).

#### 1\. **Graham's Scan Algorithm**

This is an efficient algorithm to find the convex hull in **O(n log n)** time, where `n` is the number of points.

##### **Steps for Graham's Scan:**

1.  **Find the point with the lowest y-coordinate** (in case of a tie, the leftmost point). This point is the **starting point**.
2.  **Sort the points** by the polar angle they make with the starting point. If two points have the same angle, keep the closer one.
3.  **Traverse the sorted array** and use a stack to build the convex hull:
    -   For each point, check whether moving from the two previously considered points to this point is a **"left turn"** or a **"right turn"**.
    -   If it's a right turn, it means the point is inside the hull, so remove the last point added to the convex hull.
    -   Continue until all points are processed.