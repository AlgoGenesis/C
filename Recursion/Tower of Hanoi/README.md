# Tower of Hanoi Using Recursion

## Description

The **Tower of Hanoi** is a mathematical puzzle that involves three pegs (rods) and a set of disks of different sizes. The goal is to move all the disks from a source peg to a destination peg, using an auxiliary peg, while adhering to certain rules.

### Problem Definition

Given `n` disks and three pegs — source, destination, and auxiliary — the objective is to move all the disks from the source peg to the destination peg, following these rules:
1. Only one disk can be moved at a time.
2. Each move involves taking the top disk from one peg and placing it on another peg.
3. No larger disk can be placed on top of a smaller disk.

### Algorithm Overview

1. **Base Case**:  
   - If there is only one disk, simply move it from the source peg to the destination peg.

2. **Recursive Case**:  
   - Move the top `n-1` disks from the source peg to the auxiliary peg, using the destination peg as an auxiliary.
   - Move the `n`th disk (the largest) from the source peg to the destination peg.
   - Move the `n-1` disks from the auxiliary peg to the destination peg, using the source peg as an auxiliary.

### Example:

For `n = 3` disks:
- Move 2 disks from Source to Auxiliary.
- Move 1 disk from Source to Destination.
- Move 2 disks from Auxiliary to Destination.

### Time Complexity

The time complexity of the Tower of Hanoi problem is **O(2^n)**, where `n` is the number of disks. This exponential complexity arises because each time we increase the number of disks, the number of moves required doubles (plus one additional move for the nth disk).
