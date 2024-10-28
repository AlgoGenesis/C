# A* (A-Star) Algorithm in C

## Introduction

This repository contains an implementation of the **A* (A-Star) algorithm** in C. A* is a powerful algorithm used in graph traversal and pathfinding. It is widely used in applications like:
- Game development (pathfinding for characters)
- Robotics (autonomous navigation)
- Network routing
- AI for decision-making

A* works by combining the concepts of **Dijkstra's algorithm** and **greedy best-first search** using a heuristic to guide the search towards the goal, making it more efficient than Dijkstra's for certain use cases.

## How It Works

A* uses two primary costs:
- **g(n)**: The exact cost from the start node to the current node `n`.
- **h(n)**: The heuristic function that estimates the cost from `n` to the goal node. In this example, we use a simple hardcoded heuristic.

The total cost, `f(n)`, is defined as:
f(n) = g(n) + h(n)

At each step, A* selects the node with the smallest `f(n)` to explore, moving closer to the goal.

### Example Graph

The graph is represented as an adjacency matrix:

```bash
0 --10-- 1 --20-- 2
              |      \
             30      10
              |        \
              3 --10-- 4
```

  
The algorithm will compute the shortest path from node 0 to node 4, considering both the distance and the heuristic.

### File Structure

- `a_star.c`: The main C program implementing the A* algorithm.
- `README.md`: This file explaining the program.
- `output.txt`: Example output from running the program.

## Compilation & Execution

To compile and run the program:

```bash
gcc a_star.c -o a_star
./a_star

Path: 0 -> 1 -> 2 -> 4
Total cost: 40
