# Priority Scheduling

## Definition
Priority Scheduling is a process scheduling algorithm that assigns priority to each process. The process with the highest priority is executed first.

## Problem Statement
Given a list of processes with their burst times and priorities, this algorithm determines the order of execution based on process priority.

## Overview
In Priority Scheduling, if two processes have the same priority, they are scheduled according to their order of arrival.

## Time Complexity
- O(n^2), where n is the number of processes.

## Space Complexity
- O(n), for storing waiting time and turn-around time arrays.
