# Earliest Deadline First (EDF) Scheduling

## Definition
Earliest Deadline First (EDF) Scheduling is a dynamic priority scheduling algorithm used in real-time systems to schedule processes based on their deadlines.

## Problem Statement
Given a set of processes with their burst times and arrival times, EDF Scheduling aims to ensure that the process with the earliest deadline is executed first.

## Overview
In EDF Scheduling, processes are scheduled according to their deadlines. If a new process arrives with an earlier deadline than the currently running process, it preempts the current process.

## Time Complexity
- O(n log n) for sorting processes based on arrival and deadlines, where n is the number of processes.

## Space Complexity
- O(n) for storing waiting time and turnaround time arrays.
