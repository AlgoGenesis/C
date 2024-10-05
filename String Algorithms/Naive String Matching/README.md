# Naive String Matching Algorithm

## Description

The **Naive String Matching Algorithm** is a straightforward method for finding all occurrences of a pattern (substring) within a given text (string). This algorithm works by checking for the presence of the pattern at each possible position in the text. It does this by comparing characters one by one, making it easy to understand and implement, but it is not the most efficient approach for larger datasets.

### Problem Definition

- **Input**:
  - A string `txt` of length `n`.
  - A pattern `pat` of length `m`.
  
- **Output**:
  - The starting indices of all occurrences of `pat` in `txt`.

### Algorithm Overview

1. **Initialization**: Start from the first character of the text.
2. **Outer Loop**: For each position in the text (from `0` to `n - m`), check if the pattern matches the substring of the text starting at that position.
3. **Inner Loop**: For each character in the pattern, compare it with the corresponding character in the text:
   - If a mismatch occurs, break out of the inner loop and move to the next starting position in the text.
   - If all characters match, record the starting index of the match.
4. **Continue Searching**: Repeat the process for the next starting position in the text.
5. **Termination**: Continue until the end of the text is reached.

### Time Complexity

- The worst-case time complexity is `O(n * m)`, where `n` is the length of the text and `m` is the length of the pattern. This can occur when every character of the text needs to be compared with every character of the pattern (e.g., when the text and pattern are similar).

### Space Complexity

- The space complexity is `O(1)` since the algorithm uses a constant amount of extra space for variables.

---

## Example

### Input
- Text: `txt = "ABABCABABABCD"`
- Pattern: `pat = "ABAB"`

### Execution Steps

1. **Initialization**: 
   - `n = 14` (length of `txt`)
   - `m = 4` (length of `pat`)

2. **Outer Loop**: Start from `i = 0` to `n - m = 10`.

3. **Comparisons**:
   - For `i = 0`: 
     - Compare `txt[0]` with `pat[0]`: Match (`A` == `A`)
     - Compare `txt[1]` with `pat[1]`: Match (`B` == `B`)
     - Compare `txt[2]` with `pat[2]`: Mismatch (`A` != `A`)
     - Result: No match found.

   - For `i = 1`: 
     - Compare `txt[1]` with `pat[0]`: Mismatch (`B` != `A`)
     - Result: No match found.

   - For `i = 2`: 
     - Compare `txt[2]` with `pat[0]`: Match (`A` == `A`)
     - Compare `txt[3]` with `pat[1]`: Match (`B` == `B`)
     - Compare `txt[4]` with `pat[2]`: Match (`A` == `A`)
     - Compare `txt[5]` with `pat[3]`: Match (`B` == `B`)
     - Result: Match found at index `2`.

   - For `i = 3`: 
     - Compare `txt[3]` with `pat[0]`: Mismatch (`B` != `A`)
     - Result: No match found.

   - For `i = 4`: 
     - Compare `txt[4]` with `pat[0]`: Match (`A` == `A`)
     - Compare `txt[5]` with `pat[1]`: Match (`B` == `B`)
     - Compare `txt[6]` with `pat[2]`: Mismatch (`A` != `A`)
     - Result: No match found.

   - For `i = 5`: 
     - Compare `txt[5]` with `pat[0]`: Mismatch (`B` != `A`)
     - Result: No match found.

   - For `i = 6`: 
     - Compare `txt[6]` with `pat[0]`: Match (`A` == `A`)
     - Compare `txt[7]` with `pat[1]`: Match (`B` == `B`)
     - Compare `txt[8]` with `pat[2]`: Match (`A` == `A`)
     - Compare `txt[9]` with `pat[3]`: Match (`B` == `B`)
     - Result: Match found at index `6`.

   - For `i = 7`: 
     - Compare `txt[7]` with `pat[0]`: Mismatch (`B` != `A`)
     - Result: No match found.

   - For `i = 8`: 
     - Compare `txt[8]` with `pat[0]`: Mismatch (`A` != `A`)
     - Result: No match found.

4. **Final Result**:
   - The pattern `ABAB` is found at indices `2` and `6` in the text `ABABCABABABCD`.

### Output
   - Pattern found at index 2 Pattern found at index 6


---

## Conclusion

The Naive String Matching Algorithm is useful for educational purposes and simple applications. Its straightforward implementation makes it easy to understand how string matching works. However, due to its inefficiency with large texts or patterns, it is often not suitable for performance-critical applications. Other algorithms, like the Rabin-Karp or Knuth-Morris-Pratt, offer improved efficiency for more complex string matching tasks.
