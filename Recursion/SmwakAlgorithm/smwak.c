#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_totally_monotone(int **matrix, int rows, int cols)
{
  for (int c = 1; c < cols; ++c)
  {
    for (int r = 1; r < rows; ++r)
    {
      if (matrix[r][c] < matrix[r - 1][c] && matrix[r][c - 1] > matrix[r - 1][c - 1])
      {
        return false;
      }
    }
  }
  return true;
}

int *smawk_recursive(int *rows, int rowsSize, int *cols, int colsSize, int **matrix)
{
  if (rowsSize == 0)
    return NULL;

  int *result = (int *)malloc(rowsSize * sizeof(int));
  for (int i = 0; i < rowsSize; ++i)
    result[i] = -1;

  int *reduced_cols = (int *)malloc(colsSize * sizeof(int));
  int reduced_cols_size = 0;

  for (int i = 0; i < colsSize; ++i)
  {
    int j = cols[i];
    while (reduced_cols_size > 0 && matrix[rows[reduced_cols_size - 1]][j] <= matrix[rows[reduced_cols_size - 1]][reduced_cols[reduced_cols_size - 1]])
    {
      reduced_cols_size--;
    }
    reduced_cols[reduced_cols_size++] = j;
  }

  for (int i = 0; i < rowsSize; ++i)
  {
    if (i % 2 == 0)
    {
      result[i] = reduced_cols_size > 0 ? reduced_cols[0] : -1;
      continue;
    }
    int min_col = -1;
    for (int j = 0; j < reduced_cols_size; ++j)
    {
      if (min_col == -1 || matrix[rows[i]][reduced_cols[j]] < matrix[rows[i]][min_col])
      {
        min_col = reduced_cols[j];
      }
    }
    result[i] = min_col;
  }

  free(reduced_cols);
  return result;
}

int *smawk(int **matrix, int rows, int cols)
{
  int *row_indices = (int *)malloc(rows * sizeof(int));
  int *col_indices = (int *)malloc(cols * sizeof(int));
  for (int i = 0; i < rows; ++i)
    row_indices[i] = i;
  for (int i = 0; i < cols; ++i)
    col_indices[i] = i;

  int *result = smawk_recursive(row_indices, rows, col_indices, cols, matrix);
  free(row_indices);
  free(col_indices);
  return result;
}

int main()
{
  int rows, cols;
  printf("Enter number of rows and columns for matrix : ");
  scanf("%d %d", &rows, &cols);

  int **matrix = (int **)malloc(rows * sizeof(int *));
  for (int i = 0; i < rows; ++i)
  {
    matrix[i] = (int *)malloc(cols * sizeof(int));
  }

  printf("Enter matrix elements (row by row):\n");
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      scanf("%d", &matrix[i][j]);
    }
  }

  if (!is_totally_monotone(matrix, rows, cols))
  {
    printf("The matrix is not totally monotone. SMAWK algorithm requires a totally monotone matrix.\n");
    for (int i = 0; i < rows; ++i)
    {
      free(matrix[i]);
    }
    free(matrix);
    return 1;
  }

  int *minima_indices = smawk(matrix, rows, cols);

  printf("Row-wise minimum indices is :\n");
  for (int i = 0; i < rows; ++i)
  {
    printf("Row %d: Column %d\n", i, minima_indices[i]);
  }

  free(minima_indices);
  for (int i = 0; i < rows; ++i)
  {
    free(matrix[i]);
  }
  free(matrix);
  return 0;
}
