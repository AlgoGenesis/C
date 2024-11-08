# SCAN (Elevator) Disk Scheduling Algorithm

This project provides a C implementation of the SCAN (Elevator) disk scheduling algorithm. The SCAN algorithm is used to handle disk I/O requests efficiently by moving the disk head in one direction, servicing all requests in its path until it reaches the last request or end of the disk. The disk head then reverses direction and continues to service any remaining requests.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Algorithm Explanation](#algorithm-explanation)
- [Input and Output](#input-and-output)
- [Installation](#installation)
- [Usage](#usage)

## Overview
The SCAN (Elevator) algorithm improves seek time over simpler scheduling methods like First-Come, First-Served (FCFS) by reducing unnecessary back-and-forth movement of the disk arm. It is called the "Elevator" algorithm because it works similarly to an elevator moving up and down to pick up passengers, servicing requests in one direction before reversing.

## Features
- Services disk I/O requests based on the SCAN algorithm, moving the disk arm back and forth across the disk.
- Divides requests based on their position relative to the current head position.
- Calculates total seek time and average seek time for performance analysis.
- Reduces disk seek time by minimizing back-and-forth movement.

## Algorithm Explanation
1. **Initial Direction**: The disk head starts in a specified direction (either towards higher or lower track numbers).
2. **Sort Requests**: Requests are sorted into two arrays—`left` for requests less than the current head position and `right` for requests greater than or equal to the head position.
3. **Service Requests**:
   - First, the head moves in the specified direction, servicing requests on the way.
   - Once it reaches the end of the track or the last request in that direction, it reverses and services remaining requests in the opposite direction.
4. **Calculate Seek Time**: The algorithm calculates the total seek time based on the distance covered by the disk head to serve all requests.

This approach balances seek time across requests, avoiding starvation and reducing seek time compared to FCFS.

## Input and Output

### Input
- **Number of Requests**: Total number of track requests.
- **Track Requests**: Array of requested tracks.
- **Initial Head Position**: Starting position of the disk head.
- **Disk Size**: The total size of the disk (i.e., the maximum track number).
- **Initial Direction**: The starting direction of the head (1 for high tracks, 0 for low tracks).

### Output
- **Seek Sequence**: The order in which tracks are accessed.
- **Total Seek Time**: The total distance the head moved to service all requests.
- **Average Seek Time**: Average seek time calculated by dividing the total seek time by the number of requests.

## Installation

1. **Clone the Repository** or copy the code from `scan_algorithm.c`.
2. **Compile the Code** using GCC:
   ```bash
   gcc scan_algorithm.c -o scan_algorithm

## Usage

Run the program and provide the required inputs when prompted:

Enter the number of disk requests.
Enter the individual track requests as space-separated integers.
Enter the initial head position.
Enter the disk size (e.g., the maximum track number).
Enter the initial direction (1 for moving towards higher tracks, 0 for lower tracks).
The program will then output the seek sequence, total seek time, and average seek time.
