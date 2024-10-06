# Boyer-Moore Algorithm

## Description

The Boyer-Moore algorithm is an efficient string searching algorithm that is particularly effective for large alphabets and long patterns. It preprocesses the pattern to be searched and uses this information to skip portions of the text, resulting in a sublinear running time in many cases.

### Problem Definition

Given:
- A text string
- A pattern string

Objective:
- Find all occurrences of the pattern within the text efficiently.

### Algorithm Overview

1. **Preprocessing**:
   - Compute the bad character heuristic for the pattern.
   - (Optional) Compute the good suffix heuristic for the pattern.

2. **Searching**:
   - Align the pattern at the beginning of the text.
   - Compare characters from right to left.
   - If a mismatch occurs:
     - Use the bad character heuristic to shift the pattern.
     - (If implemented) Use the good suffix heuristic and take the maximum of the two shifts.
   - If the pattern is fully matched, record the position and shift by one.

3. **Repeat** the searching step until the end of the text is reached.

### Time Complexity

- Preprocessing: O(m + σ), where m is the length of the pattern and σ is the size of the alphabet.
- Best Case: O(n/m), where n is the length of the text.
- Worst Case: O(nm)

The algorithm performs well in practice, often outperforming other string matching algorithms, especially for larger alphabets and longer patterns.