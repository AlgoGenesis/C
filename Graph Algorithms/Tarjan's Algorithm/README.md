
# Tarjan's Algorithm for Strongly Connected Components

Tarjan's Algorithm is an efficient method for finding all strongly connected components (SCCs) in a directed graph. The algorithm is based on depth-first search (DFS) and has a linear time complexity of \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.

## Table of Contents

- [Algorithm Description](#algorithm-description)
- [How It Works](#how-it-works)
- [Usage](#usage)
- [Complexity Analysis](#complexity-analysis)

## Algorithm Description

1. Initialize two arrays: `low` and `disc` to keep track of the discovery time and the lowest discovery time reachable from each vertex.
2. Use a stack to store the nodes currently in the recursion stack of the DFS.
3. For each unvisited vertex, perform DFS to explore the graph.
4. During DFS traversal, if a back edge is found, update the `low` value.
5. If the discovery time and the lowest value of a node are the same, this node is the head of a strongly connected component (SCC). Pop all nodes in the recursion stack until this node to form an SCC.
6. Repeat for all unvisited nodes.

## How It Works

Tarjan's Algorithm works by assigning a unique discovery time to each node and then using the concept of back edges to identify SCCs. The algorithm ensures that every SCC is identified by comparing discovery times and the lowest reachable times of nodes. The stack is used to track the SCCs during the traversal.

## Usage

- Save the code in a file named `tarjan_algorithm.c`.
- Compile the code using a C compiler:
  
```bash
gcc tarjan_algorithm.c -o tarjan
```

- Run the executable:

```bash
./tarjan
```

## Complexity Analysis

### Time Complexity

1. **Depth-First Search (DFS)**: 
   - The algorithm performs a single DFS traversal over all the vertices, making the time complexity \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.

2. **Stack Operations**: 
   - Stack operations (push and pop) are performed for each vertex exactly once, which is \(O(V)\).

### Space Complexity

1. **Stack and Arrays**: 
   - The algorithm uses extra space for the `low`, `disc` arrays, and the stack, each of which requires \(O(V)\) space.

2. **Overall Space Complexity**: 
   - Therefore, the overall space complexity of Tarjan's Algorithm is:
     \[
     O(V)
     \]
