# Deterministic Sample Matching Algorithm

## Description

The **Deterministic Sample Matching Algorithm** is a basic string matching technique that searches for a pattern within a text. The algorithm compares the pattern with every possible substring of the text to determine if the pattern exists. It is called "deterministic" because it systematically checks each position in the text without any randomization or skipping.

### Problem Definition

Given:
- A string of text `T` of length `n`.
- A pattern `P` of length `m`.

Objective:
- Find all occurrences of the pattern `P` in the text `T` and return the starting indices of the matches.

### Algorithm Overview

1. **Iterate through the text**: Starting from the first position of the text, slide the pattern over the text, one character at a time.
2. **Character Comparison**:
   - At each position, compare the characters of the pattern with the corresponding characters in the text.
   - If all characters match, record the starting index of the match.
3. **Move to the Next Position**: If a mismatch occurs, move to the next position in the text and repeat the process.
4. **Return Results**: Continue until all possible positions in the text are checked.

### Time Complexity

- **Worst-case time complexity**: \( O(n \times m) \), where:
  - \( n \) is the length of the text.
  - \( m \) is the length of the pattern.
  
In the worst case, the algorithm compares each character of the pattern with each character of the text.

### Example

Given the following text and pattern:

- **Text**: `"deterministicmatchingisfun"`
- **Pattern**: `"matching"`

The algorithm will find the pattern starting at index 13.

### Use Cases

- String searching applications.
- Pattern matching in text editors.
- Searching in DNA sequences for a specific gene.

### Limitations

- This algorithm can be slow for very large texts or long patterns due to its \( O(n \times m) \) time complexity. More efficient algorithms like the **KMP Algorithm** or **Rabin-Karp** are better suited for such cases.

### How to Run

1. Clone or download the repository containing the `Program.c` file.
2. Compile the program using a C compiler:

   ```bash
   gcc Program.c -o match
   ```

3. Run the program:

   ```bash
   ./match
   ```

4. Modify the `text[]` and `pattern[]` arrays in `Program.c` to test different strings and patterns.