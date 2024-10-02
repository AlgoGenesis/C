### The Prefix Table

The **prefix table** is also known by several other names, including:

- **LPS Array**: Stands for **Longest Prefix Suffix** array.
- **Partial Match Table**: It indicates how many characters can be skipped during mismatches.
- **Failure Function**: It provides information about where to continue the search in the pattern after a mismatch.

The prefix table is constructed for a given pattern and indicates the longest proper prefix of the substring that is also a suffix. A proper prefix is one that is not equal to the entire string.

### Working of the Prefix Table

1. **Initialization**:
   - Create an array `lps` of the same length as the pattern initialized to zeros.
   - Use two pointers: one (`i`) to traverse the pattern and the other (`j`) to keep track of the length of the previous longest prefix suffix.

2. **Iterate through the Pattern**:
   - Start with `i = 1` and `j = 0`.
   - Compare the character at `pattern[i]` with `pattern[j]`.

3. **Match Found**:
   - If there is a match, increment `j` and set `lps[i]` to `j`.
   - Increment `i` to check the next character.

4. **Mismatch Handling**:
   - If there is a mismatch:
     - If `j` is not zero, set `j` to `lps[j - 1]` and continue comparing.
     - If `j` is zero, set `lps[i]` to zero and increment `i`.

5. **Repeat**:
   - Continue this process until the end of the pattern is reached.

### Example: Constructing the Prefix Table for the Pattern "ABABCAB"

Let's construct the prefix table for the pattern **"ABABCAB"**.

#### Step-by-Step Construction

1. **Initialization**:
   - **Pattern**: `ABABCAB`
   - **Length (m)**: `7`
   - **LPS Array**: `lps[0..m-1]`, initialized to zeros.

```plaintext
lps = [0, 0, 0, 0, 0, 0, 0]
```

2. **Iterate through the Pattern**:
   - Start with `i = 1`, `j = 0`.

| Step | i | j | pattern[i] | pattern[j] | Action                              | lps Array              |
|------|---|---|------------|------------|-------------------------------------|------------------------|
| 1    | 1 | 0 | B          | A          | No match; lps[1] = 0, increment i  | [0, 0, 0, 0, 0, 0, 0]  |
| 2    | 2 | 0 | A          | A          | Match; increment j and set lps[2]  | [0, 0, 1, 0, 0, 0, 0]  |
| 3    | 3 | 1 | B          | B          | Match; increment j and set lps[3]  | [0, 0, 1, 2, 0, 0, 0]  |
| 4    | 4 | 2 | C          | A          | No match; set j to lps[1] (0)      | [0, 0, 1, 2, 0, 0, 0]  |
| 5    | 4 | 0 | C          | A          | No match; lps[4] = 0, increment i  | [0, 0, 1, 2, 0, 0, 0]  |
| 6    | 5 | 0 | A          | A          | Match; increment j and set lps[5]  | [0, 0, 1, 2, 0, 1, 0]  |
| 7    | 6 | 1 | B          | B          | Match; increment j and set lps[6]  | [0, 0, 1, 2, 0, 1, 2]  |

### Final LPS Array

After processing all characters, the final LPS array for the pattern **"ABABCAB"** is:

```plaintext
lps = [0, 0, 1, 2, 0, 1, 2]
```

### Explanation of the LPS Array

- **lps[0] = 0**: There is no proper prefix or suffix for the first character "A".
- **lps[1] = 0**: No prefix that is also a suffix for "AB".
- **lps[2] = 1**: The prefix "A" is also a suffix for "ABA".
- **lps[3] = 2**: The prefix "AB" is also a suffix for "ABAB".
- **lps[4] = 0**: No prefix that is also a suffix for "ABABC".
- **lps[5] = 1**: The prefix "A" is also a suffix for "ABABCA".
- **lps[6] = 2**: The prefix "AB" is also a suffix for "ABABCAB".
