#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int n)
{
    // Implementing a simple bubble sort for sorting
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void triplet(int n, int arr[][3], int input[], int *tripletCount)
{
    sort(input, n);
    *tripletCount = 0;

    for (int i = 0; i < n; i++)
    {
        // Remove duplicates
        if (i != 0 && input[i] == input[i - 1])
            continue;

        // Two-pointer technique
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
                // Skip duplicates
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

    // Assuming max possible number of triplets is n*(n-1)/2
    int result[100][3];
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

    return 0;
}
