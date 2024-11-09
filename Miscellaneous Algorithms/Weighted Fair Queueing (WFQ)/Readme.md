# Weighted Fair Queueing (WFQ) Algorithm

## Overview

**Weighted Fair Queueing (WFQ)** is a sophisticated CPU scheduling algorithm designed to allocate resources fairly among multiple processes based on their assigned weights. Unlike traditional scheduling algorithms that may treat all processes equally or prioritize based on a fixed criterion, WFQ ensures that each process receives a portion of the CPU proportional to its weight. This makes WFQ particularly suitable for environments where processes have varying levels of importance or resource requirements.

This repository contains a C implementation of the WFQ algorithm. The program simulates the scheduling of multiple processes, each with a unique weight and burst time, and determines their completion times based on the WFQ scheduling policy.

## Theory

### Weighted Fair Queueing (WFQ) Fundamentals

WFQ is an extension of the Fair Queueing (FQ) algorithm, which aims to distribute CPU time fairly among all processes. WFQ enhances FQ by introducing weights, allowing certain processes to receive more CPU time relative to others based on their assigned importance or priority.

#### Key Concepts:

1. **Weight Assignment**: Each process is assigned a weight that signifies its relative importance or required share of CPU time. A higher weight means the process should receive a larger portion of the CPU.

2. **Proportional Scheduling**: The CPU time allocated to each process is proportional to its weight. For example, a process with a weight of 3 will receive three times the CPU time of a process with a weight of 1.

3. **Fairness**: WFQ ensures that all processes get their fair share of CPU time over time, preventing any single process from monopolizing the CPU.

4. **Bandwidth Allocation**: In networking, WFQ is used to allocate bandwidth fairly among multiple data flows, ensuring that each flow gets bandwidth proportional to its weight.

### WFQ Scheduling Mechanism

1. **Initialization**:
   - Assign each process a unique ID, weight, and burst time (total CPU time required).
   - Define a base time quantum, which is the standard time slice allocated to processes with a weight of 1.

2. **Effective Time Quantum Calculation**:
   - For each process, calculate the effective time quantum by multiplying the base quantum with the process's weight.
   - `Effective Quantum = Base Quantum * Weight`

3. **Scheduling Loop**:
   - Iterate through the list of processes in a round-robin fashion.
   - For each process with remaining burst time:
     - Allocate CPU time equal to its effective quantum or the remaining burst time, whichever is smaller.
     - Update the current time and the process's remaining burst time.
     - If a process completes, record its finish time.
   
4. **Completion**:
   - Continue the loop until all processes have completed execution.

### Example

Consider three processes with the following attributes:

| Process | Weight | Burst Time |
|---------|--------|------------|
| P1      | 1      | 10         |
| P2      | 3      | 15         |
| P3      | 2      | 20         |

- **Base Time Quantum**: 2 units

**Scheduling Sequence**:
1. **P1**: Executes for `2 * 1 = 2` units (Remaining: 8)
2. **P2**: Executes for `2 * 3 = 6` units (Remaining: 9)
3. **P3**: Executes for `2 * 2 = 4` units (Remaining: 16)
4. **P1**: Executes for `2 * 1 = 2` units (Remaining: 6)
5. **P2**: Executes for `2 * 3 = 6` units (Remaining: 3)
6. **P3**: Executes for `2 * 2 = 4` units (Remaining: 12)
7. **...** and so on until all processes complete.

## Time and Space Complexity

### Time Complexity

The time complexity of the WFQ implementation provided is **O(n²)** in the worst case, where `n` is the number of processes. This complexity arises because, for each cycle, the algorithm iterates through all `n` processes, and in the worst case, each process may require up to `n` iterations to complete its burst time.

However, in practical scenarios, especially when the number of processes is relatively small, the algorithm performs efficiently. Optimizations such as prioritizing processes based on remaining burst time or using more efficient data structures (e.g., priority queues) can help reduce the time complexity.

### Space Complexity

The space complexity of the WFQ algorithm is **O(n)**, where `n` is the number of processes. This is due to the storage requirements for maintaining information about each process, including its ID, weight, remaining burst time, and finish time.

## Conclusion

The Weighted Fair Queueing (WFQ) algorithm offers a balanced approach to CPU scheduling by combining fairness with priority-based resource allocation. By assigning weights to processes, WFQ ensures that critical tasks receive more CPU time while still maintaining fairness among all processes. This makes WFQ particularly useful in environments where processes have diverse priorities and resource requirements.

The provided C implementation serves as a foundational example of WFQ, demonstrating how weighted scheduling can be achieved programmatically. Further enhancements, such as dynamic weight adjustment or integration with real-time systems, can be explored to extend the algorithm's applicability.

---
