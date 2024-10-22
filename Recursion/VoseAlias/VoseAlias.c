#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int *alias;
  double *prob;
  int n;
} AliasTable;

AliasTable *initAliasTable(int n)
{
  AliasTable *table = (AliasTable *)malloc(sizeof(AliasTable));
  table->alias = (int *)malloc(n * sizeof(int));
  table->prob = (double *)malloc(n * sizeof(double));
  table->n = n;
  return table;
}

void freeAliasTable(AliasTable *table)
{
  free(table->alias);
  free(table->prob);
  free(table);
}

void buildAliasTableRecursively(int *small, int *large, int *smallSize, int *largeSize, AliasTable *table, double *prob)
{
  while (*smallSize > 0 && *largeSize > 0)
  {
    int l = small[--(*smallSize)];
    int g = large[--(*largeSize)];

    table->prob[l] = prob[l] * table->n;
    table->alias[l] = g;

    prob[g] = prob[g] + prob[l] - 1.0 / table->n;

    if (prob[g] < 1.0 / table->n)
    {
      small[(*smallSize)++] = g;
    }
    else
    {
      large[(*largeSize)++] = g;
    }
  }
}

AliasTable *createAliasTable(double *prob, int n)
{
  AliasTable *table = initAliasTable(n);

  int *small = (int *)malloc(n * sizeof(int));
  int *large = (int *)malloc(n * sizeof(int));

  int smallSize = 0, largeSize = 0;

  for (int i = 0; i < n; i++)
  {
    if (prob[i] < 1.0 / n)
    {
      small[smallSize++] = i;
    }
    else
    {
      large[largeSize++] = i;
    }
  }

  buildAliasTableRecursively(small, large, &smallSize, &largeSize, table, prob);

  free(small);
  free(large);

  return table;
}

int sampleAlias(AliasTable *table)
{
  int i = rand() % table->n;
  return rand() / (double)RAND_MAX < table->prob[i] ? i : table->alias[i];
}

int main()
{
  int n;

  printf("Enter the number of probabilities: ");
  scanf("%d", &n);

  if (n <= 0)
  {
    printf("Invalid number of probabilities.\n");
    return 1;
  }

  double *prob = (double *)malloc(n * sizeof(double));

  printf("Enter the probabilities (space-separated, must sum to 1):\n");
  double sum = 0.0;
  for (int i = 0; i < n; i++)
  {
    scanf("%lf", &prob[i]);
    sum += prob[i];
  }

  if (sum < 0.999 || sum > 1.001)
  {
    printf("Error: Probabilities must sum to 1. Sum provided: %f\n", sum);
    free(prob);
    return 1;
  }

  AliasTable *aliasTable = createAliasTable(prob, n);

  printf("Sampled index: %d\n", sampleAlias(aliasTable));

  freeAliasTable(aliasTable);
  free(prob);

  return 0;
}
