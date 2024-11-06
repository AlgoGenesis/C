# Flux Memory Balancer (FMB) in C

## Table of Contents
1. [Overview](#overview)
2. [Algorithm Details](#algorithm-details)
3. [Code Structure](#code-structure)
4. [How to Use](#how-to-use)
5. [Sample Input/Output](#sample-inputoutput)


## Overview
The **Flux Memory Balancer (FMB)** is a priority-based memory allocation algorithm designed to dynamically manage and allocate memory to processes based on their priority and requested memory. The algorithm aims to prioritize high-priority processes and ensure that lower-priority tasks receive memory only when there is enough available, using a "flux mechanism" to balance allocations.

## Algorithm Details
The Flux Memory Balancer algorithm performs the following steps:

1. **Initial Allocation**: Memory is allocated to each process based on its priority. Higher-priority processes (lower priority number) are allocated their requested memory first until the system's maximum memory is reached.
2. **Flux Mechanism**: If total memory allocation exceeds available capacity, the algorithm reduces memory from lower-priority processes in small increments, freeing up memory for higher-priority needs.
3. **Memory Redistribution**: The flux mechanism redistributes memory to ensure the total allocated memory is within the system limit, with high-priority processes receiving their requested memory.

## Code Structure
- **`Process` Structure**: Each process is represented by a structure containing:
  - `id`: Process identifier
  - `priority`: Process priority (lower value indicates higher priority)
  - `memoryReq`: Memory requested by the process
  - `allocatedMem`: Memory actually allocated to the process
- **`fluxMemoryBalancer()`**: Core function that allocates memory to processes based on priority and applies the flux mechanism to balance allocations.
- **`printProcesses()`**: Displays the process details, including priority, memory requested, and memory allocated.
- **`main()`**: Collects user input for processes and calls functions to execute the memory balancing and display results.

## How to Use
1. Clone or download this repository to your local machine.
2. Compile the code using a C compiler (see instructions below).
3. Run the executable and enter the number of processes when prompted.
4. For each process, input the priority and memory required.
5. The output will display each process's priority, memory requested, and allocated memory, as well as any adjustments applied by the flux mechanism.

## Sample Input/Output

### Sample Input

Enter number of processes: 3
Enter priority and memory required for process 1: 1 500
Enter priority and memory required for process 2: 2 300
Enter priority and memory required for process 3: 3 400

### Sample Output

ID      Priority    Memory Requested    Memory Allocated
1       1           500                 500
2       2           300                 300
3       3           400                 200

