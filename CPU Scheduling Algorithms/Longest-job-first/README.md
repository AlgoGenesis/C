# Longest Job First (LJF) Scheduling

## Definition
Longest Job First (LJF) Scheduling is a non-preemptive scheduling algorithm that selects the process with the longest burst time to execute next.

## Problem Statement
Given a set of processes with their burst times, LJF Scheduling aims to optimize turnaround time by executing longer jobs before shorter ones.

## Overview
In LJF Scheduling, the processes are sorted based on their burst times in descending order. The process with the longest burst time is executed first, followed by the next longest, and so on.

## Time Complexity
- O(n^2) for sorting processes based on burst time, where n is the number of processes.

## Space Complexity
- O(n) for storing waiting time and turnaround time arrays.
