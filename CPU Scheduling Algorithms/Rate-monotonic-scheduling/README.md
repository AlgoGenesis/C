# Rate Monotonic Scheduling (RMS)

## Definition
Rate Monotonic Scheduling (RMS) is a fixed-priority algorithm used in real-time operating systems where tasks with shorter periods are assigned higher priorities.

## Problem Statement
Given a set of periodic tasks with their execution times and periods, RMS aims to ensure that all tasks meet their deadlines.

## Overview
In RMS, tasks are scheduled based on their rates (the inverse of their periods). The task with the shortest period is executed first. If multiple tasks are ready at the same time, the one with the shortest execution time is scheduled first.

## Time Complexity
- O(n log n) for sorting tasks based on their periods, where n is the number of tasks.

## Space Complexity
- O(n) for storing waiting time and turnaround time arrays.
