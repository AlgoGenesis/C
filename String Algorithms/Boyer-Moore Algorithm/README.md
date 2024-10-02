# Boyer-Moore Algorithm

## Description

The Boyer-Moore algorithm is an efficient string searching algorithm that is the standard benchmark for practical string search literature. It preprocesses the pattern to be searched for, but not the text to be searched in.

## How it works

1. Preprocess the pattern to create two heuristics:
   - Bad Character Heuristic
   - Good Suffix Heuristic
2. Use these heuristics to skip characters in the text, reducing the number of comparisons.
3. Compare characters from right to left in the pattern.

## Time Complexity

- Best Case: O(n/m)
- Average Case: O(n)
- Worst Case: O(nm)

Where n is the length of the text and m is the length of the pattern.

## Space Complexity

O(k), where k is the size of the alphabet

## Use Cases

- Efficient string searching in large texts
- Text editors for find/replace operations
- Bioinformatics for DNA sequence matching

## Advantages

- Very fast in practice, especially for large alphabets
- Sublinear time complexity in the best and average cases

## Disadvantages

- Preprocessing step can be complex
- Not as efficient for small alphabets or short patterns