# Shortest Job Next (SJN) / Shortest Job First (SJF) Scheduling

## Definition
Shortest Job Next (SJN) or Shortest Job First (SJF) is a scheduling algorithm that selects the process with the smallest execution time.

## Problem Statement
Given a set of processes with their burst times, SJF aims to minimize the average waiting time by executing the shortest jobs first.

## Overview
In SJF, the process with the least burst time is selected for execution next. If multiple processes have the same burst time, they are scheduled in the order of their arrival.

## Time Complexity
- O(n^2), where n is the number of processes.

## Space Complexity
- O(n), for storing waiting time and turn-around time arrays.
