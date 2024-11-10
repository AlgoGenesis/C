# Adaptive Disk Reordering (ADR) Algorithm

This project provides a C implementation of the Adaptive Disk Reordering (ADR) algorithm, which dynamically adjusts the order of disk I/O requests to optimize disk access times. By prioritizing requests based on their proximity to the current disk head position, this algorithm minimizes seek time, making it ideal for applications requiring efficient disk scheduling.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Algorithm Explanation](#algorithm-explanation)
- [Input and Output](#input-and-output)
- [Code Structure](#code-structure)
- [Example](#example)

## Overview
The Adaptive Disk Reordering (ADR) algorithm reduces disk seek time by dynamically reordering I/O requests based on the disk head's current position. It enhances performance in environments with frequent disk access patterns by minimizing the back-and-forth movement of the disk arm, thus lowering the overall seek time and improving response time.

## Features
- **Dynamic Request Reordering**: Orders pending I/O requests based on current disk head position to reduce seek time.
- **Seek Time Optimization**: Calculates total and average seek time, providing metrics to evaluate performance.
- **Efficient Disk Head Movement**: Minimizes disk head movement by servicing the nearest unserviced requests first.
- **Simple and Adaptable**: Easy to integrate into systems where frequent disk I/O occurs.

## Algorithm Explanation
The ADR algorithm follows these steps:
1. **Current Head Position Check**: Starts by checking the current head position and orders requests based on their proximity to this position.
2. **Request Sorting**: Requests are sorted dynamically during each iteration, ensuring that the closest unserviced request is serviced next.
3. **Service Requests**:
   - Services requests sequentially, moving the disk head to the nearest unserviced request and updating the seek time.
4. **Seek Time Calculation**: After all requests are serviced, the algorithm outputs the total and average seek times for evaluation.

## Input and Output

### Input
- **Number of Requests**: The total number of track requests (integer).
- **Track Requests**: An array containing track numbers of each request.
- **Initial Head Position**: The starting position of the disk head (integer).

### Output
- **Seek Sequence**: The order in which tracks are accessed by the disk head.
- **Total Seek Time**: The cumulative distance the disk head traveled to service all requests.
- **Average Seek Time**: Average distance traveled per request.

## Code Structure
The code for the ADR algorithm is organized as follows:
.
├── ADR.c      # Main C file with the ADR implementation
└── Readme.md   # Project documentation

### Example

Enter number of disk requests: 5
Enter track numbers for the requests:
Request 1: 55
Request 2: 14
Request 3: 37
Request 4: 98
Request 5: 25
Enter initial head position: 50

Seek Sequence: 50 -> 55 -> 37 -> 25 -> 14 -> 98
Total Seek Time: 96
Average Seek Time: 19.20
