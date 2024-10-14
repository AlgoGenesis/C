# Koko Eating Bananas Problem

### Overview

- The Koko Eating Bananas problem uses binary search to determine the minimum speed
  𝑘
  k at which Koko can eat all banana piles within a given number of hours h. Given a sorted array piles[], where each element represents the number of bananas in a pile, the goal is to find the smallest speed
  𝑘
  k that allows Koko to finish all bananas within h hours.

### Problem Definition

You are tasked with finding the smallest
𝑘
k such that:

```cpp
k = min_speed_to_finish_all(piles, h);
```

Where
𝑘
k is the number of bananas Koko eats per hour, and piles[] is the array of piles. If Koko finishes a pile in less than an hour, she will move to the next pile, ensuring she completes all piles in h hours or fewer.

### Algorithm Explanation

1. Initialization:

Start with left = 1 (Koko eats at least 1 banana per hour).
Set right to the size of the largest pile.

2. Binary Search:

Use the formula:

```cpp
mid = (left + right) // 2
```

- Case 1: If Koko can finish at speed mid, check smaller speeds by setting right = mid.
- Case 2: If Koko cannot finish, increase the speed by setting left = mid + 1.

### Return

- After the binary search, left will be the minimum speed
  𝑘
  k at which Koko can finish all bananas within the time limit.

### Time & Space Complexity

- Time Complexity: O(n\*logm) where n is number of piles and m is the size of the largest pile.
- Space Complexity: O(1), as only a few extra variables are used.

### Example

For piles[] = {30, 11, 23, 4, 20} and h = 6, the minimum speed Koko needs to finish all bananas is 23 bananas per hour.
