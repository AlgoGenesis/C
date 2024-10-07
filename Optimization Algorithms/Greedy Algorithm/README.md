# Greedy Algorithm
## Description
Greedy Algorithm is an *optimization algorithm* which checks for local most optimal solution iteratively finding the **globally optimal solution** as a result. It is an appliaction based algorithm and used in many cases such as the infamous denomination problem.

## Problem Definition
Given: multiple pathways to choose from

Objective: choosing the path offering the most value (greedily)

## Code
In the code we will be trying to solve the well known problem of finding the number of denominations required to make the input amount using INR denominations.

### Overview
1. Create a decreasing array of denomination
2. Sum the number of times the largest denomination can be reduced from the target
3. Reduce that amount from the target
4. Return the result

### Complexity
Complexity of the program changes with the situation of application. In this case, it is _O(n)_.

