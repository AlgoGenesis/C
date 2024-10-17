# Shortest Remaining Time (SRT) Scheduling

## Definition
Shortest Remaining Time (SRT) is a pre-emptive scheduling algorithm that selects the process with the least remaining execution time.

## Problem Statement
Given a set of processes with burst times, SRT aims to minimize the average waiting time by executing the process with the shortest remaining time first.

## Overview
In SRT, a process can be preempted if a new process arrives with a shorter burst time. This ensures optimal scheduling.

## Time Complexity
- O(n^2), where n is the number of processes.

## Space Complexity
- O(n), for storing waiting time and turn-around time arrays.
