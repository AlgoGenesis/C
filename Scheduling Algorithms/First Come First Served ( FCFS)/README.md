# First Come First Serve (FCFS) Scheduling Algorithm

## Description

The **First Come First Serve (FCFS)** scheduling algorithm is one of the simplest CPU scheduling algorithms. In this algorithm, the process that arrives first is executed first. This non-preemptive algorithm is easy to implement and understand.

## Problem Definition

Given a set of processes, each with an arrival time and burst time, the task is to schedule the processes using the FCFS scheduling algorithm and calculate the waiting time and turnaround time for each process.

### Input:

- Number of processes.
- For each process, the arrival time and burst time.

### Output:

- A table displaying the process ID, arrival time, burst time, waiting time, and turnaround time.

### Algorithm Overview

1. **Input Processes**: The user inputs the number of processes and their respective arrival and burst times.
2. **Sort by Arrival Time**: Processes are sorted based on their arrival time.
3. **Calculate Waiting Time**: For each process, the waiting time is calculated based on the burst times of previously scheduled processes.
4. **Calculate Turnaround Time**: The turnaround time for each process is calculated as the sum of its burst time and waiting time.
5. **Display Results**: The results are displayed in a formatted table.

### Time Complexity

The time complexity of the FCFS scheduling algorithm is generally as follows:

- **Best Case**: `O(n^2)` when the processes are already sorted by arrival time.
- **Average Case**: `O(n^2)` under typical conditions due to the sorting process.
- **Worst Case**: `O(n^2)` for any input due to its nature of calculating waiting times.

### Advantages

- Simple to implement and understand.
- Ensures fairness as every process gets executed in the order of arrival.

### Disadvantages

- Can lead to the "convoy effect," where short processes wait for a long process to finish, resulting in poor average waiting time.
- Not suitable for time-sharing systems.

### Conclusion

The FCFS scheduling algorithm is a straightforward method for scheduling processes in a queue. While it guarantees fairness, it may not always be the most efficient choice for optimizing turnaround or waiting times in more complex systems.

