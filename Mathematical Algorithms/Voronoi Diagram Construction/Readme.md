# Voronoi Diagram Construction

## Description

This repository provides a C implementation for constructing **Voronoi Diagrams**. A Voronoi diagram partitions a plane into regions based on the distance to a specific set of points (sites). Each region contains all points that are closer to its corresponding site than to any other site, making it useful for various applications, including spatial analysis, pattern recognition, and geographic information systems.

## Overview

The implementation uses a simple algorithm to compute Voronoi cells for a set of input points. The program iterates over a fixed grid to determine the closest site for each point, effectively constructing the Voronoi diagram.

## Structures

1. **Point**:
   - Represents a 2D point in space.
   - Members:
     - `double x`: X-coordinate of the point.
     - `double y`: Y-coordinate of the point.

2. **VoronoiCell**:
   - Represents a Voronoi cell for a site.
   - Members:
     - `Point vertices[MAX_VORONOI_VERTICES]`: Array of vertices that define the cell.
     - `int vertex_count`: The number of vertices in the cell.

## Functions

1. **`double distance(Point a, Point b)`**:
   - Calculates the Euclidean distance between two points.

2. **`void compute_voronoi()`**:
   - Constructs the Voronoi diagram by determining the closest site for each point in a fixed grid.

3. **`void print_voronoi()`**:
   - Prints the vertices of each Voronoi cell.

## Example

### Input

Enter the number of points (max 100): 3
Enter the points (x y):
10 10
30 10
20 30

### Output

Voronoi Cell for site (10.000000, 10.000000):
  Point: (0.000000, 0.000000)
  Point: (1.000000, 0.000000)
  Point: (2.000000, 0.000000)
  ...
  Point: (19.000000, 29.000000)
Voronoi Cell for site (30.000000, 10.000000):
  Point: (20.000000, 0.000000)
  Point: (20.000000, 1.000000)
  ...
  Point: (99.000000, 29.000000)
Voronoi Cell for site (20.000000, 30.000000):
  Point: (0.000000, 30.000000)
  Point: (1.000000, 30.000000)
  ...
  Point: (99.000000, 30.000000)


