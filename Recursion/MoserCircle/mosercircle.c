#include <stdio.h>

// Recursive function to calculate maximum regions
int maxRegions(int n)
{
  if (n == 0) // Base case
    return 1;
  return maxRegions(n - 1) + n; // Recursive case
}

int main()
{
  int n;
  printf("Enter the number of chords (non-negative integer): ");
  scanf("%d", &n);

  // Input validation
  while (n < 0)
  {
    printf("Invalid input! Number of chords cannot be negative.\n");
    printf("Enter the number of chords (non-negative integer): ");
    scanf("%d", &n);
  }

  int regions = maxRegions(n); // Calculate regions
  printf("Maximum number of regions with %d chords: %d\n", n, regions);
  return 0;
}
