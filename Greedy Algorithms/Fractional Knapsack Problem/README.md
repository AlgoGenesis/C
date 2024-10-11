# Fractional Knapsack Algorithm

# Description

This program solves the fractional knapsack problem using a greedy approach. It allows the user to input several items with their respective amounts and prices, and it determines the maximum value that can be accommodated in a knapsack with a specified capacity.

# Structures

-- Item: A structure to represent an item with its amount and price.
Members:
int amt: The amount or weight of the item.
int price: The price or value of the item.

# Function

1. int compare(const void a, const void b):
   Returns:

- A negative value if the price-to-amount ratio of the first item is less than that of the second (for sorting in descending order).
- Zero if they are equal.
- A positive value if the price-to-amount ratio of the first item is greater.

# Main Function:

Details:

- Prompts the user to enter the number of items (n).
- Dynamically allocates memory for an array of Item structures based on the value of n.
- For each item, prompts the user to enter the amount and price, and stores these values in the items array.
- Prompts the user to enter the capacity of the knapsack (knapsack).
- Sorts the array of items based on their price-to-amount ratio in descending order using qsort() and the compare() function.
- Initializes a variable ans to store the total value in the knapsack.
- Iterates over the sorted items and calculates the maximum value:
- If the current item's amount can fit into the remaining capacity of the knapsack, it adds the full price of the item to ans and decreases the capacity accordingly.
- If the current item's amount cannot fit, it adds the proportion of the item's price that corresponds to the remaining capacity and breaks the loop.
- Prints the maximum value that can be achieved in the knapsack.
- Frees the dynamically allocated memory for the items array before exiting.

# Memory Management

- Dynamic Memory Allocation
- Freeing Memory
