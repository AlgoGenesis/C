
# Euler's Algorithm for finding Eulerian paths and circuits

It an implementation of Euler’s Algorithm in C to find **Eulerian paths** and **Eulerian circuits** in an undirected graph.

## Overview

- Eulerian Path: A path that visits every edge of the graph exactly once.
- Eulerian Circuit: An Eulerian path that starts and ends at the same vertex.

This program:
- Checks if a graph has an Eulerian path or circuit.
- Uses Depth-First Search (DFS) to find the Eulerian path or circuit.
  
### Eulerian Path and Circuit Rules:
- A graph has an Eulerian circuit if all vertices have even degrees.
- A graph has an Eulerian path if exactly two vertices have odd degrees.
  
## How the Program Works

1. Input the number of vertices and edges.
2. Enter the edges to build the graph.
3. The program checks whether the graph has an Eulerian path or circuit.
4. The program prints the Eulerian path or circuit if it exists.

## Files

- `Euler's Algo.c`: The C program that implements Euler's Algorithm.
- `README.md`: This file explaining the project.

## Usage

1. Compile the program
   
2. Run the program

3. Input the number of vertices and edges, followed by the edges of the graph in `u v` format.

### Example:

Enter the number of vertices: 4
Enter the number of edges: 5
Enter the edges (u v) format:
0 1
0 2
1 2
2 3
1 3

Eulerian Path: 0 2 1 3 2 0


## How to Modify

- You can change the number of vertices, edges, and input graph data by editing the graph input section in the program.
- The program assumes an **undirected graph**. You can modify it to work with **directed graphs** if needed.

## Prerequisites

- A C compiler (e.g., GCC).
- Basic knowledge of C programming and graph theory.

## Features

- Detects whether a graph has an Eulerian path or circuit.
- Finds and prints the Eulerian path or circuit using DFS.

