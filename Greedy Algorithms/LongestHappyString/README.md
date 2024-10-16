# Longest Happy String Algorithm

## Problem Description

The **Longest Happy String** problem involves generating the longest possible string using the characters 'a', 'b', and 'c' under specific constraints. A string is defined as "happy" if it meets the following criteria:

1. The string only contains the letters 'a', 'b', and 'c'.
2. The string does not contain any of the substrings "aaa", "bbb", or "ccc".
3. The string contains at most a specified number of occurrences for each character.

Given three integers \( a \), \( b \), and \( c \) representing the maximum counts of characters 'a', 'b', and 'c' respectively, the task is to construct the longest possible happy string. If multiple valid strings of the same length can be generated, any one of them is acceptable. If it's impossible to create a valid string, the algorithm should return an empty string.

## Solution Explanation

To solve the Longest Happy String problem, we can use a greedy approach combined with a loop. The solution involves the following steps:

1. **Character Selection**: Continuously select the character with the highest remaining count, ensuring that adding this character does not violate the constraint of avoiding three consecutive identical characters.
2. **Count Tracking**: Keep track of the number of consecutive characters added to ensure we do not exceed two consecutive characters of the same type.
3. **Building the Result**: Append the selected characters to the result string until no more characters can be added without violating the happy string conditions.

### Detailed Steps:
- Start with a result string and counters for each character.
- In a loop, determine which character can be added based on the current counts and the last two characters in the result string.
- If adding the character would create three consecutive identical characters, switch to the next character with the highest count.
- Continue this process until no characters can be added anymore.

## Example Usage

### Example 1:

```plaintext
Input: a = 1, b = 1, c = 7
Output: ccbccacc
```


## Complexity Analysis
- Time Complexity: O(n), where n is the total length of the generated string.
- Space Complexity: O(1) for character counts, plus O(n) for the resulting string.


