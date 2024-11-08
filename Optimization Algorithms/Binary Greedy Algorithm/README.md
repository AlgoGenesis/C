# Minimum Machines for Maximum Output

## Problem Description

You are given a list of tasks, each requiring a certain amount of time to complete. You have multiple machines available, each with a specific speed that determines how fast it can complete tasks. Your goal is to determine the minimum number of machines required to complete all tasks within a given time frame.

- **Input:**
  - `tasks`: An array of integers where each element represents the time required for a task.
  - `machines`: An array of integers where each element represents the speed of a machine (higher means faster).
  - `max_time`: The maximum allowed time to complete all tasks.

- **Output:**
  - An integer representing the minimum number of machines required to complete all tasks within `max_time`. If it is impossible to complete all tasks within the time limit, return `-1`.

## Example

```plaintext
Input:
  tasks = [10, 20, 30, 40]
  machines = [5, 10, 15]
  max_time = 20

Output:
  2
