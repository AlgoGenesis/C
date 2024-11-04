# Banker's Algorithm in C

This project implements the **Banker's Algorithm** in C, a classic deadlock avoidance algorithm used in operating systems. The algorithm checks if resource allocation requests can be safely granted without causing deadlock by ensuring that the system remains in a "safe state" after each allocation.

## Table of Contents
- [Introduction](#introduction)
- [Algorithm Overview](#algorithm-overview)
- [Features](#features)
- [Example](#example)
- [Limitations](#limitations)

## Introduction

The Banker's Algorithm, designed by Edsger Dijkstra, is a deadlock avoidance algorithm that allocates resources to processes only if the system can remain in a safe state. A "safe state" is one where a sequence of processes can complete without running into resource contention issues that would lead to deadlock.

## Algorithm Overview

The Banker's Algorithm operates based on three main matrices:
- **Max Matrix**: Indicates the maximum resources each process may require.
- **Allocation Matrix**: Shows the resources currently allocated to each process.
- **Available Vector**: Tracks the currently available resources in the system.

When a process requests resources, the algorithm calculates if fulfilling the request will keep the system in a safe state. If so, the resources are allocated; otherwise, the request is denied.

## Features

- Deadlock avoidance for resource allocation.
- Identification of a safe sequence for process execution.
- Simple implementation using arrays and loops, compatible with standard C libraries.

## Example

### Example 1

#### Sample Input

Enter number of processes: 3
Enter number of resources: 3

Enter the Max matrix:
7 5 3
3 2 2
9 0 2

Enter the Allocation matrix:
0 1 0
2 0 0
3 0 2

Enter the Available resources:
3 3 2

#### Sample Input

System is in a safe state.
Safe sequence: 1 0 2

## Limitations

- **Fixed Resource and Process Count**: This implementation sets maximum limits for the number of processes and resources. Modifying these limits requires changing the code and recompiling.
- **Static Resource Allocation**: The algorithm only supports a static allocation based on the initial request. Dynamic resource changes or multiple resource requests are not handled.
- **Non-Preemptive**: Once allocated, resources cannot be preempted or re-assigned from one process to another, limiting flexibility.
- **Single Resource Type Per Process**: The current implementation assumes that each process only requests one type of resource at a time. For complex requests, code adjustments are needed.
- **Sequential Execution**: The algorithm performs sequential checks to find a safe sequence, which can be inefficient for systems with a large number of processes and resources.
