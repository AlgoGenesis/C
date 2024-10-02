# Rabin-Karp Algorithm

## Description

The Rabin-Karp algorithm is a string-searching algorithm that uses hashing to find any one of a set of pattern strings in a text. It's particularly effective when searching for multiple patterns simultaneously.

## How it works

1. Calculate the hash value of the pattern and the first window of text.
2. Slide the pattern over the text one by one, comparing the hash values.
3. If the hash values match, check the characters individually.
4. Use a rolling hash function to efficiently calculate the hash of the next window.

## Time Complexity

- Average and Best Case: O(n+m), where n is the length of the text and m is the length of the pattern
- Worst Case: O(nm)

## Space Complexity

O(1) if we're searching for one pattern

## Use Cases

- Multiple pattern string matching
- Plagiarism detection
- Intrusion detection in cybersecurity

## Advantages

- Efficient for multiple pattern matching
- Good average-case performance

## Disadvantages

- Worst-case time complexity is still O(nm)
- Effectiveness depends on the choice of the hash function