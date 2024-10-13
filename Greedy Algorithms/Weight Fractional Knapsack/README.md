# Weight Fractional Knapsack Algorithm

# Description

This program solves the fractional knapsack problem using a greedy approach. It allows the user to input multiple items with their respective weights (amounts) and values (prices) and determines the maximum protein (weight) that can be accommodated in a knapsack with a specified capacity.

# Structures

-- Item: A structure to represent an item with its weight and value.
Members:
int weight: The weight (amount) of the item.
int value: The value (price) of the item.
double weight_value_ratio: The ratio of weight to value used for sorting.

# Function

1. int compare(const void *a, const void *b)
   Compares two items based on their weight-to-value ratio, used for sorting items in descending order of this ratio.
   Returns:

- A positive value if the weight-to-value ratio of the first item is greater than the second (for sorting in descending order).
- Zero if the ratios are equal.
- A negative value if the first item's ratio is less than the second.

# Main Function:

Details:

- Input Number of Items: Prompts the user to enter the number of items (n).
- Input Item Details: For each item, prompts the user to enter the weight (amount) and value (price) and calculates the weight-to-value ratio.
- Input Knapsack Capacity: Prompts the user to enter the capacity of the knapsack.
- Sort Items: Uses qsort() with the compare function to sort items in descending order of their weight-to-value ratio.
- Calculate Maximum Protein:
- Initializes a variable total_protein to store the total weight (protein) added to the knapsack.
- Iterates through the sorted items:
- If the current item can fully fit in the knapsack, adds its weight to total_protein and decreases the capacity.
- If it can’t fully fit, adds only a fraction of the item’s weight proportional to the remaining capacity and exits the loop.
- Output Result: Displays the maximum protein that can fit in the knapsack.

# Memory Management

- Static Memory Allocation: Memory for the items array is allocated statically based on the input number of items.
- Freeing Memory: The program completes without requiring explicit memory deallocation, as no dynamic memory was used in this implementation.
