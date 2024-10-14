# Depth-First Search (DFS) Algorithm

## Description

Depth-First Search (DFS) is a fundamental graph traversal algorithm that explores as far as possible along each branch before backtracking. It is commonly used for tasks like pathfinding, detecting cycles, and exploring the entire structure of a graph or tree. DFS can be implemented both recursively and iteratively (using a stack).

## Problem Definition

The goal of this implementation is to efficiently explore all nodes of a graph using Depth-First Search (DFS), supporting:

- **Graph Representation:** A graph can be represented using an adjacency list or matrix.
- **DFS Traversal:** Starting from a given source node, explore each branch of the graph to its depth limit before backtracking.
- **Cycle Detection:** Detect cycles in both directed and undirected graphs using DFS.
- **Pathfinding:** Use DFS to find a path between two nodes, if one exists.
- **Graph Connectivity:** Determine if all nodes in the graph are connected.

## Algorithm Review

### Traversal

1. **Recursive DFS**: 
   - Start from the given node.
   - Visit an unvisited adjacent node, then recursively visit its adjacent nodes.
   - Backtrack once all adjacent nodes have been visited.
   
2. **Iterative DFS**: 
   - Use a stack to emulate recursion.
   - Push the starting node onto the stack.
   - While the stack is not empty, pop a node from the stack and visit its unvisited adjacent nodes, pushing them onto the stack.

### Key Operations:

- **Graph Representation**: A graph can be represented using an adjacency list where each vertex points to a list of its neighbors.
- **DFS Traversal**: Explore the graph by visiting a node, then recursively or iteratively visiting its adjacent, unvisited nodes.
- **Cycle Detection**: While traversing, check if an adjacent node has already been visited and is not the direct parent of the current node.
- **Pathfinding**: Keep track of the visited nodes during traversal to find a path between a start and target node.

## Time Complexity

For both recursive and iterative DFS:

- **Traversal**: O(V + E), where V is the number of vertices and E is the number of edges.
- **Space Complexity**: O(V) in the worst case due to the recursion stack or explicit stack used in the iterative approach.

## Use Cases

- **Cycle Detection**: DFS can detect cycles in a graph by backtracking and checking for visited nodes.
- **Pathfinding**: DFS can help find if there is a path between two nodes.
- **Graph Connectivity**: DFS can be used to check if all nodes are reachable from any given node.
- **Topological Sorting**: In Directed Acyclic Graphs (DAGs), DFS is often used for topological sorting.

