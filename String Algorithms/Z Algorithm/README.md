# Z Algorithm

## Description

The Z Algorithm is a linear time string matching algorithm that finds all occurrences of a pattern in a text. It uses a Z array, which stores the length of the longest substring starting from each position that is also a prefix of the string.

## How it works

1. Concatenate the pattern, a special character (e.g., $), and the text.
2. Construct the Z array for this concatenated string.
3. Find matches where the Z value equals the pattern length.

## Time Complexity

O(n + m), where n is the length of the text and m is the length of the pattern

## Space Complexity

O(n + m) for the concatenated string and Z array

## Use Cases

- Efficient string matching
- Palindrome detection
- String compression

## Advantages

- Linear time complexity
- Can be used for multiple pattern matching

## Disadvantages

- Requires additional space for the Z array
- May be overkill for simple string matching tasks