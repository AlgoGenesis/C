# Round Robin (RR) Scheduling

## Definition
Round Robin (RR) Scheduling is a pre-emptive scheduling algorithm that assigns a fixed time unit per process and cycles through them.

## Problem Statement
Given a set of processes with burst times and a time quantum, RR determines the order of execution based on the fixed time slice.

## Overview
In Round Robin, each process is allowed to run for a time quantum. If it does not finish, it is placed back in the queue. This continues until all processes are complete.

## Time Complexity
- O(n), where n is the number of processes.

## Space Complexity
- O(n), for storing waiting time and turn-around time arrays.
