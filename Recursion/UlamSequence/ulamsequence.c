#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000
int ulam[MAX];
int ulamCount = 0;

bool isUlam(int n)
{
  int count = 0;
  for (int i = 0; i < ulamCount; i++)
  {
    for (int j = i + 1; j < ulamCount; j++)
    {
      if (ulam[i] + ulam[j] == n)
      {
        count++;
        if (count > 1)
          return false;
      }
    }
  }
  return count == 1;
}

void generateUlam(int current)
{
  if (current > MAX)
    return;

  if (isUlam(current))
  {
    ulam[ulamCount++] = current;
  }

  generateUlam(current + 1);
}

int main()
{
  ulam[0] = 1;
  ulam[1] = 2;
  ulamCount = 2;

  generateUlam(3);

  int maxN;
  printf("Enter the maximum value for the Ulam sequence: ");
  scanf("%d", &maxN);

  printf("Ulam Sequence up to %d:\n", maxN);
  for (int i = 0; i < ulamCount && ulam[i] <= maxN; i++)
  {
    printf("%d ", ulam[i]);
  }
  printf("\n");

  return 0;
}
