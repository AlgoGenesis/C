# Indian Denomination Problem

# Description

This program determines the minimum number of currency notes required to achieve a specified monetary amount using the largest available denominations first. It uses a greedy algorithm approach to solve the problem.

# Function

1. int compare(const void a, const void b):

- A positive value if the first integer is less than the second (for descending order).
- A negative value if the first integer is greater.
- Zero if they are equal.

# Main

- Initializes an array of integers representing different currency notes.
- Calculates the number of available currency denominations (n).
- Prompts the user to enter an amount (amt) that they want to achieve using the currency notes.
- Sorts the array of currency notes in decreasing order using qsort() and the compare() function.
- Initializes a variable sum to count the total number of notes required and dynamically allocates an array result to store the specific notes used.
- Uses a loop to iterate over the currency notes and calculates how many notes of each denomination are needed:
  --For each note, it determines how many of that note are required by dividing the remaining amount (amt) by the denomination.
  --Updates the total count of notes.
  --Updates the remaining amount.
  --Stores each note used in the result array.
- Prints the total number of notes required.
- Outputs each denomination used to make up the amount.
- Frees the dynamically allocated memory for the result array before exiting.

# Memory Management

- Dynamic Memory Allocation
- Freeing Memory
