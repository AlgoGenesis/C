## Valid Parentheses

# Problem Description
The problem of "Valid Parentheses" is a common algorithmic challenge where you need to determine if a given string containing just the characters '(', ')', '{', '}', '[' and ']' is valid. A string is considered valid if:

Open brackets must be closed by the corresponding closing brackets.
Open brackets must be closed in the correct order.

# Example
Input: s = "()"
Output: true

Input: s = "()[]{}"
Output: true

Input: s = "(] "
Output: false

Input: s = "([)]"
Output: false

Input: s = "{[]}"
Output: true

# Solution Approach
A common approach to solving the valid parentheses problem is to use a stack data structure. The stack helps to keep track of the opening brackets and ensures that they are closed in the correct order.

Steps:
Initialize an empty stack.
Iterate through each character in the string:
If the character is an opening bracket ((, {, [), push it onto the stack.
If the character is a closing bracket (), }, ]):
Check if the stack is empty. If it is, return false (there's no corresponding opening bracket).
Pop the top element from the stack and check if it matches the current closing bracket. If it does not match, return false.
After processing all characters, check if the stack is empty. If it is empty, return true (all opening brackets were matched); otherwise, return false.

# Time and space complexity
Time Complexity: O(n), where n is the length of the string. We make a single pass through the string, performing constant time operations for each character.

Space Complexity: O(n) in the worst case, where all characters are opening parentheses, which would require storing them in the stack. In the best case, the space used would be O(1) if the string is valid and balanced.