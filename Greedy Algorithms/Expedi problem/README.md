# Expedi Problem

# Description

This program calculates the minimum number of stops a truck must make to reach a town. It takes into account the distance to the town and the petrol available at various stops. The truck can stop at any location to refuel, and the goal is to minimize the number of stops needed.

# Structures

1. Stop

- Description: A structure to represent a stop where the truck can refuel.
- Members:
  ** int distance: The distance from the town to the stop.
  ** int petrol: The amount of petrol available at that stop.

2. Functions

- int compare(const void a, const void b)
  Returns:
  -- A negative value if the distance of the first stop is less than that of the second (ascending order).
  -- Zero if they are equal.
  -- A positive value if the distance of the first stop is greater.

- int min_stops(int n, Stop arr, int initial_distance, int initial_petrol)

-- Description: Determines the minimum number of stops required for the truck to reach the town.

-- Returns:
The minimum number of stops required, or -1 if it is impossible to reach the destination.

## Main Function

- Description: The entry point of the program.
- Details:
  ** Prompts the user to enter the number of test cases (t).
  ** For each test case:

* Prompts the user to enter the number of stops (n).
* Dynamically allocates memory for an array of Stop structures based on n.
* For each stop, prompts the user to enter the distance from the town and the petrol available.
* Prompts the user to enter the initial distance of the truck from the town and the initial petrol.
* Calls min_stops() to calculate the minimum number of stops.
* If the result is -1, it prints -1. Otherwise, it prints the number of stops required.
** Frees the dynamically allocated memory for the arr of stops before exiting.

# Memory Management

-- Dynamic Memory Allocation
-- Freeing Memory
