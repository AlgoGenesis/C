# Sleep Sort Algorithm in C

## Overview

Sleep Sort is a humorous and non-standard sorting algorithm that sorts numbers by using the concept of sleeping for an amount of time proportional to the value of each number. This implementation in C utilizes threads to achieve the sorting by sleeping and then printing each number.

## How It Works

1. Each number is processed in its own thread.
2. The thread "sleeps" for a duration equal to the value of the number.
3. After sleeping, the thread prints the number.
4. As a result, smaller numbers will print first, achieving a sorted order.

## Features

- Uses threads to handle multiple numbers concurrently.
- Simple and illustrative of thread behavior.
- Not practical for large datasets or real-world applications.

## Compilation and Execution

To compile and run the program, follow these steps:

1. Make sure you have GCC installed on your system.
2. Save the code to a file named `sleepsort.c`.
3. Open a terminal and navigate to the directory containing the file.
4. Compile the program with the following command:

   ```bash
   gcc -pthread sleepsort.c -o sleepsort
   ./sleepsort

## Input
- The program first asks for the number of elements to sort (up to 100).
- Then, it prompts you to enter the numbers to be sorted.

## Example
    ```bash
    Enter the number of elements to sort (max 100): 5
    Enter 5 numbers:
    3
    1
    4
    2
    5

    Sorted numbers (using Sleep Sort): 1 2 3 4 5 

## Limitations
- Sleep Sort is not an efficient sorting algorithm and is primarily meant for educational purposes.
- It is impractical for sorting large datasets or in performance-sensitive applications due to the reliance on sleep durations.
