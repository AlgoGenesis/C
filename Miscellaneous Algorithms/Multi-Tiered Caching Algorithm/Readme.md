# Multi-Tiered Caching (MTC) Algorithm

This project implements a Multi-Tiered Caching (MTC) algorithm in C. The MTC algorithm manages multiple cache levels to improve data retrieval efficiency by storing frequently accessed data in faster, higher-priority caches. It dynamically moves data between cache levels based on access patterns, reducing retrieval time and optimizing memory utilization in systems with large data workloads.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Algorithm Explanation](#algorithm-explanation)
- [Input and Output](#input-and-output)
- [Example](#example)

## Overview

The Multi-Tiered Caching (MTC) algorithm uses multiple cache levels (e.g., L1, L2) to store frequently accessed data closer to the processor, reducing data retrieval time. This approach is particularly useful for systems with limited memory and a high volume of data requests, as it minimizes access time and improves memory management.

## Features

- Multi-tiered caching system with multiple cache levels (e.g., L1 and L2).
- Caching based on access frequency, moving data between levels as needed.
- Simple FIFO (First-In-First-Out) replacement policy in each cache tier.
- Efficient data access management for large datasets and high-throughput applications.

## Algorithm Explanation

1. **Cache Initialization**: Allocate memory for each cache level with a predefined size (L1 and L2).
2. **Data Lookup**:
   - Check if the data exists in the higher-priority cache (L1).
   - If not in L1, search the lower-priority cache (L2).
3. **Data Movement**:
   - If found in L2, move the data to L1 for quicker access in future requests.
   - If not found in either cache, add it to both L1 and L2 caches.
4. **Replacement Policy**: Uses a First-In-First-Out (FIFO) approach for data replacement, removing the oldest entry when the cache is full.


### Input

- **Data Requests**: An array of integers representing the data access requests.
- **L1 and L2 Cache Sizes**: Fixed cache sizes for each level (e.g., L1 with 3 slots, L2 with 5 slots).

### Output

The program will output the following for each request:
- Whether the requested data was found in L1, L2, or was not found.
- Any movement between cache levels when data is accessed.

### Example Input and Output

#### Example Input

Requests: {10, 20, 10, 30, 40, 50, 20, 60, 70, 10}
L1 Cache Size: 3
L2 Cache Size: 5

### Example Output

Value 10 added to L1 and L2.
Value 20 added to L1 and L2.
Value 10 found in L1 cache.
Value 30 added to L1 and L2.
Value 40 added to L1 and L2.
Value 50 added to L1 and L2.
Value 20 found in L1 cache.
Value 60 added to L1 and L2.
Value 70 added to L1 and L2.
Value 10 moved from L2 to L1.
