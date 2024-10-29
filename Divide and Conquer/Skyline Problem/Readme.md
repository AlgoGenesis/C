# Skyline Problem 

## Overview

This program uses the **Skyline Algorithm** to compute the **skyline outline** formed by a set of overlapping rectangles in a 2D plane. The algorithm efficiently identifies the critical points where the height of the skyline changes, achieving a time complexity of **O(n log n)** due to sorting the edges. This approach is significantly faster than naive methods that may take **O(n²)** time.

## Data Structure

### Structures Used:
- **Event**: A structure that holds the x-coordinate, height, and type (start or end) for each rectangle edge.

- **Priority Queue**: A max-heap (or priority queue) used to manage active heights, allowing quick retrieval of the current maximum height.

### Functions:

1. **void addRectangle(int left, int right, int height)**:  
   Adds the start and end events of a rectangle to the list of events for processing.

2. **vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings)**:  
   Computes the skyline by processing the sorted events and updating the heights using the priority queue to track active rectangles.

3. **void processEvents(vector<Event>& events)**:  
   Processes the sorted events to determine the critical points where the skyline changes height.

4. **void printSkyline(const vector<pair<int, int>>& skyline)**:  
   Outputs the computed skyline points in the required format.

## Memory Management

- **Dynamic Memory Allocation**:  
  The program uses dynamic allocation for the event list and the priority queue to handle an arbitrary number of rectangles.

- **Freeing Memory**:  
Memory is managed automatically with C++ containers (like vectors) that handle their own memory cleanup.

### Functions for Memory Management:
1. **vector<Event> createEventList(vector<vector<int>>& buildings)**:  
   Dynamically creates a list of events based on the provided building coordinates.

## Time and Space Complexity

- **Time Complexity**:  
  The algorithm runs in **O(n log n)** time, where `n` is the number of rectangles due to the sorting of events.
  
- **Space Complexity**:  
  The space complexity is **O(n)** for storing the event list and the priority queue for active heights.
