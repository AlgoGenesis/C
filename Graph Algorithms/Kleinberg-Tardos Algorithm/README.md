# Kleinberg-Tardos Algorithm in C

## Overview

The Kleinberg-Tardos Algorithm is used primarily in the context of constructing directed graphs, particularly for applications in social networks and other complex systems. This implementation provides a basic structure for creating a directed graph using an adjacency matrix.

## How It Works

1. **Graph Representation**: The graph is represented using an adjacency matrix, where each cell indicates whether an edge exists between two nodes.
2. **Node and Edge Input**: The user can input the number of nodes and edges, followed by specific edges that connect the nodes.
3. **Adjacency Matrix Output**: The program prints the adjacency matrix, which visually represents the graph's structure.

## Features

- Simple and clear representation of directed graphs.
- Easy to extend for additional graph-related functionalities.
- Useful for educational purposes in understanding graph structures.

## Compilation and Execution

To compile and run the program, follow these steps:

1. Ensure you have GCC installed on your system.
2. Save the code to a file named `kleinberg_tardos.c`.
3. Open a terminal and navigate to the directory containing the file.
4. Compile the program with the following command:

   ```bash
   gcc kleinberg_tardos.c -o kleinberg_tardos
   
5. Run the program:
     ```bash
     ./kleinberg_tardos

## Input
- The program first asks for the number of nodes in the graph.
- Then, it prompts for the number of edges and the specific edges in the format (src dest).

## Example
     ```bash
     Enter the number of nodes: 3
    Enter the number of edges: 2
    Enter edge (src dest): 0 1
    Enter edge (src dest): 1 2
    Adjacency Matrix:
    0 1 0 
    0 0 1 
    0 0 0 

## Limitations
- This implementation is a basic representation and does not include advanced graph algorithms such as pathfinding or cycle detection.
- The maximum number of nodes is limited to 100, which can be adjusted as needed.

##Conclusion
This implementation of the Kleinberg-Tardos algorithm provides a foundational understanding of graph construction using adjacency matrices. It serves as a stepping stone for more advanced graph algorithms and applications.