#include <stdio.h>
#include <stdlib.h>

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// QuickSort implementation for sorting
void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to find triplets
void triplet(int n, int **arr, int input[], int *tripletCount)
{
    quickSort(input, 0, n - 1);
    *tripletCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && input[i] == input[i - 1])
            continue; // Skip duplicates for i

        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = input[i] + input[j] + input[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                // Store the triplet
                arr[*tripletCount][0] = input[i];
                arr[*tripletCount][1] = input[j];
                arr[*tripletCount][2] = input[k];
                (*tripletCount)++;

                j++;
                k--;

                // Skip duplicates for j and k
                while (j < k && input[j] == input[j - 1])
                    j++;
                while (j < k && input[k] == input[k + 1])
                    k--;
            }
        }
    }
}

int main()
{
    int input[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(input) / sizeof(input[0]);

    // Dynamically allocate memory for the result array
    int **result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        result[i] = (int *)malloc(3 * sizeof(int));
    }

    int tripletCount;
    triplet(n, result, input, &tripletCount);

    // Print results
    for (int i = 0; i < tripletCount; i++)
    {
        printf("[");
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("] ");
    }
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < n; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}
