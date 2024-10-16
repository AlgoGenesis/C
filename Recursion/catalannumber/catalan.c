#include <stdio.h>

unsigned long long catalan(int n)
{

  if (n == 0)
    return 1;

  unsigned long long result = 0;

  for (int i = 0; i < n; i++)
  {
    result += catalan(i) * catalan(n - 1 - i);
  }

  return result;
}

int main()
{
  int n;

  printf("Enter a value for n: ");
  scanf("%d", &n);

  if (n < 0)
  {
    printf("n must be a non-negative integer.\n");
    return 1;
  }

  printf("Catalan number C_%d is %llu\n", n, catalan(n));

  return 0;
}
