# Deadlock Detection in C
This repository contains a C implementation of a system to detect deadlocks in a resource allocation graph. It simulates a scenario where processes request resources and checks if any cycles are formed in the graph, which would indicate a deadlock.

## Algorithm Overview
The program tracks processes and resources, representing their relationships in a directed graph. It uses Depth-First Search (DFS) to detect cycles in the graph. A cycle indicates that a set of processes are waiting for resources held by each other, resulting in a deadlock.

## Process Flow:
1. Allocation: Resources are allocated to processes.
2. Request: Processes can request resources. After each request, the program checks for cycles.
3. Cycle Detection: DFS is used to detect cycles, indicating potential deadlocks.

## Data Structure
- Processes and Resources are represented using linked lists.
- Each process can be linked to a resource it has requested, and each resource can be allocated to a process.

## How to Run
### Prerequisites
You will need a C compiler, such as `gcc`, to compile and run the code.

## Steps to Run:
1. Clone the Repository or copy the code into a file named `deadlock_detection.c`.

2. Compile the C program using the following command:

``` bash
gcc deadlock_detection.c -o deadlock_detection
```
Run the compiled program:
``` bash
./deadlock_detection
```


## Code Explanation
- `Allocate()`: Allocates a resource to a process.
- `Request()`: Allows a process to request a resource and checks for cycles.
- `DFS()`: Performs Depth-First Search to detect cycles in the allocation graph.
- `DetectCycle()`: Iterates over all processes to check for deadlocks by using DFS.
- `Cleanup()`: Frees all dynamically allocated memory at the end of the program.


## Complexity
Time Complexity: The cycle detection algorithm using DFS has a time complexity of O(P + R), where P is the number of processes and R is the number of resources.