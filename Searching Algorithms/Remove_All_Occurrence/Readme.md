## Remove All Occurrence

# Problem Description
To remove all the occurrences of an element in an array.
Given a string and a character, remove all occurrences of that character from the string. The resulting string should maintain the order of the remaining characters and should be null-terminated.

## Proposed Solution
To solve the problem of removing all occurrences of a specific character from a string ,you can follow these steps:

Iterate through the original string.
Copy characters to a new string only if they are not the target character.
Terminate the new string properly.

# Example :

Input:
String: "hello world"
Character to remove: 'o'
Output:
Resultant String: "hell wrld"

Complexity Analysis
# Time Complexity:

The time complexity of this algorithm is O(n), where n is the length of the input string. This is because we need to iterate through each character of the string exactly once to check if it matches the character to be removed.

# Space Complexity:

The space complexity is also O(n) in the worst case, as we may need to create a new string to hold the result. In the worst case, where none of the characters are removed, the size of the result string could be equal to the input string.