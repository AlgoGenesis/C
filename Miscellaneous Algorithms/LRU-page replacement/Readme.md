# Least Recently Used (LRU) Page Replacement Algorithm

## Overview

The Least Recently Used (LRU) page replacement algorithm is a cache management algorithm that removes the least recently used page when a page fault occurs and more frames are needed. It keeps track of page usage over time and uses this information to decide which page to evict.

## How It Works

1. **Page Reference:** When a page is requested, the algorithm checks if it is already in the cache (frame). If it is, no action is taken.
2. **Page Fault:** If the page is not in the cache, a page fault occurs, and the algorithm must decide which page to evict.
3. **Eviction:** The algorithm evicts the page that has not been used for the longest period of time (the least recently used).
4. **Page Replacement:** The new page is then loaded into the frame.

### Steps:

1. Initialize frames as empty.
2. For each requested page:
   - Check if it is already in one of the frames.
   - If yes, update its last accessed time.
   - If no, replace the least recently used page if there is a page fault.
3. Count the total number of page faults.

### Compilation

To compile the program, use the following command:
gcc lru_page_replacement.c -o lru_page_replacement

## input:

Pages: 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 0, 7, 0, 1

## output:

Current Frames: 7 -1 -1
Current Frames: 7 0 -1
Current Frames: 7 0 1
Current Frames: 2 0 1
Current Frames: 2 0 3
Current Frames: 0 3 2
Current Frames: 4 3 0
Current Frames: 4 2 3
Current Frames: 0 2 3
Current Frames: 0 3 2
Current Frames: 1 0 2
Current Frames: 7 0 1
Current Frames: 0 1 -1
Total Page Faults: 12

## Time Complexity

- **Time Complexity:** O(n _ m)  
  The algorithm requires O(n) time for each page request in the worst case, leading to O(n _ m) where `n` is the number of page requests and `m` is the number of frames.

## Space Complexity

- **Space Complexity:** O(m)  
  The algorithm uses a fixed amount of space for the frame and time arrays, where `m` is the number of frames.
