# Priority Scheduling Algorithm

## Description

The **Priority Scheduling** algorithm is a preemptive or non-preemptive scheduling algorithm based on the priority of processes. In this algorithm, each process is assigned a priority, and the CPU is allocated to the process with the highest priority (lowest numerical value). If two processes have the same priority, the one that arrived first is scheduled first.

### Problem Definition

Given:
- A set of processes, each with a priority, arrival time, and burst time.

Objective:
- Schedule the processes using the Priority Scheduling algorithm and calculate the waiting time and turnaround time for each process.

### Input

- Number of processes.
- For each process, the arrival time, burst time, and priority.

### Output

- A table displaying the process ID, arrival time, burst time, priority, waiting time, and turnaround time.


### Algorithm Overview

1. **Input Processes**: The user inputs the number of processes and their respective arrival times, burst times, and priorities.
2. **Sort by Arrival and Priority**: Processes are sorted based on arrival time and priority.
3. **Calculate Waiting Time**: For each process, the waiting time is calculated based on the burst times of previously scheduled processes.
4. **Calculate Turnaround Time**: The turnaround time for each process is calculated as the sum of its burst time and waiting time.
5. **Display Results**: The results are displayed in a formatted table.

### Time Complexity

The time complexity of the Priority Scheduling algorithm is generally as follows:

- **Best Case**: `O(n log n)` when the processes are already sorted by priority.
- **Average Case**: `O(n log n)` under typical conditions due to the sorting process.
- **Worst Case**: `O(n log n)` for any input.

### Advantages

- Provides better turnaround time for high-priority processes.
- Reduces the waiting time for processes with higher priority.

### Disadvantages

- Starvation can occur for low-priority processes.
- Requires knowledge of the priorities of processes in advance.

### Conclusion

The Priority Scheduling algorithm is effective in scenarios where priority management is crucial. While it improves turnaround time for high-priority processes, it may lead to starvation for lower-priority processes.



