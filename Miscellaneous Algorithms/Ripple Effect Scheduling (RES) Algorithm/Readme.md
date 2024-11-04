# Ripple Effect Scheduling (RES) Algorithm in C

This project implements the **Ripple Effect Scheduling (RES)** algorithm in C, a priority-based scheduling algorithm that minimizes disruptions to lower-priority tasks. This algorithm sorts tasks based on their priority and calculates waiting and turnaround times for each process. Additionally, it applies a "ripple effect" adjustment to reduce the waiting time of lower-priority tasks.

## Table of Contents

1. [Overview](#overview)
2. [Algorithm Details](#algorithm-details)
3. [Code Structure](#code-structure)
4. [How to Use](#how-to-use)
5. [Sample Input/Output](#sample-inputoutput)
6. [Compilation and Execution](#compilation-and-execution)
7. [Contributing](#contributing)
8. [License](#license)

## Overview

The Ripple Effect Scheduling (RES) algorithm is a **priority-based CPU scheduling algorithm** that aims to:
- Prioritize tasks based on their priority level (where a lower priority number indicates higher priority).
- Minimize disruptions to lower-priority tasks using a "ripple effect" adjustment, where each process slightly adjusts the waiting time of the next lower-priority process.

This approach ensures that high-priority tasks are executed first but avoids causing excessive delays for lower-priority tasks.

## Algorithm Details

The algorithm involves the following steps:

1. **Sorting by Priority**: Processes are sorted by priority (ascending order), where a lower priority number indicates a higher priority.
2. **Waiting Time Calculation**:
   - For each process, calculate the waiting time as the cumulative burst time of previous processes.
   - Apply the "ripple effect" by reducing the waiting time of the next process slightly if it has a lower priority, ensuring it doesn't fall below zero.
3. **Turnaround Time Calculation**:
   - For each process, calculate the turnaround time as the sum of waiting time and burst time.
4. **Average Waiting and Turnaround Times**: Display the average waiting and turnaround times for all processes.

## Code Structure

- **`Process` struct**: Stores the details for each process, including `id`, `priority`, `burstTime`, `waitingTime`, and `turnaroundTime`.
- **`rippleEffectScheduling()`**: Sorts processes by priority and calculates waiting and turnaround times, applying the ripple effect.
- **`printProcesses()`**: Displays the process details in a tabular format and calculates average waiting and turnaround times.
- **`main()`**: Collects user input for each process and invokes the scheduling functions.

## How to Use

1. Clone or download this repository to your local machine.
2. Compile the code using a C compiler (instructions below).
3. Run the executable and input the number of processes.
4. For each process, enter the priority and burst time when prompted.

The output will display the waiting time and turnaround time for each process, along with the average waiting and turnaround times.

## Sample Input/Output

### Sample Input

Enter number of processes: 3
Enter priority and burst time for process 1: 1 5
Enter priority and burst time for process 2: 2 8
Enter priority and burst time for process 3: 1 2

### Sample Output

ID      Priority    Burst Time      Waiting Time    Turnaround Time
1       1           5               0               5
3       1           2               5               7
2       2           8               4               12

Average Waiting Time: 3.00
Average Turnaround Time: 8.00

