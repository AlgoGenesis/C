# Process Scheduling Simulation in C (First-Come, First-Serve Algorithm)

## Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [First-Come, First-Serve (FCFS) Algorithm](#first-come-first-serve-fcfs-algorithm)
- [Detailed Explanation of Functions](#detailed-explanation-of-functions)
- [Requirements](#requirements)
- [Installation and Execution](#installation-and-execution)
- [Example Usage](#example-usage)
- [Output Explanation](#output-explanation)
- [Memory Management](#memory-management)
- [Code Structure and Files](#code-structure-and-files)
- [Contributing](#contributing)
- [License](#license)

## Algorithm Overview

This algorithm simulates a **First-Come, First-Serve (FCFS) scheduling** algorithm for processes in an operating system. In FCFS scheduling, the CPU processes requests in the order of their arrival, ensuring that each process is completed before the next begins. This code calculates and displays essential metrics like **response time**, **turnaround time**, and **waiting time** for each process.

The FCFS algorithm is a non-preemptive scheduling algorithm and is straightforward to implement, making it ideal for understanding basic process scheduling.

## Features

- **Sorts processes by arrival time** to ensure the First-Come, First-Serve order.
- **Calculates Response Time** (time between arrival and first execution).
- **Calculates Turnaround Time** (total time from arrival to completion).
- **Calculates Waiting Time** (time spent waiting in the queue).
- **Displays Results** in a well-formatted table, showing calculated metrics for each process.

## First-Come, First-Serve (FCFS) Algorithm

The **FCFS** scheduling algorithm follows a non-preemptive approach where processes are served in the order of their arrival. Here’s how it works in this program:

1. **Sorting by Arrival Time**: The program first sorts all processes by their arrival times. If two processes have the same arrival time, they are further sorted by their ID.
2. **Sequential Execution**: Each process begins execution as soon as the CPU is available, based on the completion of the previous process.
3. **Metric Calculation**: For each process, the program calculates:
   - **Start Time**: When the process begins execution.
   - **Completion Time**: When the process finishes execution.
   - **Response Time**: Difference between start time and arrival time.
   - **Turnaround Time**: Difference between completion time and arrival time.
   - **Waiting Time**: Difference between turnaround time and burst time.

## Detailed Explanation of Functions

### 1. `find_response(struct Process* input, int n)`
   - Calculates the **response time** for each process.
   - Formula: **Response Time** = `start time - arrival time`

### 2. `find_tat(struct Process* input, int n)`
   - Calculates the **turnaround time** for each process.
   - Formula: **Turnaround Time** = `completion time - arrival time`

### 3. `find_wt(struct Process* input, int* tat, int n)`
   - Calculates the **waiting time** for each process.
   - Formula: **Waiting Time** = `turnaround time - burst time`

### 4. `schedule(struct Process* input, int n)`
   - Sorts processes by arrival time using the FCFS approach.
   - Determines **start time** and **completion time** for each process based on its burst time and order of arrival.

### 5. `comp(const void* a, const void* b)`
   - Comparison function used by `qsort` to sort processes by arrival time, and by ID if arrival times are equal.

## Requirements

To run this program, you need:
- A C compiler like `gcc`.
- Basic command-line skills for compiling and executing C programs.
