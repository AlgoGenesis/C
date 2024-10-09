#include <stdio.h>

void SelectionSort(int array[], int);
void swap(int *, int *);

int main()
{
	int n;
	printf("\nEnter how many numbers you want to sort : ");
	scanf("%d", &n);
	int arr[n];
	printf("\nEnter an unsorted array : ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	SelectionSort(arr, n);
	printf("\nYour sorted array is : ");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	return 0;
}

void SelectionSort(int array[], int n)
{
	int loc;
	for (int i = 0; i < n - 1; i++)
	{
		loc = i;
		for (int j = i + 1; j < n; j++)
		{
			if (array[loc] > array[j])
			{
				loc = j;
			}
		}
		swap(&array[i], &array[loc]);
	}
}
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}