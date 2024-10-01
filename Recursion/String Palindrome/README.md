#  String Palindrome Using Recursion

## Description
A palindrome is a string that reads the same backward as forward. This property can be checked using recursion, where we compare characters from both ends of the string.

### Problem Definition
Given a string, the objective is to determine if it is a palindrome using a recursive function.

### Algorithm Overview
**Base Case**: If the starting index is greater than or equal to the ending index, it is a palindrome.  
**Recursive Case***: Compare the characters at the start and end indices. If they match, recursively check the substring excluding these characters.

### Time Complexity
The time complexity for checking if a string is a palindrome using recursion is O(n), where n is the length of the string. This is because we are making n/2 comparisons.