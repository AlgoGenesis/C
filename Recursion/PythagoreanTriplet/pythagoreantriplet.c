#include <stdio.h>
#include <math.h>
void findPythagoreanTriplets(int a, int b, int n)
{
  int c;
  if (a > n)
  {
    return;
  }

  for (b = a + 1; b <= n; b++)
  {
    c = (a * a + b * b);
    int c_squared = (int)(sqrt(c));
    if (c_squared * c_squared == c && c_squared > b)
    {
      printf("Pythagorean Triplet: (%d, %d, %d)\n", a, b, c_squared);
    }
  }

  findPythagoreanTriplets(a + 1, a + 2, n);
}

int main()
{
  int n;
  printf("Enter a number (n) to find Pythagorean triplets up to n: ");
  scanf("%d", &n);

  printf("Finding Pythagorean triplets up to %d:\n", n);
  findPythagoreanTriplets(1, 2, n);

  return 0;
}
