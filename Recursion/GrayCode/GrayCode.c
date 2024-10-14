#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateGrayCode(int n, char **grayCodes, int *size)
{
  if (n == 1)
  {
    grayCodes[0] = strdup("0");
    grayCodes[1] = strdup("1");
    *size = 2;
    return;
  }

  generateGrayCode(n - 1, grayCodes, size);
  int currentSize = *size;

  for (int i = 0; i < currentSize; i++)
  {
    grayCodes[currentSize + i] = strdup(grayCodes[currentSize - 1 - i]);
  }

  for (int i = 0; i < currentSize; i++)
  {
    char *temp = malloc(n + 1);
    sprintf(temp, "0%s", grayCodes[i]);
    free(grayCodes[i]);
    grayCodes[i] = temp;
  }

  for (int i = currentSize; i < 2 * currentSize; i++)
  {
    char *temp = malloc(n + 1);
    sprintf(temp, "1%s", grayCodes[i]);
    free(grayCodes[i]);
    grayCodes[i] = temp;
  }

  *size = 2 * currentSize;
}

int main()
{
  int n;
  printf("Enter the number of bits: ");
  scanf("%d", &n);

  int maxSize = 1 << n;
  char **grayCodes = malloc(maxSize * sizeof(char *));
  int size = 0;

  generateGrayCode(n, grayCodes, &size);

  printf("Gray Code for %d bits:\n", n);
  for (int i = 0; i < size; i++)
  {
    printf("%s\n", grayCodes[i]);
    free(grayCodes[i]);
  }

  free(grayCodes);
  return 0;
}
