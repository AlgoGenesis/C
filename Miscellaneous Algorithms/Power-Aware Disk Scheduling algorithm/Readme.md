# Power-Aware Disk Scheduling (PADS) Algorithm

This project implements the Power-Aware Disk Scheduling (PADS) algorithm in C, a modified disk scheduling technique designed to reduce power consumption during disk I/O operations. The PADS algorithm optimizes disk head movement by balancing request servicing with energy-saving mechanisms, simulating a "low-power" mode when disk head movement would be excessive.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Algorithm Explanation](#algorithm-explanation)
- [Input and Output](#input-and-output)
- [Code Structure](#code-structure)
- [Example](#example)

## Overview

The Power-Aware Disk Scheduling (PADS) algorithm aims to enhance energy efficiency in systems by reducing unnecessary disk head movements. By implementing a modified SCAN (Elevator) scheduling algorithm, PADS can selectively enter a "low-power" mode if the next request is far from the current disk head position. This reduces power consumption while still achieving acceptable seek times and balancing I/O performance.

## Features

- **Efficient Disk I/O**: Services requests in a sequence to minimize disk head movement.
- **Power-Aware Mode**: Enters "low-power" mode when the disk head movement exceeds a specified threshold.
- **Flexible Direction Control**: Allows initial direction specification (toward higher or lower track numbers).
- **Seek Time Calculation**: Outputs total and average seek time for performance analysis.

## Algorithm Explanation

1. **Initial Direction**: The disk head starts moving in a specified direction (either toward higher or lower track numbers).
2. **Sorting Requests**: Requests are sorted to prioritize servicing those in the head's current path, ensuring minimal head movement.
3. **Low-Power Mode Activation**: If the distance to the next request exceeds a defined threshold, the algorithm simulates a "low-power" mode, reducing head movement until closer requests are available.
4. **Seek Time Calculation**: The algorithm calculates the total distance the head moved to service all requests, helping evaluate performance.

## Input and Output

### Input

- **Number of Requests**: Total number of track requests.
- **Track Requests**: Array of requested track positions.
- **Initial Head Position**: Starting position of the disk head.
- **Disk Size**: Total size of the disk (maximum track number).
- **Initial Direction**: Starting direction of the head (1 for high, 0 for low).

### Output

- **Seek Sequence**: The sequence of tracks serviced by the disk head.
- **Total Seek Time**: Total distance the disk head moved.
- **Average Seek Time**: Average seek time per request, useful for performance evaluation.

## Code Structure

├── pads_algorithm.c    # Contains the PADS algorithm implementation
├── README.md           # Project documentation
└── LICENSE             # License information

## Example

### Input:

Enter the number of disk requests: 5
Enter the disk requests: 45 130 10 180 90
Enter the initial position of the disk head: 50
Enter the initial direction (1 for high, 0 for low): 1

### Output:

Servicing request at track 90
Servicing request at track 130
Servicing request at track 180
Entering low-power mode to save energy.
Servicing request at track 45
Servicing request at track 10

Total seek time: 250
Average seek time: 50.00
