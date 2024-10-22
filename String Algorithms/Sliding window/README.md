
### Name:  
Find the Index of the First Occurrence in a String (Sliding Window Approach)

---

### About:  
The Sliding Window Approach, also known as brute force, involves comparing the `needle` with every possible substring of the same length within the `haystack`. Although not as efficient as other algorithms like KMP or Rabin-Karp, this approach is simple and works for small strings.

---

### Labels:  
```new algorithm, gssoc-ext, hacktoberfest, level1```

---

### Assignees:  
- [x] Contributor in GSSoC-ext  
- [x] Want to work on it  

---

### Problem Definition

**Input**:  
- `haystack`: A string where we are searching for the substring.
- `needle`: The substring we want to find in `haystack`.

**Output**:  
- The index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not found.

---

### Algorithm Overview

1. **Sliding Window**:  
   Move a window of length equal to the `needle` over the `haystack`, and at each step, check if the substring in the window matches the `needle`.
   
2. **Character Comparison**:  
   Compare characters one by one for each window.

---

### Time Complexity

- **Worst Case**: O(n * m), where `n` is the length of the `haystack` and `m` is the length of the `needle`.

### Space Complexity

O(1), since no extra space other than variables for indices is required.

This brute force approach, though not as efficient as other methods, is simple to understand and implement, making it useful for small strings.