### Detailed Explanation of Pascal's Triangle Generation

Pascal's Triangle is a mathematical concept represented as a triangular array where each row represents the coefficients of the binomial expansion. Each element in the triangle is obtained by adding the two elements directly above it in the previous row.

### How the Pascal's Triangle is Constructed

1. **Input from the User**:

   - The user specifies the number of rows `n` they want to generate for Pascal's Triangle.
   - The value of `n` determines how many levels of the triangle will be printed.

2. **Triangle Structure**:

   - The first row is always `[1]`.
   - The second row is `[1, 1]`, and every subsequent row starts and ends with `1`.
   - Each intermediate element in a row is computed by adding the two numbers directly above it from the previous row.

3. **Computation of Elements**:
   - If `i` is the current row index and `j` is the column index within that row, the value of the element at position `(i, j)` is:
     - `triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]`, where `i` is the row number, and `j` is the position in that row.
     - For `j = 0` and `j = i`, `triangle[i][j] = 1`, as the edges of each row are always `1`.

### Example Walkthrough: `n = 5`

If the user inputs `n = 5`, the program generates Pascal's Triangle with 5 rows as follows:

1. **Row 1**: `[1]`
   - There is only one element in this row.
2. **Row 2**: `[1, 1]`
   - Starts and ends with `1`.
3. **Row 3**: `[1, 2, 1]`
   - Starts with `1`.
   - `2` is obtained by adding the two `1`s from Row 2.
   - Ends with `1`.
4. **Row 4**: `[1, 3, 3, 1]`
   - Starts with `1`.
   - `3` is obtained by adding the `1` and `2` above it.
   - The next `3` is obtained by adding the `2` and `1` above it.
   - Ends with `1`.
5. **Row 5**: `[1, 4, 6, 4, 1]`
   - Starts with `1`.
   - `4` is obtained by adding `1` and `3` above it.
   - `6` is obtained by adding `3` and `3` above it.
   - The next `4` is obtained by adding `3` and `1` above it.
   - Ends with `1`.

### Full Pascal's Triangle for `n = 5`

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
