# SmartSlice CPU Scheduling Algorithm

SmartSlice is a dynamic CPU scheduling algorithm that adapts time slices based on the burst time of each process, offering an optimized version of the Round Robin scheduling method. By assigning smaller time slices to short tasks and larger slices to longer tasks, SmartSlice reduces context switching, lowers wait times, and improves overall process efficiency.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Algorithm Explanation](#algorithm-explanation)
- [Input and Output](#input-and-output)
- [Installation](#installation)
- [Example](#example)


## Overview
SmartSlice is designed for environments with a mix of short and long tasks, where traditional Round Robin scheduling may not be efficient. By dynamically adjusting time slices according to each process's burst time, SmartSlice minimizes unnecessary context switches and allows short tasks to complete quickly. This method leads to a balanced system load and improved turnaround and waiting times for most tasks.

## Features
- **Adaptive Time Slices**: Assigns smaller time slices to short tasks and larger slices to longer tasks.
- **Reduced Context Switching**: Minimizes unnecessary context switching, saving CPU resources.
- **Improved Efficiency**: Short tasks complete quickly, while long tasks make steady progress, balancing performance.
- **Performance Metrics**: Calculates total and average wait and turnaround times for all processes.

## Algorithm Explanation
1. **Time Slice Calculation**: The time slice is determined based on each process's burst time:
   - Short bursts get smaller slices.
   - Medium bursts get moderate slices.
   - Long bursts get larger slices.

2. **Scheduling**:
   - Iterates through processes in a loop.
   - Applies the calculated time slice to each process based on its remaining burst time.
   - Updates remaining burst time and continues until all processes are completed.

3. **Performance Metrics**:
   - Calculates total and average wait times and turnaround times for performance analysis.

This dynamic approach improves system performance, especially in multitasking environments with varying process burst times.

## Input and Output

### Input
- **Number of Processes**: Total number of processes.
- **Burst Times**: Burst times of each process, provided by the user.
  
### Output
- **Execution Order**: Shows the execution sequence with each process's start and end times.
- **Wait Times**: Time each process waited before execution.
- **Turnaround Times**: Total time taken for each process to complete.
- **Average Metrics**: Average wait time and turnaround time across all processes.

## Installation

1. **Clone the Repository** or copy the code from `smartslice.c`.
2. **Compile the Code** using GCC:
   ```bash
   gcc smartslice.c -o smartslice

## Example

###  Input
Enter the number of processes: 3
Enter burst time for process 1: 6
Enter burst time for process 2: 8
Enter burst time for process 3: 3

### Output
Process 1 executing from time 0 to 4
Process 2 executing from time 4 to 10
Process 3 executing from time 10 to 12
Process 1 executing from time 12 to 14

Process    Burst Time    Wait Time    Turnaround Time
1          6             8            14
2          8             4            12
3          3             10           13

Average Wait Time: 7.33
Average Turnaround Time: 13.00
