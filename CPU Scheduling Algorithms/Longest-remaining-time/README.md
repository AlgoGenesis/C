# Longest Remaining Time First (LRTF) Scheduling

## Definition
Longest Remaining Time First (LRTF) Scheduling is a preemptive scheduling algorithm that selects the process with the longest remaining time to execute next.

## Problem Statement
Given a set of processes with their burst times, LRTF Scheduling aims to minimize waiting time by preempting shorter processes for longer ones.

## Overview
In LRTF Scheduling, at every time unit, the scheduler checks for the process with the longest remaining burst time. If a new process with a longer remaining time arrives, it preempts the currently running process.

## Time Complexity
- O(n^2) in the worst case, where n is the number of processes.

## Space Complexity
- O(n) for storing waiting time and turnaround time arrays.
