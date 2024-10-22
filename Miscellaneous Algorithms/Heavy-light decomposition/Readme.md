
# Heavy-Light Decomposition in C

This repository contains a C implementation of the Heavy-Light Decomposition (HLD) algorithm. HLD is used for decomposing a tree to efficiently handle path queries and updates. This implementation supports querying the sum of values along the path between two nodes.

## Overview

Heavy-Light Decomposition is a technique used to decompose a tree into "heavy" and "light" paths. This allows for efficient querying and updating along the paths, using segment trees to handle range queries.

### Key Features:
- Handles tree-based queries efficiently using HLD.
- Supports path sum queries and updates using a segment tree.

## Input

The program expects the following input format:
1. **Number of Nodes (n)**: The first input line contains a single integer `n`, representing the number of nodes in the tree.
2. **Tree Edges**: The next `n-1` lines contain two integers `u` and `v`, representing an undirected edge between nodes `u` and `v`. This describes the tree's structure.
3. **Query Nodes (u, v)**: A pair of integers representing the nodes between which the path sum is queried.

### Example Input

5 0 1 1 2 1 3 3 4 2 4

This input represents:
- A tree with 5 nodes.
- Edges: (0-1), (1-2), (1-3), (3-4).
- A path sum query between nodes 2 and 4.

## Output

The output displays the sum of the values along the path between the specified nodes. Initially, all node values are set to zero. The segment tree can be updated to reflect different values for each node, allowing for more meaningful results.

### Example Output

Path sum between 2 and 4 is 0

In this example, the initial values are set to zero, resulting in a path sum of zero between nodes 2 and 4.

## How to Run

1. **Compile the Program**: Use a C compiler like `gcc`.
    ```bash
    gcc -o hld hld.c
    ```
2. **Run the Program**: Provide input according to the format specified above.
    ```bash
    ./hld
    ```

3. **Sample Execution**:
    ```
    Input:
    5
    0 1
    1 2
    1 3
    3 4
    2 4

    Output:
    Path sum between 2 and 4 is 0
    ```

## Code Explanation

### Functions:
1. **addEdge**: Adds an edge in the adjacency list representation of the tree.
2. **Depth-First Search (DFS)**: Computes subtree sizes and identifies the heavy child for each node.
3. **decompose**: Decomposes the tree into heavy and light chains.
4. **buildSegmentTree**: Builds the segment tree for range queries.
5. **updateSegmentTree**: Updates a value in the segment tree.
6. **querySegmentTree**: Queries the sum of values in a range using the segment tree.
7. **queryPath**: Finds the sum of values along the path from node `u` to node `v`.

## Additional Notes

- Ensure the input tree is connected and acyclic, satisfying tree properties.
- Nodes are indexed from 0 to n-1.
- The program can be extended to support additional queries like maximum or minimum values along a path.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
