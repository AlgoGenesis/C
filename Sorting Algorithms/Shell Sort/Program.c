#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEMENT_COUNT 15
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

const char *bigONotation =
    "Shell Sort Big O Notation:\n"
    "--> Best Case: O(n log(n))\n"
    "--> Average Case: depends on gap sequence\n"
    "--> Worst Case: O(n^2)";

void displayArray(int arr[], int length)
{
    for (int i = 0; i < length; i++) {
        printf("%3d ", arr[i]);
    }
    printf("\n");
}

void swapElements(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void shellSort(int arr[], int length)
{
    for (int gap = length / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < length; i++) {
            for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap) {
                swapElements(&arr[j], &arr[j + gap]);
            }
        }
    }
}

int main()
{
    int array[ELEMENT_COUNT];
    int rangeLimit = 500;
    int arrayLength;
    clock_t startTime, endTime;
    double elapsedTime;

    srand(time(NULL));
    
    // Populate array with random values
    for (int i = 0; i < ELEMENT_COUNT; i++) {
        array[i] = rand() % rangeLimit + 1;
    }

    arrayLength = ARRAY_SIZE(array);

    // Display unsorted data
    displayArray(array, arrayLength);

    // Measure sorting time
    startTime = clock();
    shellSort(array, arrayLength);
    endTime = clock();

    elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Display sorted data
    printf("Data Sorted\n");
    displayArray(array, arrayLength);

    // Output Big O Notation and time taken
    printf("%s\n", bigONotation);
    printf("Time spent sorting: %.4g ms\n", elapsedTime * 1e3);

    return 0;
}
