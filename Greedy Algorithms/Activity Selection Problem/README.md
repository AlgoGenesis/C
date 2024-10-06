# Activity Selection Problem

# Description

This program calculates the maximum number of non-overlapping intervals from a list provided by the user. It employs a greedy algorithm that sorts the intervals based on their ending times and iterates through them to select non-overlapping intervals.

# Structures

1. Interval

- Description: A structure to represent an interval with a start and end time.
- Members:
  -- int start: The starting time of the interval.
  -- int end: The ending time of the interval.

# Functions

1. int compare(const void a, const void b):

--Returns:
** A negative value if the end time of the first interval is less than that of the second.
** Zero if they are equal.
** A positive value if the end time of the first interval is greater.

# Main Function

- Description: The entry point of the program.
- Details:

* Prompts the user to enter the number of intervals (n).
* Dynamically allocates memory for an array of Interval structures based on n.
* For each interval, prompts the user to enter the start and end times.
* Sorts the intervals based on their ending times using the qsort() function and the compare() function.
* Initializes a counter take to 1 (to include the first interval) and sets end to the end time of the first interval.
* Iterates through the sorted intervals and checks if the starting time of the current interval is greater than or equal to the end time of the last selected interval:
  -- If true, increments the take counter and updates end to the current interval's end time.
* Prints the maximum number of non-overlapping intervals.
* Frees the dynamically allocated memory for the arr of intervals before exiting.

# Memory Management

- Dynamic Memory Allocation
- Freeing Memory
