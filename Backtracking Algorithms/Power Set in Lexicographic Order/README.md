### Power Set in Lexicographic Order

### Overview

This program generates the power set of a given string in lexicographic (sorted) order. The power set of a set is the collection of all its subsets, including the empty set and the set itself. The subsets are printed in lexicographic order, meaning that "ab" would appear before "ba" if "a" and "b" are characters in the input.

### Problem Definition

Given a string \( S \), the task is to generate and display all possible subsets of characters in \( S \) in lexicographic order. Each subset should appear once, and they should be sorted based on character lexicographic order.

**Input**: A string, `str`, which may contain unique characters.

**Output**: All possible subsets of `str` in lexicographic order.

### Algorithm Overview

1. **Sort the String**: First, the input string `str` is sorted to ensure that the generated subsets are in lexicographic order.
  
2. **Recursive Function (`permuteRec`)**:
   - The function `permuteRec` is designed to generate and print each subset.
   - It takes `str` (the sorted string), `n` (length of `str`), `index` (indicating the current position in `str`), and `curr` (current subset being built).
   - In each call:
     - The function prints the current subset stored in `curr`.
     - It iterates through the remaining characters in `str` (from `index + 1` to `n`), appending each character to `curr` to create a new subset.
     - After adding a character to `curr`, the function calls itself recursively to explore further subsets that include this character.
     - Once back from recursion, the added character is removed from `curr` (backtracking) to explore other possible subsets without it.
   
3. **Driver Code (`powerSet`)**:
   - The `powerSet` function initializes variables, sorts the string, and prepares an empty subset string `curr`.
   - It then calls the recursive function `permuteRec` to begin generating the subsets.

### Example

Let `str = "cab"`.

1. **Sort the String**: Sorting "cab" results in "abc".
   
2. **Subset Generation**:
   - Start with an empty subset and add elements to form new subsets while exploring all combinations:
   
   **Recursive Steps**:
   - `curr = ""`: Print `""` (empty set).
   - Add `"a"` to `curr`: Print `"a"`.
     - Add `"b"` to `"a"`: Print `"ab"`.
       - Add `"c"` to `"ab"`: Print `"abc"`.
     - Backtrack to `"a"`.
     - Add `"c"` to `"a"`: Print `"ac"`.
   - Backtrack to `""`.
   - Add `"b"` to `curr`: Print `"b"`.
     - Add `"c"` to `"b"`: Print `"bc"`.
   - Backtrack to `""`.
   - Add `"c"` to `curr`: Print `"c"`.

**Output**:
```
"" (empty subset)
a
ab
abc
ac
b
bc
c
```

This output lists all subsets of `"cab"` in lexicographic order.