# Critical and Pseudo-Critical Edges in Minimum Spanning Tree

This repository contains a C implementation that identifies critical and pseudo-critical edges in a Minimum Spanning Tree (MST) of a given graph. The algorithm employs Kruskal's algorithm along with a disjoint set (union-find) data structure to efficiently manage the connected components of the graph.

## Table of Contents

- [Problem Description](#problem-description)
- [Definitions](#definitions)
- [Features](#features)
- [Input Format](#input-format)
- [Output Format](#output-format)
- [Example](#example)
- [How to Compile and Run](#how-to-compile-and-run)
- [Code Structure](#code-structure)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Problem Description

In a connected, undirected graph, edges play a crucial role in defining the structure of the Minimum Spanning Tree (MST). The MST is a subset of edges that connects all vertices with the minimum possible total edge weight. Understanding which edges are critical or pseudo-critical helps in network design and optimization.

## Definitions

- **Critical Edge**: An edge is considered critical if its removal increases the weight of the MST. This means that the MST cannot be formed without this edge.
  
- **Pseudo-Critical Edge**: An edge is considered pseudo-critical if it can be included in the MST without affecting the total weight, but removing it does not increase the MST weight. This means that while the edge is not essential for the MST, it can be part of it without changing the overall cost.

## Features

- **Efficient Edge Classification**: Uses Kruskal's algorithm to determine the MST and classify edges as critical or pseudo-critical.
- **Union-Find Structure**: Implements a disjoint set data structure to efficiently manage and merge connected components.
- **Dynamic Input Handling**: Accepts a variable number of edges and vertices, making it adaptable to different graph sizes.

## Input Format

The input consists of:
- An integer `n` representing the number of vertices in the graph.
- An integer `m` representing the number of edges in the graph.
- A 2D array `edges` where each element is an array containing three integers: the two vertices connected by the edge and the weight of the edge.

### Example Input

```c
int n = 5; // Number of vertices
int m = 7; // Number of edges
int edges[7][3] = {
    {0, 1, 1}, // Edge from vertex 0 to vertex 1 with weight 1
    {0, 2, 3}, // Edge from vertex 0 to vertex 2 with weight 3
    {1, 2, 2}, // Edge from vertex 1 to vertex 2 with weight 2
    {1, 3, 4}, // Edge from vertex 1 to vertex 3 with weight 4
    {2, 3, 5}, // Edge from vertex 2 to vertex 3 with weight 5
    {3, 4, 6}, // Edge from vertex 3 to vertex 4 with weight 6
    {1, 4, 7}  // Edge from vertex 1 to vertex 4 with weight 7
};