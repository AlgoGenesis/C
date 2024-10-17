# Multilevel Queue Scheduling

## Definition
Multilevel Queue Scheduling is a scheduling algorithm that partitions the ready queue into several separate queues based on process priority.

## Problem Statement
Given a set of processes with different priorities, this algorithm categorizes them into multiple queues to manage their execution.

## Overview
In Multilevel Queue Scheduling, processes are placed in different queues based on their priority, and each queue can have its own scheduling algorithm.

## Time Complexity
- O(n), where n is the number of processes.

## Space Complexity
- O(n), for storing waiting time and turn-around time arrays.
