# Knuth-Morris-Pratt (KMP) Algorithm

## Description

The Knuth-Morris-Pratt (KMP) algorithm is an efficient string searching algorithm that improves the naive string matching approach by avoiding unnecessary re-examinations of characters in the text. It preprocesses the pattern to create a partial match table (also known as the "prefix" table) that helps to skip characters in the text, ensuring that the search runs in linear time.

### Problem Definition

Given:
- A text string
- A pattern string

Objective:
- Find all occurrences of the pattern within the text efficiently.

### Algorithm Overview

1. **Preprocessing**:
   - Create the prefix table (or partial match table) for the pattern. This table indicates the longest proper prefix which is also a suffix for each substring of the pattern. This helps to determine the next positions to check when a mismatch occurs.

2. **Searching**:
   - Initialize two pointers: one for the text and one for the pattern.
   - Compare characters of the pattern with the text:
     - If characters match, advance both pointers.
     - If a mismatch occurs after some matches, use the prefix table to shift the pattern without re-evaluating matched characters in the text.
   - If the entire pattern matches, record the starting position of the match and shift the pattern according to the prefix table.

3. **Repeat** the searching step until the end of the text is reached.

### Time Complexity

- Preprocessing: O(m), where m is the length of the pattern.
- Searching: O(n), where n is the length of the text.
- Overall Time Complexity: O(n + m)

The KMP algorithm is efficient and performs well in practice, making it suitable for applications involving string matching, such as text editors, search engines, and DNA sequence analysis. Its linear time complexity ensures that it scales effectively even for large text inputs.
