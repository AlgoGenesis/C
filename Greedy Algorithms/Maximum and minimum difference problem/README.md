# Maximum and minimum difference

# Description:

This program reads a number of integers, sort them , and then computes two values:

1.  The maximum value obtained from the absolute difference between pairs of the largest and smallest number.
2.  The minimum value obtained from the absolute differences between pairs of adjacent numbers in the sorted list.

# Functions:

1.  int compare(const void a , const void b):
    --Returns negative int if first element is less than second.
    -- Zero if they are equal
    -- A positive integer if the first element is greater than the second.

# In the main function

--Calculates the maximum value by summing the absolute differences between the largest elements and the smallest elements, iterating through the first half of the sorted array.
--Calculates the minimum value by summing the absolute differences between adjacent pairs of elements in the sorted array.

# Memory Management:

- Dynamic Memory Management
- Freeing Memory
