# METHOD 1

1. First transpose the matrix.
2. For this run a loop from i=0 to n and another loop from j=i+1 to j
3. After doing this, now iterate over rows and reverse each rows.
4. After this print the entire matrix (that gets rotated).


# Time and Space Complexity :

Time-Complexity : O(n*n)

Space-Complexity : O(1)


# METHOD 2

1. First rotate the matrix about its main diagonal.
2. For this run a loop from i=0 to n and another loop from j=0 to 1, and swap (mat[i][j], mat[j][i])
3. Now, rotate the matrix about middle column.
4. For this run a loop from i=0 to n, and another loop from j=0 to n/2 and swap (mat[i][j],, mat[i][n-j-1]).
5. After this print the entire matrix (that gets rotated).


# Time and Space Complexity :

Time-Complexity : O(n*n)

Space-Complexity : O(1)