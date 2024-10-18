# Ford-Fulkerson Algorithm

## Overview

The **Ford-Fulkerson Algorithm** is used to compute the maximum flow in a flow network. The key idea is to find paths from the source to the sink with available capacity and push flow along these paths until no more flow can be pushed. It leverages the concept of residual graphs and augmenting paths, repeatedly increasing the flow until an optimal solution is found.

## Problem Statement

Given a directed graph where each edge has a capacity, the objective is to find the maximum flow from a given source to a given sink. Each vertex represents a junction, and each edge represents a pipeline with a certain capacity (maximum flow).

### Example Problem

You are given a flow network with `n` vertices and `m` edges. Compute the maximum possible flow from source `s` to sink `t`.

**Input:**
Vertices: 6 Edges: 1 -> 2, capacity 16 1 -> 3, capacity 13 2 -> 3, capacity 10 2 -> 4, capacity 12 3 -> 5, capacity 14 4 -> 6, capacity 20 5 -> 6, capacity 4

**Output:**
The maximum possible flow is 23.


## Example Test Cases

**Test Case 1:**
Input: Vertices: 4 Edges: 1 -> 2, capacity 100 2 -> 3, capacity 50 3 -> 4, capacity 200 **Output:** The maximum possible flow is 50.

**Test Case 2:**
Input: Vertices: 5 Edges: 1 -> 2, capacity 15 1 -> 3, capacity 10 2 -> 4, capacity 20 3 -> 5, capacity 10 4 -> 5, capacity 25 
**Output:** The maximum possible flow is 15.


### Theory

The **Ford-Fulkerson Algorithm** is an iterative algorithm that finds augmenting paths in a residual graph. The main steps include:
1. Start with zero flow.
2. Find an augmenting path in the residual graph using BFS or DFS.
3. Augment the flow along this path by the minimum residual capacity of the edges in the path.
4. Update the residual graph.
5. Repeat the process until no augmenting paths are found.

### Time Complexity

- In the case of BFS (Edmonds-Karp implementation), the time complexity is **O(VE^2)** where `V` is the number of vertices and `E` is the number of edges.

### Space Complexity

- The space complexity is **O(V + E)** due to the adjacency list and residual graph.

### Coding Platform Problems

- [Maximum Flow - LeetCode](https://leetcode.com/problems/find-max-flow/)
- [Ford-Fulkerson Implementation - GeeksforGeeks](https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/)
