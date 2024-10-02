#include <stdio.h>
#include <math.h>

#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

int jump_search(int *arr, int x, int n)
{
	int step = floor(sqrt(n));
	int prev = 0;

	while (arr[MIN(step, n)] < x)
	{
		prev = step;
		step += floor(sqrt(n));

		if (prev >= n)
			return -1;
	}

	// linear search
	while(arr[prev] < x)
	{
		prev ++;

        	// If we reached next block or end of
        	// array, element is not present.
		if (prev == MIN(step, n))
			return -1;
	}

	if (arr[prev] == x)
		return prev;

	return -1;
}


int main()
{
	int arr[] = { 0, 1, 1, 2, 3, 4, 5, 7, 8, 13, 21, 34, 55, 89, 144, 233, 250, 310};
	int n = sizeof(arr) / sizeof(arr[0]);

	int x = 34;
	int index = jump_search(arr, 34, n);

	if (index >= 0)
		printf("Number %d is at: %d index\n", x, index);
	else
		printf("Number %d does not exist in the array\n", x);

	x = 324;
	index = jump_search(arr, x, n);

	if (index >= 0)
		printf("Number %d is at: %d index\n", x, index);
	else
		printf("Number %d does not exist in the array\n", x);
	
	return 0;
}
