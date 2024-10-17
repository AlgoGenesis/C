# First-Come, First-Served (FCFS) Scheduling

## Definition
First-Come, First-Served (FCFS) is the simplest scheduling algorithm that schedules processes in the order of their arrival. 

## Problem Statement
Given a list of processes with their burst times, FCFS determines the order in which processes will be executed based on their arrival times.

## Overview
In FCFS, the process that arrives first is executed first. If two processes arrive at the same time, they are scheduled according to their order in the ready queue.

## Time Complexity
- O(n), where n is the number of processes.

## Space Complexity
- O(n), for storing waiting time and turn-around time arrays.
