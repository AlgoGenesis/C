# Kruskal's Algorithm for Minimum Spanning Tree

Kruskal's Algorithm is a greedy algorithm used for finding the Minimum Spanning Tree (MST) of a connected, undirected graph. The algorithm works by sorting all the edges in non-decreasing order of their weights and adding them one by one to the MST, ensuring no cycles are formed.

## Table of Contents
- [Algorithm Description](#algorithm-description)
- [How It Works](#how-it-works)
- [Usage](#usage)
- [Complexity Analysis](#complexity-analysis)

## Algorithm Description

1. Sort all the edges of the graph in non-decreasing order of their weights.
2. Initialize a forest (a set of trees), where each vertex is a separate tree.
3. For each edge in the sorted list, check if it forms a cycle with the spanning tree formed so far.
4. If it does not form a cycle, add it to the spanning tree.
5. Repeat until there are (V - 1) edges in the spanning tree, where V is the number of vertices.

## How It Works

Kruskal's algorithm uses a union-find data structure to keep track of which vertices are in which components. This allows for efficient cycle detection.

## Usage

- Save the code in a file named `kruskals_algorithm.c`.
- Compile the code using a C compiler:
`gcc kruskals_algorithm.c -o kruskal`
- Run the executable:
`./kruskal`

## Complexity Analysis

### Time Complexity

1. **Sorting the Edges**: 
   - The first step of Kruskal's Algorithm is to sort all the edges in non-decreasing order of their weights. This takes \(O(E \log E)\) time, where \(E\) is the number of edges.

2. **Union-Find Operations**: 
   - The union-find operations (find and union) are performed for each edge considered. With path compression and union by rank, the time complexity of each operation is nearly \(O(1)\) on average. Thus, for \(E\) edges, this contributes \(O(E \cdot \alpha(V))\) to the time complexity, where \(\alpha\) is the inverse Ackermann function, which grows very slowly.

3. **Overall Time Complexity**: 
   - Combining these two parts, the overall time complexity of Kruskal's Algorithm is:
     \[
     O(E \log E + E \cdot \alpha(V))
     \]
   - Since \(E \log E\) dominates the \(E \cdot \alpha(V)\) term, we can simplify it to:
     \[
     O(E \log E)
     \]

### Space Complexity

1. **Edge List**: 
   - The algorithm stores all edges in an edge list, which requires \(O(E)\) space.

2. **Union-Find Structure**: 
   - The union-find structure requires an array of size \(V\) for storing parent and rank information, which requires \(O(V)\) space.

3. **Overall Space Complexity**: 
   - Therefore, the overall space complexity of Kruskal's Algorithm is:
     \[
     O(V + E)
     \]
