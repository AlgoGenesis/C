# Topological Sort Algorithm (DFS) - C++

## Problem Statement

Given a **Directed Acyclic Graph (DAG)** with `V` vertices and `E` edges, the task is to find any **Topological Sorting** of that graph.

### Topological Sorting
In topological sorting, node `u` will always appear before node `v` if there is a directed edge from node `u` towards node `v` (`u -> v`).

### Example 1
**Input:**
- V = 6, E = 6
- Adjacency List: [[], [], [3], [1], [0, 1], [0, 2]]

**Output:**
5, 4, 2, 3, 1, 0

**Explanation:** The graph may have multiple valid topological sortings. The provided output is one possible result.

### Example 2
**Input:**
- V = 4, E = 3
- Adjacency List: [[1], [2], [3], []]

**Output:**
3, 2, 1, 0

## Approach

Topological sorting is only possible in a **Directed Acyclic Graph (DAG)**. If the graph contains a cycle, it is impossible to perform a topological sort.

### Key Concepts
- **DFS Traversal:** We will use Depth First Search (DFS) traversal to explore each node and its adjacent nodes. After visiting all the adjacent nodes, we push the current node onto a stack.
- **Stack:** The nodes are pushed onto the stack after all of their adjacent nodes have been visited, ensuring the topological order.

### Steps:
1. Perform DFS traversal for all unvisited nodes.
2. For each node, after visiting all its adjacent nodes, push the node onto a stack.
3. Once DFS completes for all nodes, the stack will contain the topological sort.
4. Pop the elements from the stack to get the topologically sorted order.

### Time Complexity
- **O(V + E):** Where `V` is the number of vertices and `E` is the number of edges. This is because we visit each vertex and each edge once.

### Space Complexity
- **O(V):** The space complexity is proportional to the number of vertices for the visited array and stack.
