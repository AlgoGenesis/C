#include <stdio.h>

#define MAX 50

void floodFill(int screen[MAX][MAX], int x, int y, int prevColor, int newColor, int row, int col)
{
  if (x < 0 || x >= row || y < 0 || y >= col)
    return;

  if (screen[x][y] != prevColor)
    return;

  screen[x][y] = newColor;

  floodFill(screen, x + 1, y, prevColor, newColor, row, col);
  floodFill(screen, x - 1, y, prevColor, newColor, row, col);
  floodFill(screen, x, y + 1, prevColor, newColor, row, col);
  floodFill(screen, x, y - 1, prevColor, newColor, row, col);
}

void printScreen(int screen[MAX][MAX], int row, int col)
{
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      printf("%d ", screen[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int screen[MAX][MAX], row, col, x, y, newColor;

  printf("Enter number of rows and columns: ");
  scanf("%d %d", &row, &col);

  printf("Enter the screen pixel values:\n");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      scanf("%d", &screen[i][j]);
    }
  }

  printf("Enter the starting point (x, y) and the new color: ");
  scanf("%d %d %d", &x, &y, &newColor);

  int prevColor = screen[x][y];

  if (prevColor != newColor)
  {
    floodFill(screen, x, y, prevColor, newColor, row, col);
  }

  printf("Updated screen after flood fill:\n");
  printScreen(screen, row, col);

  return 0;
}
