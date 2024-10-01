# Tower of Hanoi Using Recursion

## Description
The Tower of Hanoi is a classic puzzle that involves moving a set of disks from one peg to another, using a third peg as an auxiliary. The challenge lies in moving the disks according to specific rules.

### Problem Definition
Given three pegs and a number of disks of different sizes, the objective is to move all the disks from the source peg to the destination peg, following these rules:
1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or an empty peg.
3. No disk may be placed on top of a smaller disk.

### Algorithm Overview
**Base Case**: If there is only one disk, move it directly from the source peg to the destination peg.  
**Recursive Case**: 
1. Move the top n-1 disks from the source peg to the auxiliary peg.
2. Move the nth disk (largest) from the source peg to the destination peg.
3. Move the n-1 disks from the auxiliary peg to the destination peg.

### Time Complexity
The time complexity for solving the Tower of Hanoi problem using recursion is O(2^n), where n is the number of disks. This exponential time complexity arises because the number of moves doubles with each additional disk.