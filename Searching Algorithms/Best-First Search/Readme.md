# Best-First Search

## Description

Best-First Search is an informed search algorithm that uses a heuristic to determine the most promising node to explore next. It prioritizes nodes based on their estimated cost to reach the goal, effectively guiding the search process toward the target more efficiently than uninformed search methods.

### Problem Definition

Given:
- A graph or tree structure where nodes represent states.
- A heuristic function \( h(n) \) that estimates the cost from node \( n \) to the goal.

Objective:
- Find the optimal path from the start node to the goal node using the Best-First Search algorithm.

### Algorithm Overview

1. **Initialization**:
   - Create a priority queue to hold nodes, prioritized by their heuristic value.
   - Enqueue the start node with its heuristic value.

2. **Explore Nodes**:
   - While the priority queue is not empty:
     - Dequeue the node with the lowest heuristic value.
     - If the dequeued node is the goal, reconstruct the path and return it.
     - For each neighbor of the dequeued node:
       - Calculate the heuristic value and enqueue the neighbor if it hasn't been visited.

3. **Continue** until the goal is found or all possible nodes have been explored.

### Time Complexity

The time complexity of Best-First Search depends on the heuristic and the structure of the graph, but in the worst case, it can be \( O(b^d) \), where \( b \) is the branching factor and \( d \) is the depth of the goal node.

