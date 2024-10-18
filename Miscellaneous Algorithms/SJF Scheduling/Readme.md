# Shortest Job First (SJF) CPU Scheduling

## Overview

The Shortest Job First (SJF) CPU Scheduling algorithm is a non-preemptive scheduling algorithm that selects the process with the smallest burst time for execution. This algorithm is optimal in minimizing average waiting time for a set of processes.

## How It Works

1. **Process Sorting:** The processes are sorted based on their burst times in ascending order.
2. **Waiting Time Calculation:** The waiting time for each process is calculated based on the burst times of the previous processes.
3. **Turnaround Time Calculation:** The turnaround time for each process is determined by adding its burst time to its waiting time.

### Steps:

1. Sort the processes based on their burst times.
2. Calculate the waiting time for each process.
3. Calculate the turnaround time for each process.
4. Compute the average waiting and turnaround times.

### Compilation

To compile the program, use the following command in your terminal:
gcc sjf_scheduling.c -o sjf_scheduling

## input:

Process Burst Time
1 6
2 8
3 7

## output

Process Burst Time Waiting Time Turnaround Time
1 6 0 6
3 7 6 13
2 8 13 21
Average Waiting Time: 6.33
Average Turnaround Time: 13.33

## Time Complexity

- **Time Complexity:** O(n²)  
  The algorithm involves sorting the processes and calculating waiting and turnaround times, leading to a quadratic time complexity.

## Space Complexity

- **Space Complexity:** O(1)  
  The algorithm uses a constant amount of space for the arrays storing waiting times and turnaround times.
